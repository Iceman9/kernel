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

//  File   : SALOMEDSImpl_AttributeExpandable.hxx
//  Author : Sergey RUIN
//  Module : SALOME
//
#ifndef _SALOMEDSImpl_AttributeExpandable_HeaderFile
#define _SALOMEDSImpl_AttributeExpandable_HeaderFile

#include "SALOMEDSImpl_Defines.hxx"
#include "SALOMEDSImpl_GenericAttribute.hxx"
#include "DF_Attribute.hxx"
#include "DF_Label.hxx"       
#include <string>


class SALOMEDSIMPL_EXPORT SALOMEDSImpl_AttributeExpandable :
  public SALOMEDSImpl_GenericAttribute 
{
private:
  int myValue;

public:

  virtual std::string Save() { return (myValue == 0)?(char*)"0":(char*)"1"; }
  virtual void Load(const std::string& theValue) { (theValue == "0")?myValue=0:myValue=1; } 

  static const std::string& GetID() ;
  static SALOMEDSImpl_AttributeExpandable* Set(const DF_Label& label,const int value) ;
  SALOMEDSImpl_AttributeExpandable();
  void SetExpandable(const int value); 
  int IsExpandable() const { return myValue; }
  const std::string& ID() const;
  void Restore(DF_Attribute* with) ;
  DF_Attribute* NewEmpty() const;
  void Paste(DF_Attribute* into);
  ~SALOMEDSImpl_AttributeExpandable() {}

};

#endif
