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
  ${CMAKE_CURRENT_SOURCE_DIR}/../NamingService
  ${CMAKE_CURRENT_SOURCE_DIR}/../Utils
  ${CMAKE_CURRENT_SOURCE_DIR}/../Registry
  ${CMAKE_CURRENT_SOURCE_DIR}/../Notification
  ${CMAKE_CURRENT_SOURCE_DIR}/../ResourcesManager
  ${CMAKE_CURRENT_SOURCE_DIR}/../Container
  ${CMAKE_CURRENT_SOURCE_DIR}/../MPIContainer
  ${CMAKE_CURRENT_SOURCE_DIR}/../GenericObj
  ${PROJECT_BINARY_DIR}/idl
  ${MPI_CXX_INCLUDE_PATH}
  ${OMNIORB_INCLUDE_DIR}
  ${PROJECT_BINARY_DIR}/salome_adm
  ${SALOMEBOOTSTRAP_INCLUDE_DIRS}
)

ADD_DEFINITIONS(${OMNIORB_DEFINITIONS} ${MPI_DEFINITIONS})

SET(COMMON_LIBS
  ArgvKeeper
  Registry
  SalomeNotification
  SalomeResourcesManager
  SalomeNS
  OpUtil
  ${SALOMEBOOTSTRAP_SALOMELocalTrace}
  ${SALOMEBOOTSTRAP_SALOMEBasics}
  ${SALOMEBOOTSTRAP_KERNELBasics}
  SalomeContainer
  SalomeMPIContainer
  SalomeGenericObj
  SalomeIDLKernel
  ${OMNIORB_LIBRARIES}
)

ADD_LIBRARY(SalomeTestMPIComponentEngine TestMPIComponentEngine.cxx)
TARGET_LINK_LIBRARIES(SalomeTestMPIComponentEngine ${COMMON_LIBS})
INSTALL(TARGETS SalomeTestMPIComponentEngine DESTINATION ${SALOME_INSTALL_LIBS})

ADD_EXECUTABLE(TestMPIContainer TestMPIContainer.cxx)
TARGET_LINK_LIBRARIES(TestMPIContainer SalomeTestMPIComponentEngine ${COMMON_LIBS} ${MPI_CXX_LIBRARIES})
INSTALL(TARGETS TestMPIContainer DESTINATION ${SALOME_INSTALL_BINS})

FILE(GLOB COMMON_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${COMMON_HEADERS_HXX} DESTINATION ${SALOME_INSTALL_HEADERS})
