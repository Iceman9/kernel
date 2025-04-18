# Copyright (C) 2015-2025  CEA, EDF
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
#

IF(NOT WIN32)
  SET(TEST_NAME ${COMPONENT_NAME}_KernelHelpers)
  ADD_TEST(${TEST_NAME} ${SALOME_TEST_DRIVER} ${TIMEOUT} TestKernelHelpers.py)
  SET_TESTS_PROPERTIES(${TEST_NAME} PROPERTIES
                                    LABELS "${COMPONENT_NAME}"
                                    ENVIRONMENT "LD_LIBRARY_PATH=${KERNEL_TEST_LIB}:$ENV{LD_LIBRARY_PATH}"
  #                                 TIMEOUT 500
                      )
  # /!\ DO NOT SET TIMEOUT PROPERTY IF USING ${SALOME_TEST_DRIVER}
  #     BUT PASS TIMEOUT VALUE TO THE DRIVER

ENDIF()
