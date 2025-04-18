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

ADD_SUBDIRECTORY(salome_tester)
ADD_SUBDIRECTORY(tests)

# ===============================================================
# Files to be installed
# ===============================================================

# These files are executable scripts
SET(SCRIPTS
  envd
  runRemote.sh
  runRemoteSSL.sh
  .bashrc
  getAppliPath.py
  update_catalogs.py
  kill_remote_containers.py
  .salome_run # this is the Python launcher (without .py extension to avoid conflicts when importing salome python package)
  salome # this is the Python wrapper (without .py extension to avoid conflicts when importing salome python package)
  salome_mesa # this is the Python wrapper using MESA (work around display issue)
  salome_common.py
  salome_starter.py
  .salome-completion.sh
)

SALOME_INSTALL_SCRIPTS("${SCRIPTS}" ${SALOME_INSTALL_SCRIPT_SCRIPTS}/appliskel)
