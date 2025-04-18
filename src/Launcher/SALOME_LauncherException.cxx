// Copyright (C) 2019-2025  CEA, EDF, OPEN CASCADE
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
//
// Author : Anthony GEAY (EDF R&D)

#include "SALOME_LauncherException.hxx"

SALOME_LauncherException::SALOME_LauncherException(const std::string& reason)
{
  this->assign(reason.c_str());
}

SALOME_LauncherException::SALOME_LauncherException(const char *reason)
{
  this->assign(reason);
}

void SALOME_LauncherException::assign(const char *reason)
{
  SALOME::ExceptionStruct es;
  es.type=SALOME::INTERNAL_ERROR;
  es.text=CORBA::string_dup(reason);
  es.lineNumber=0;
  (*this).details=es;
}
