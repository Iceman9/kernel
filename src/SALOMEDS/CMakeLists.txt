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

include(${SWIG_USE_FILE})

INCLUDE_DIRECTORIES(
  ${PTHREAD_INCLUDE_DIR}
  ${OMNIORB_INCLUDE_DIR}
  ${HDF5_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
  ${PYTHON_INCLUDE_DIRS}
  ${SALOMEBOOTSTRAP_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}/salome_adm
  ${CMAKE_CURRENT_SOURCE_DIR}/../HDFPersist
  ${CMAKE_CURRENT_SOURCE_DIR}/../ArgvKeeper
  ${CMAKE_CURRENT_SOURCE_DIR}/../KernelHelpers
  ${CMAKE_CURRENT_SOURCE_DIR}/../Utils
  ${CMAKE_CURRENT_SOURCE_DIR}/../DF
  ${CMAKE_CURRENT_SOURCE_DIR}/../SALOMEDSImpl
  ${CMAKE_CURRENT_SOURCE_DIR}/../NamingService
  ${CMAKE_CURRENT_SOURCE_DIR}/../GenericObj
  ${CMAKE_CURRENT_SOURCE_DIR}/../SALOMEDSClient
  ${CMAKE_CURRENT_SOURCE_DIR}/../LifeCycleCORBA
  ${CMAKE_CURRENT_SOURCE_DIR}/../TOOLSDS
  ${CMAKE_CURRENT_SOURCE_DIR}/../Container
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${PROJECT_BINARY_DIR}/idl
)

ADD_DEFINITIONS(${OMNIORB_DEFINITIONS} ${HDF5_DEFINITIONS} ${BOOST_DEFINITIONS})
IF(WIN32)
  ADD_DEFINITIONS(-DNOGDI)
ENDIF(WIN32)

SET(COMMON_LIBS
  ArgvKeeper
  TOOLSDS
  SalomeNS
  OpUtil
  ${SALOMEBOOTSTRAP_SALOMELocalTrace}
  ${SALOMEBOOTSTRAP_SALOMEBasics}
  ${SALOMEBOOTSTRAP_KERNELBasics}
  SalomeHDFPersist
  SalomeKernelHelpers
  DF
  SalomeDSImpl
  SalomeGenericObj
  SalomeLifeCycleCORBA
  SalomeIDLKernel
  SalomeDSClient
  ${HDF5_C_LIBRARIES}
)

SET(SalomeDS_SOURCES
  SALOMEDS.cxx
  SALOMEDS_Driver_i.cxx
  SALOMEDS_UseCaseBuilder_i.cxx
  SALOMEDS_UseCaseIterator_i.cxx
  SALOMEDS_ChildIterator_i.cxx
  SALOMEDS_SComponentIterator_i.cxx
  SALOMEDS_Study_i.cxx
  SALOMEDS_StudyBuilder_i.cxx
  SALOMEDS_SObject_i.cxx
  SALOMEDS_SComponent_i.cxx
  SALOMEDS_GenericAttribute_i.cxx
  SALOMEDS_AttributeComment_i.cxx
  SALOMEDS_AttributeExternalFileDef_i.cxx
  SALOMEDS_AttributeFileType_i.cxx
  SALOMEDS_AttributeIOR_i.cxx
  SALOMEDS_AttributeInteger_i.cxx
  SALOMEDS_AttributeName_i.cxx
  SALOMEDS_AttributePersistentRef_i.cxx
  SALOMEDS_AttributeReal_i.cxx
  SALOMEDS_AttributeSequenceOfReal_i.cxx
  SALOMEDS_AttributeSequenceOfInteger_i.cxx
  SALOMEDS_AttributeDrawable_i.cxx
  SALOMEDS_AttributeSelectable_i.cxx
  SALOMEDS_AttributeOpened_i.cxx
  SALOMEDS_AttributeFlags_i.cxx
  SALOMEDS_AttributeGraphic_i.cxx
  SALOMEDS_AttributeExpandable_i.cxx
  SALOMEDS_AttributeTextColor_i.cxx
  SALOMEDS_AttributeTextHighlightColor_i.cxx
  SALOMEDS_AttributePixMap_i.cxx
  SALOMEDS_AttributeTreeNode_i.cxx
  SALOMEDS_AttributeLocalID_i.cxx
  SALOMEDS_AttributeUserID_i.cxx
  SALOMEDS_AttributeTarget_i.cxx
  SALOMEDS_AttributeTableOfInteger_i.cxx
  SALOMEDS_AttributeTableOfReal_i.cxx
  SALOMEDS_AttributeTableOfString_i.cxx
  SALOMEDS_AttributeStudyProperties_i.cxx
  SALOMEDS_AttributePythonObject_i.cxx
  SALOMEDS_AttributeParameter_i.cxx
  SALOMEDS_AttributeString_i.cxx
  SALOMEDS_SObject.cxx
  SALOMEDS_SComponent.cxx
  SALOMEDS_GenericAttribute.cxx
  SALOMEDS_ChildIterator.cxx
  SALOMEDS_SComponentIterator.cxx
  SALOMEDS_UseCaseIterator.cxx
  SALOMEDS_UseCaseBuilder.cxx
  SALOMEDS_StudyBuilder.cxx
  SALOMEDS_Study.cxx
  SALOMEDS_AttributeStudyProperties.cxx
  SALOMEDS_AttributeComment.cxx
  SALOMEDS_AttributeDrawable.cxx
  SALOMEDS_AttributeExpandable.cxx
  SALOMEDS_AttributeExternalFileDef.cxx
  SALOMEDS_AttributeFileType.cxx
  SALOMEDS_AttributeFlags.cxx
  SALOMEDS_AttributeGraphic.cxx
  SALOMEDS_AttributeIOR.cxx
  SALOMEDS_AttributeInteger.cxx
  SALOMEDS_AttributeLocalID.cxx
  SALOMEDS_AttributeName.cxx
  SALOMEDS_AttributeOpened.cxx
  SALOMEDS_AttributePythonObject.cxx
  SALOMEDS_AttributeReal.cxx
  SALOMEDS_AttributeSelectable.cxx
  SALOMEDS_AttributeSequenceOfInteger.cxx
  SALOMEDS_AttributePersistentRef.cxx
  SALOMEDS_AttributePixMap.cxx
  SALOMEDS_AttributeSequenceOfReal.cxx
  SALOMEDS_AttributeTableOfInteger.cxx
  SALOMEDS_AttributeTableOfReal.cxx
  SALOMEDS_AttributeTableOfString.cxx
  SALOMEDS_AttributeTarget.cxx
  SALOMEDS_AttributeTextColor.cxx
  SALOMEDS_AttributeTextHighlightColor.cxx
  SALOMEDS_AttributeTreeNode.cxx
  SALOMEDS_AttributeUserID.cxx
  SALOMEDS_TMPFile_i.cxx
  SALOMEDS_AttributeParameter.cxx
  SALOMEDS_AttributeString.cxx
  SALOMEDS_IParameters.cxx
)


ADD_LIBRARY(SalomeDS ${SalomeDS_SOURCES})
TARGET_LINK_LIBRARIES(SalomeDS ${COMMON_LIBS})
INSTALL(TARGETS SalomeDS EXPORT ${PROJECT_NAME}TargetGroup DESTINATION ${SALOME_INSTALL_LIBS})

ADD_EXECUTABLE(SALOMEDS_Server SALOMEDS_Server.cxx)
TARGET_LINK_LIBRARIES(SALOMEDS_Server SalomeDS ${SALOMEBOOTSTRAP_SALOMEBasics} ${SALOMEBOOTSTRAP_KERNELBasics} ${COMMON_LIBS} ${OMNIORB_LIBRARIES})

ADD_EXECUTABLE(SALOMEDS_Client SALOMEDS_Client.cxx)
TARGET_LINK_LIBRARIES(SALOMEDS_Client SalomeDS ${SALOMEBOOTSTRAP_SALOMEBasics} ${SALOMEBOOTSTRAP_KERNELBasics} ${COMMON_LIBS} ${OMNIORB_LIBRARIES})

SET(KernelDS_HEADERS KernelDS.hxx KernelDS.i)
SET(KernelDS_SOURCES KernelDS.cxx ${KernelDS_HEADERS})
SET_SOURCE_FILES_PROPERTIES(KernelDS.i PROPERTIES CPLUSPLUS ON)
SET_SOURCE_FILES_PROPERTIES(KernelDS.i PROPERTIES SWIG_FLAGS "-py3")
SET_SOURCE_FILES_PROPERTIES(KernelDS_wrap.cpp PROPERTIES COMPILE_FLAGS "-DHAVE_CONFIG_H")
SET(_swig_SCRIPTS ${CMAKE_CURRENT_BINARY_DIR}/KernelDS.py )
IF(${CMAKE_VERSION} VERSION_LESS "3.8.0") 
  SWIG_ADD_MODULE(KernelDS python ${KernelDS_SOURCES})
ELSE()
  SWIG_ADD_LIBRARY(KernelDS LANGUAGE python SOURCES ${KernelDS_SOURCES})
ENDIF()
IF(${MACHINE} STREQUAL WINDOWS)
  SET_TARGET_PROPERTIES(_KernelDS PROPERTIES DEBUG_OUTPUT_NAME _KernelDS_d)
ENDIF(${MACHINE} STREQUAL WINDOWS)
SWIG_LINK_LIBRARIES(KernelDS ${PYTHON_LIBRARIES} ${PLATFORM_LIBS} SalomeDS SalomeKernelHelpers)
install(TARGETS _KernelDS DESTINATION ${SALOME_INSTALL_LIBS})
install(FILES ${KernelDS_HEADERS} DESTINATION ${SALOME_INSTALL_HEADERS})
SALOME_INSTALL_SCRIPTS("${_swig_SCRIPTS}"  ${SALOME_INSTALL_BINS} EXTRA_DPYS "${SWIG_MODULE_KernelDS_REAL_NAME}")

INSTALL(TARGETS SALOMEDS_Server SALOMEDS_Client
      EXPORT ${PROJECT_NAME}TargetGroup
      DESTINATION ${SALOME_INSTALL_BINS})

# Executable scripts to be installed
SALOME_INSTALL_SCRIPTS(SALOME_DriverPy.py ${SALOME_INSTALL_SCRIPT_PYTHON})

SET(COMMON_HEADERS_HXX
  SALOMEDS_SComponentIterator_i.hxx
  SALOMEDS_StudyBuilder_i.hxx
  SALOMEDS_UseCaseBuilder_i.hxx
  SALOMEDS_Driver_i.hxx
  SALOMEDS_Study_i.hxx
  SALOMEDS_Study.hxx
  SALOMEDS_SObject_i.hxx
  SALOMEDS_SObject.hxx
  SALOMEDS_SComponent_i.hxx
  SALOMEDS_SComponent.hxx
  SALOMEDS_GenericAttribute_i.hxx
  SALOMEDS_GenericAttribute.hxx
  SALOMEDS_IParameters.hxx
  SALOMEDS_Defines.hxx
  SALOMEDS_wrap.hxx
  SALOMEDS_Attributes_wrap.hxx
)
INSTALL(FILES ${COMMON_HEADERS_HXX} DESTINATION ${SALOME_INSTALL_HEADERS})
