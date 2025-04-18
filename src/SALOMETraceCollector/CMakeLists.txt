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
  ${CMAKE_CURRENT_SOURCE_DIR}/../Utils
  ${SALOMEBOOTSTRAP_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/../NamingService
  ${CMAKE_CURRENT_SOURCE_DIR}/../Logger
  ${PROJECT_BINARY_DIR}/idl
  ${OMNIORB_INCLUDE_DIR}
  ${PTHREAD_INCLUDE_DIR}
  ${PROJECT_BINARY_DIR}/salome_adm
)

ADD_DEFINITIONS(${OMNIORB_DEFINITIONS} ${PTHREAD_DEFINITIONS})
ADD_LIBRARY(with_loggerTraceCollector SALOMETraceCollector.cxx TraceCollector_WaitForServerReadiness.cxx)

TARGET_LINK_LIBRARIES(with_loggerTraceCollector SalomeNS ArgvKeeper ${SALOMEBOOTSTRAP_SALOMELocalTrace} SalomeLoggerServer OpUtil SalomeIDLKernel ${OMNIORB_LIBRARIES} ${PTHREAD_LIBRARIES})
INSTALL(TARGETS with_loggerTraceCollector EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

FILE(GLOB COMMON_HEADERS_HXX "${CMAKE_CURRENT_SOURCE_DIR}/*.hxx")
INSTALL(FILES ${COMMON_HEADERS_HXX} DESTINATION ${SALOME_INSTALL_HEADERS})
