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

//  File   : SALOMEDSClient_AttributeTableOfReal.hxx
//  Author : Michael Ponikarov
//  Module : SALOME
//
#ifndef SALOMEDSClient_AttributeTableOfReal_HeaderFile
#define SALOMEDSClient_AttributeTableOfReal_HeaderFile

#include <vector>
#include <string>
#include "SALOMEDSClient_definitions.hxx" 
#include "SALOMEDSClient_AttributeTable.hxx" 

class SALOMEDSClient_AttributeTableOfReal: public SALOMEDSClient_AttributeTable
{
public:
  virtual void AddRow(const std::vector<double>& theData) = 0;
  virtual void SetRow(int theRow, const std::vector<double>& theData) = 0;
  virtual std::vector<double> GetRow(int theRow) = 0; 
  virtual void AddColumn(const std::vector<double>& theData) = 0;
  virtual void SetColumn(int theColumn, const std::vector<double>& theData) = 0;
  virtual std::vector<double> GetColumn(int theColumn) = 0;
  virtual void PutValue(double theValue, int theRow, int theColumn) = 0;
  virtual double GetValue(int theRow, int theColumn) = 0;
};

#endif // SALOMEDSClient_AttributeTableOfReal_HeaderFile
