# Copyright (C) 2012-2025  CEA, EDF, OPEN CASCADE
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

# --- rules ---

IF(NOT WIN32)

  INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/test_launcher.py ${CMAKE_CURRENT_SOURCE_DIR}/TestSSLAttached.py
  ${CMAKE_CURRENT_SOURCE_DIR}/testPerfLogManager1.py ${CMAKE_CURRENT_SOURCE_DIR}/testCrashProofContainer.py DESTINATION ${KERNEL_TEST_DIR}/Launcher)

  INSTALL(FILES CTestTestfileInstall.cmake
          DESTINATION ${KERNEL_TEST_DIR}/Launcher
          RENAME CTestTestfile.cmake)
  SET(STRESS_TEST_FILES
      test_stress.sh
      launcher_use_case.py
      )
  INSTALL(PROGRAMS ${STRESS_TEST_FILES}
          DESTINATION ${KERNEL_TEST_DIR}/Launcher)
ENDIF()
