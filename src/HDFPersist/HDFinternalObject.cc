//  SALOME HDFPersist : implementation of HDF persitent ( save/ restore )
//
//  Copyright (C) 2003  OPEN CASCADE, EADS/CCR, LIP6, CEA/DEN,
//  CEDRAT, EDF R&D, LEG, PRINCIPIA R&D, BUREAU VERITAS 
// 
//  This library is free software; you can redistribute it and/or 
//  modify it under the terms of the GNU Lesser General Public 
//  License as published by the Free Software Foundation; either 
//  version 2.1 of the License. 
// 
//  This library is distributed in the hope that it will be useful, 
//  but WITHOUT ANY WARRANTY; without even the implied warranty of 
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU 
//  Lesser General Public License for more details. 
// 
//  You should have received a copy of the GNU Lesser General Public 
//  License along with this library; if not, write to the Free Software 
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA 
// 
//  See http://www.opencascade.org/SALOME/ or email : webmaster.salome@opencascade.org 
//
//
//
//  File   : HDFinternalObject.cc
//  Module : SALOME

using namespace std;
extern "C"
{
#include "hdfi.h"
}
#include "HDFinternalObject.hxx"

HDFinternalObject::HDFinternalObject(char *name)
  : HDFobject(name)
{
  _previousbrother = NULL;
  _nextbrother = NULL;
}

HDFinternalObject *HDFinternalObject::GetPreviousBrother()
{
  return _previousbrother;
}
 
HDFinternalObject *HDFinternalObject::GetNextBrother()
{
  return _nextbrother;
}
  
void HDFinternalObject::SetPreviousBrother(HDFinternalObject *previous)
{
  _previousbrother = previous;
}
  
void HDFinternalObject::SetNextBrother(HDFinternalObject *next)
{
  _nextbrother = next;
}

