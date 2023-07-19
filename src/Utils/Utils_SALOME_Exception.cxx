// Copyright (C) 2007-2023  CEA, EDF, OPEN CASCADE
//
// Copyright (C) 2003-2007  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
// CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS
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

//  SALOME Utils : general SALOME's definitions and tools
//  File   : Utils_SALOME_Exception.cxx
//  Author : Antoine YESSAYAN, EDF
//  Module : SALOME
//  $Header$
//
#include "Utils_SALOME_Exception.hxx"
#include "utilities.h"

#ifndef WIN32
extern "C"
{
#endif
#include <math.h>
#include <stdio.h>
#include <string.h>
#ifndef WIN32
}
#endif

std::string makeText(const char *text, const char *fileName, const unsigned int lineNumber)
{
  constexpr char prefix[] = "Salome Exception";
  std::ostringstream oss;
  if (fileName)
  {
    oss << prefix << " in " << fileName << "[" << lineNumber << "] : " << text;
  }
  else
  {
    oss << prefix << " : " << text;
  }
  return oss.str();
}

SALOME_Exception::SALOME_Exception(const char *text, const char *fileName, const unsigned int lineNumber) : _text(makeText(text, fileName, lineNumber))
{
}

SALOME_Exception::~SALOME_Exception() noexcept
{
}

std::ostream &operator<<(std::ostream &os, const SALOME_Exception &ex)
{
  os << ex._text;
  return os;
}

const char *SALOME_Exception::what(void) const noexcept
{
  return _text.c_str();
}
