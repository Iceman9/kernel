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

ADD_SUBDIRECTORY(config_files)

SET(DEPRECATED_FILES
  DEPRECATED/F77config.h.in
  DEPRECATED/sstream.in
  DEPRECATED/envScript.in
  DEPRECATED/depend.in
  DEPRECATED/make_commence.in
  DEPRECATED/make_conclude.in
  DEPRECATED/make_module.in
  DEPRECATED/make_omniorb.in
)

# The deprecated files are deprecated for the KERNEL but not for the
# related modules (GUI, MED, ...), for now. Some files have to be installed.
INSTALL(FILES ${DEPRECATED_FILES} DESTINATION ${SALOME_INSTALL_AMCONFIG})
