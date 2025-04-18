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

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_SOURCE_DIR}/../ArgvKeeper
  ${SALOMEBOOTSTRAP_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../NamingService
  ${CMAKE_CURRENT_SOURCE_DIR}/../Utils
  ${CMAKE_CURRENT_SOURCE_DIR}/../Registry
  ${CMAKE_CURRENT_SOURCE_DIR}/../Notification
  ${CMAKE_CURRENT_SOURCE_DIR}/../ResourcesManager
  ${CMAKE_CURRENT_SOURCE_DIR}/../Container
  ${CMAKE_CURRENT_SOURCE_DIR}/../GenericObj
  ${PROJECT_BINARY_DIR}/idl
  ${PTHREAD_INCLUDE_DIR}
  ${OMNIORB_INCLUDE_DIR}
  ${PROJECT_BINARY_DIR}/salome_adm
)

SET(SalomeTestComponentEngine_SOURCES
  SALOME_TestComponent.hxx
  SALOME_TestComponent_i.cxx
  SALOME_TestComponent_i.hxx
)

SET(COMMON_LIBS
  ${SALOMEBOOTSTRAP_SALOMEBasics}
  ${SALOMEBOOTSTRAP_KERNELBasics}
  SalomeIDLKernel
)

IF(WIN32)
  LIST (APPEND COMMON_LIBS
     ArgvKeeper
     SalomeContainer
     Registry
     SalomeNotification
     SalomeResourcesManager
     SalomeNS
     ${SALOMEBOOTSTRAP_SALOMELocalTrace}
     SalomeGenericObj
     SalomeIDLKernel
     SalomeTestComponentEngine
  )
ENDIF(WIN32)
ADD_DEFINITIONS(${OMNIORB_DEFINITIONS})

ADD_LIBRARY(SalomeTestComponentEngine ${SalomeTestComponentEngine_SOURCES})
ADD_DEPENDENCIES(SalomeTestComponentEngine SalomeIDLKernel)
TARGET_LINK_LIBRARIES(SalomeTestComponentEngine ${COMMON_LIBS})

INSTALL(TARGETS SalomeTestComponentEngine EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

ADD_EXECUTABLE(TestLogger TestLogger.cxx)
TARGET_LINK_LIBRARIES(TestLogger ${SALOMEBOOTSTRAP_SALOMELocalTrace} ${COMMON_LIBS} ${OMNIORB_LIBRARIES})

ADD_EXECUTABLE(TestContainer TestContainer.cxx)
TARGET_LINK_LIBRARIES(TestContainer SalomeContainer ${COMMON_LIBS} ${OMNIORB_LIBRARIES})

INSTALL(TARGETS TestLogger TestContainer EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_BINS})

# Executable scripts to be installed
SET(SCRIPTS
  SALOME_TestComponentPy.py
  TestComponentPy.py
  TestLogger.py
)
SALOME_INSTALL_SCRIPTS("${SCRIPTS}" ${SALOME_INSTALL_SCRIPT_PYTHON})
