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
  ${PTHREAD_INCLUDE_DIR}
  ${OMNIORB_INCLUDE_DIR}
  ${PROJECT_BINARY_DIR}/salome_adm
  ${CMAKE_CURRENT_SOURCE_DIR}/../ArgvKeeper
  ${CMAKE_CURRENT_SOURCE_DIR}/../NamingService
  ${CMAKE_CURRENT_SOURCE_DIR}/../Utils
  ${PROJECT_BINARY_DIR}/idl
  ${SALOMEBOOTSTRAP_INCLUDE_DIRS}
)

ADD_LIBRARY(Registry RegistryConnexion.cxx RegistryService.cxx)
ADD_DEFINITIONS(${OMNIORB_DEFINITIONS})
TARGET_LINK_LIBRARIES(Registry SalomeNS OpUtil ${SALOMEBOOTSTRAP_SALOMELocalTrace} ${SALOMEBOOTSTRAP_SALOMEBasics} ${SALOMEBOOTSTRAP_KERNELBasics} ${SALOMEBOOTSTRAP_SALOMEException} SalomeIDLKernel ${PLATFORM_LIBS} ${CMAKE_DL_LIBS})
INSTALL(TARGETS Registry EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

SET(SALOME_Registry_Server_LIBS
 ArgvKeeper
 SalomeIDLKernel
 Registry
 SalomeNS
 OpUtil
 ${SALOMEBOOTSTRAP_SALOMELocalTrace}
 ${SALOMEBOOTSTRAP_SALOMEBasics}
 ${SALOMEBOOTSTRAP_KERNELBasics}
 ${PLATFORM_LIBS}
 ${PTHREAD_LIBRARIES}
)

ADD_EXECUTABLE(SALOME_Registry_Server SALOME_Registry_Server.cxx)
TARGET_LINK_LIBRARIES(SALOME_Registry_Server ${SALOME_Registry_Server_LIBS})
INSTALL(TARGETS SALOME_Registry_Server EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_BINS})

FILE(GLOB COMMON_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${COMMON_HEADERS_HXX} DESTINATION ${SALOME_INSTALL_HEADERS})
