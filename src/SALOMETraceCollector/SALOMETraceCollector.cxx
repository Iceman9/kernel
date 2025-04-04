// Copyright (C) 2007-2025  CEA, EDF, OPEN CASCADE
//
// Copyright (C) 2003-2007  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
// CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//

//  File   : LocalTraceCollector.cxx
//  Author : Paul RASCLE (EDF)
//  Module : KERNEL
//  $Header$
//
#include <SALOMEconfig.h>

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <omniORB4/CORBA.h>

#include "Utils_SALOME_Exception.hxx"
#include "SALOMETraceCollector.hxx"
#include "TraceCollector_WaitForServerReadiness.hxx"
#include <SALOMEconfig.h>
#include CORBA_CLIENT_HEADER(Logger)

// ============================================================================
/*!
 *  This class is for use with CORBA, inside SALOME.
 *  Type of trace (and corresponding class) is chosen in LocalTraceBufferPool.
 *
 *  Guarantees a unique object instance of the class (singleton thread safe)
 *  a separate thread for loop to print traces is launched.
 */
// ============================================================================

BaseTraceCollector* SALOMETraceCollector::instance()
{
  if (_singleton == 0) // no need of lock when singleton already exists
    {
      pthread_mutex_lock(&_singletonMutex);    // acquire lock to be alone
      if (_singleton == 0)                     // another thread may have got
        {                                      // the lock after the first test
          BaseTraceCollector* myInstance = new SALOMETraceCollector();

          sem_init(&_sem,0,0); // to wait until run thread is initialized
          pthread_t traceThread;
          int bid = 0;
          pthread_create(&traceThread, NULL,
                                   SALOMETraceCollector::run, &bid);
          sem_wait(&_sem);
          _singleton = myInstance; // _singleton known only when init done
        }
      pthread_mutex_unlock(&_singletonMutex); // release lock
    }
  return _singleton;
}

// ============================================================================
/*!
 *  In a separate thread, loop to print traces.
 *  Mutex guarantees initialisation on instance method is done and only one run
 *  allowed (double check ...)
 *  Loop until there is no more buffer to print,
 *  and no ask for end from destructor.
 *  Get a buffer. If type = ABORT then exit application with message.
 */
// ============================================================================

void* SALOMETraceCollector::run(void* /*bid*/)
{
  _threadId = new pthread_t;
  *_threadId = pthread_self();
  sem_post(&_sem); // unlock instance

  LocalTraceBufferPool* myTraceBuffer = LocalTraceBufferPool::instance();
  LocalTrace_TraceInfo myTrace;

  SALOME_Logger::Logger_var m_pInterfaceLogger;
  CORBA::Object_var obj;

  obj = TraceCollector_WaitForServerReadiness("Logger");
  if (!CORBA::is_nil(obj))
    m_pInterfaceLogger = SALOME_Logger::Logger::_narrow(obj);
  if (CORBA::is_nil(m_pInterfaceLogger))
    {
      std::cerr << "Logger server not found ! Abort" << std::endl;
      std::cerr << std::flush ; 
      exit(1);
    } 
  else
    {
      CORBA::String_var LogMsg =
        CORBA::string_dup("\n---Init logger trace---\n");
      m_pInterfaceLogger->putMessage(LogMsg);
      DEVTRACE("Logger server found");
    }

  // --- Loop until there is no more buffer to print,
  //     and no ask for end from destructor.

  while ((!_threadToClose) || myTraceBuffer->toCollect() )
    {
      if (_threadToClose)
        {
          DEVTRACE("SALOMETraceCollector _threadToClose");
          //break;
        }

      myTraceBuffer->retrieve(myTrace);
      {
        if (myTrace.traceType == ABORT_MESS)
          {
            std::ostringstream abortMessage;
            abortMessage << "INTERRUPTION from thread : " << myTrace.trace;
            CORBA::String_var LogMsg =
              CORBA::string_dup(abortMessage.str().c_str());
            m_pInterfaceLogger->putMessage(LogMsg);
            exit(1);
          }
        else
          {
            std::ostringstream aMessage;
            aMessage << " " << myTrace.trace;
            CORBA::String_var LogMsg =
              CORBA::string_dup(aMessage.str().c_str());
            m_pInterfaceLogger->putMessage(LogMsg);
          }
      }
    }
  pthread_exit(NULL);
  return NULL;
}

// ============================================================================
/*!
 *  Destructor: wait until printing thread ends (SALOMETraceCollector::run)
 */
// ============================================================================

SALOMETraceCollector:: ~SALOMETraceCollector()
{
  pthread_mutex_lock(&_singletonMutex); // acquire lock to be alone
  if (_singleton)
    {
      DEVTRACE("SALOMETraceCollector:: ~SALOMETraceCollector()");
      LocalTraceBufferPool* myTraceBuffer = LocalTraceBufferPool::instance();
      _threadToClose = 1;
      myTraceBuffer->insert(NORMAL_MESS,"end of trace\n"); // to wake up thread
      if (_threadId)
        {
          int ret = pthread_join(*_threadId, NULL);
          if (ret) { std::cerr << "error close SALOMETraceCollector : "<< ret << std::endl; }
          else { DEVTRACE("SALOMETraceCollector destruction OK") };
          delete _threadId;
          _threadId = 0;
          _threadToClose = 0;
        }
      _singleton = 0;
    }
  pthread_mutex_unlock(&_singletonMutex); // release lock
}

// ============================================================================
/*!
 * Constructor: no need of LocalTraceBufferPool object initialization here,
 * thread safe singleton used in LocalTraceBufferPool::instance()
 */
// ============================================================================

SALOMETraceCollector::SALOMETraceCollector()
{
  _threadId=0;
  _threadToClose = 0;
}

// ============================================================================
/*!
 * 
 */
// ============================================================================

#include "KernelBasis.hxx"
#include "SALOME_Logger_Server.hxx"
#include "SALOME_Fake_NamingService.hxx"

#include <memory>

extern "C"
{
 SALOMETRACECOLLECTOR_EXPORT
  BaseTraceCollector *SingletonInstance(void)
  {
    if(getSSLMode())
    {
      SALOME_Logger::Logger_var logger = KERNEL::getLoggerServantSA();
      std::unique_ptr<SALOME_Fake_NamingService> ns(new SALOME_Fake_NamingService);
      ns->Register(logger,"/Logger");
    }
    BaseTraceCollector *instance = SALOMETraceCollector::instance();
    return instance;
  }
}
