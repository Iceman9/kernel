// Copyright (C) 2007-2025  CEA, EDF, OPEN CASCADE
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

//  File   : DSC_Basic.hxx
//  Author : Natalia ERMOLAYEVA
//  Module : SALOME
//
#ifndef _DSC_Basic_HXX_
#define _DSC_Basic_HXX_

#ifdef WIN32
# if defined DSC_BASIC_EXPORTS || defined SalomeDSCContainer_EXPORTS
#  define DSC_BASIC_EXPORT __declspec( dllexport )
# else
#  define DSC_BASIC_EXPORT __declspec( dllimport )
# endif
#else
# define DSC_BASIC_EXPORT
#endif

#endif

