#!/bin/sh
# Copyright (C) 2007-2025  CEA, EDF, OPEN CASCADE
#
# Copyright (C) 2003-2007  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
# CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
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

#  File   : test3.sh
#  Module : SALOME
#
echo   "test3:

        remplacement dans un catalogue existant d'un composant existant
        (meme idl)
        "

\rm -f my_catalog.xml*


echo  "
--> creation d'un nouveau catalogue avec un composant
"

sh ${ROOT_BUILDDIR}/bin/runIDLparser -p ${SRCDIR} \
    -I${ROOT_SRCDIR}/idl \
    -Wbcatalog=my_catalog.xml \
    ${SRCDIR}/tests/AddComponent.idl


echo  "
--> remplacement du composant dans le catalogue (meme idl)
"

sh ${ROOT_BUILDDIR}/bin/runIDLparser -p ${SRCDIR} \
    -I${ROOT_SRCDIR}/idl \
    -Wbcatalog=my_catalog.xml \
    ${SRCDIR}/tests/AddComponent.idl
