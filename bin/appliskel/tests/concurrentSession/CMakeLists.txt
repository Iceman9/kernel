# Copyright (C) 2013-2025  CEA, EDF, OPEN CASCADE
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

FILE(GLOB py_scripts "${CMAKE_CURRENT_SOURCE_DIR}/*.py")
FILE(GLOB sh_scripts "${CMAKE_CURRENT_SOURCE_DIR}/*.sh")

LIST(APPEND scripts ${py_scripts} ${sh_scripts})

# Application tests
INSTALL(FILES CTestTestfileInstall.cmake
        DESTINATION ${KERNEL_TEST_DIR}/concurrentSession
        RENAME CTestTestfile.cmake)

INSTALL(PROGRAMS ${scripts}
        DESTINATION ${KERNEL_TEST_DIR}/concurrentSession)
