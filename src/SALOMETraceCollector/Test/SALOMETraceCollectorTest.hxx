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

#ifndef _SALOMETRACECOLLECTORTTEST_HXX_
#define _SALOMETRACECOLLECTORTTEST_HXX_

#include <cppunit/extensions/HelperMacros.h>

#ifdef WIN32
# if defined SALOMETRACECOLLECTORTEST_EXPORTS || defined SALOMETraceCollectorTest_EXPORTS
#  define SALOMETRACECOLLECTORTEST_EXPORT __declspec( dllexport )
# else
#  define SALOMETRACECOLLECTORTEST_EXPORT __declspec( dllimport )
# endif
#else
# define SALOMETRACECOLLECTORTEST_EXPORT
#endif

class SALOMETRACECOLLECTORTEST_EXPORT SALOMETraceCollectorTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( SALOMETraceCollectorTest );
  CPPUNIT_TEST( testLoadBufferPoolCORBA );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testLoadBufferPoolCORBA();
};

#endif
