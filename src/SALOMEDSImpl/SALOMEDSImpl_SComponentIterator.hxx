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

//  File   : SALOMEDSImpl_SComponentIterator_i.hxx
//  Author : Sergey RUIN
//  Module : SALOME
//
#ifndef __SALOMEDSIMPL_SCOMPONENTITERATOR_H__
#define __SALOMEDSIMPL_SCOMPONENTITERATOR_H__


//SALOMEDSImpl headers
#include "SALOMEDSImpl_Defines.hxx"
#include "SALOMEDSImpl_SComponent.hxx"

#include "DF_ChildIterator.hxx"
#include "DF_Label.hxx"
#include "DF_Document.hxx"
#include <stdio.h>

class SALOMEDSIMPL_EXPORT SALOMEDSImpl_SComponentIterator
{
private:

  DF_ChildIterator        _it;
  DF_Label                _lab;

public:

  SALOMEDSImpl_SComponentIterator(const SALOMEDSImpl_SComponentIterator& theIterator) 
  {
    _it = theIterator._it;
    _lab = theIterator._lab;
  } 

  SALOMEDSImpl_SComponentIterator() {};

  SALOMEDSImpl_SComponentIterator(DF_Document* theDocument);

  virtual ~SALOMEDSImpl_SComponentIterator() {};

  virtual void Init();
  virtual bool More();
  virtual void Next();
  virtual SALOMEDSImpl_SComponent Value();  

  SALOMEDSImpl_SComponentIterator* GetPersistentCopy() const;
};
#endif
