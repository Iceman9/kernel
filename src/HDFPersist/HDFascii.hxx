// Copyright (C) 2007-2025  CEA, EDF, OPEN CASCADE
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

//  File      : HDFascii.hxx
//  Created   : Mon Jun 10 16:24:50 2003
//  Author    : Sergey RUIN
//  Project   : SALOME
//  Module    : HDFPersist
//
#ifndef __HDFascii_H__
#define __HDFascii_H__

#include "HDFexport.hxx"


class HDFPERSIST_EXPORT HDFascii                                
{
public:
 
  static char* ConvertFromHDFToASCII(const char* thePath, 
                                     bool isReplaced = true, 
                                     const char* theExtension = NULL);
                                     
  static char* ConvertFromASCIIToHDF(const char* thePath, 
                                     bool isReplaced = false);
  
  static bool isASCII(const char* thePath);
};
#endif
