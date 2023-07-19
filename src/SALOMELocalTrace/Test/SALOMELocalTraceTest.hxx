// Copyright (C) 2007-2023  CEA, EDF, OPEN CASCADE
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

#ifndef _SALOMELOCALTRACETEST_HXX_
#define _SALOMELOCALTRACETEST_HXX_

#include <cppunit/extensions/HelperMacros.h>
#include <string>

#ifdef WIN32
# if defined SALOMELOCALTRACETEST_EXPORTS || defined SALOMELocalTraceTest_EXPORTS
#  define SALOMELOCALTRACETEST_EXPORT __declspec( dllexport )
# else
#  define SALOMELOCALTRACETEST_EXPORT __declspec( dllimport )
# endif
#else
# define SALOMELOCALTRACETEST_EXPORT
#endif

class SALOMELOCALTRACETEST_EXPORT SALOMELocalTraceTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( SALOMELocalTraceTest );
  CPPUNIT_TEST( testSingletonBufferPool );
  CPPUNIT_TEST( testLoadBufferPoolLocal );
  CPPUNIT_TEST( testLoadBufferPoolFile );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testSingletonBufferPool();
  void testLoadBufferPoolLocal();
  void testLoadBufferPoolFile();

 private:
  std::string _getTraceFileName();
};

#endif
