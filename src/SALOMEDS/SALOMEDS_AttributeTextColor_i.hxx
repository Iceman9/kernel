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

//  File   : SALOMEDS_AttributeTextColor_i.hxx
//  Author : Sergey RUIN
//  Module : SALOME
//  $Header$
//
#ifndef SALOMEDS_AttributeTextColor_i_HeaderFile
#define SALOMEDS_AttributeTextColor_i_HeaderFile

// IDL headers
#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(SALOMEDS_Attributes)

#include "SALOMEDS_GenericAttribute_i.hxx"
#include "SALOMEDSImpl_AttributeTextColor.hxx"

class SALOMEDS_AttributeTextColor_i: public virtual POA_SALOMEDS::AttributeTextColor,
                                     public virtual SALOMEDS_GenericAttribute_i 
{
public:
  
  SALOMEDS_AttributeTextColor_i(SALOMEDSImpl_AttributeTextColor* theAttr, CORBA::ORB_ptr orb) 
    :SALOMEDS_GenericAttribute_i(theAttr, orb) {}; 

  ~SALOMEDS_AttributeTextColor_i() {};

  SALOMEDS::Color TextColor();
  void SetTextColor(const SALOMEDS::Color& value);

};


#endif
