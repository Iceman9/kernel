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

//  File   : SALOMEDS_AttributeFlags.hxx
//  Author : Sergey RUIN
//  Module : SALOME
//
#ifndef SALOMEDS_AttributeFlags_HeaderFile
#define SALOMEDS_AttributeFlags_HeaderFile

#include "SALOMEDSClient_AttributeFlags.hxx"
#include "SALOMEDS_GenericAttribute.hxx"
#include "SALOMEDSImpl_AttributeFlags.hxx"

// IDL headers
#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(SALOMEDS)
#include CORBA_SERVER_HEADER(SALOMEDS_Attributes)

class SALOMEDS_AttributeFlags: public SALOMEDS_GenericAttribute, public SALOMEDSClient_AttributeFlags
{
public:  
  SALOMEDS_AttributeFlags(SALOMEDSImpl_AttributeFlags* theAttr);
  SALOMEDS_AttributeFlags(SALOMEDS::AttributeFlags_ptr theAttr);
  ~SALOMEDS_AttributeFlags();

  virtual int   GetFlags();
  virtual void  SetFlags(int theFlags);

  virtual bool  Get(int theFlag);
  virtual void  Set(int theFlag, bool theValue);
};

#endif
