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

//  File   : SALOMEDS_AttributeTableOfReal_i.hxx
//  Author : Michael Ponikarov
//  Module : SALOME
//
#ifndef SALOMEDS_AttributeTableOfReal_i_HeaderFile
#define SALOMEDS_AttributeTableOfReal_i_HeaderFile

// IDL headers
#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(SALOMEDS_Attributes)

#include "SALOMEDS_GenericAttribute_i.hxx"
#include "SALOMEDSImpl_AttributeTableOfReal.hxx"

class SALOMEDS_AttributeTableOfReal_i : public virtual POA_SALOMEDS::AttributeTableOfReal,
					public virtual SALOMEDS_GenericAttribute_i
{
public:
  SALOMEDS_AttributeTableOfReal_i(SALOMEDSImpl_AttributeTableOfReal* theAttr, CORBA::ORB_ptr orb) 
    : SALOMEDS_GenericAttribute_i(theAttr, orb) {}; 
  
  ~SALOMEDS_AttributeTableOfReal_i() {};
  
  virtual void SetTitle(const char* theTitle);
  virtual char* GetTitle();
  virtual void SetRowTitle(CORBA::Long theIndex, const char* theTitle);
  virtual char* GetRowTitle(CORBA::Long theIndex);
  virtual void SetRowTitles(const SALOMEDS::StringSeq& theTitles);
  virtual SALOMEDS::StringSeq* GetRowTitles();
  virtual void SetColumnTitle(CORBA::Long theIndex, const char* theTitle);
  virtual char* GetColumnTitle(CORBA::Long theIndex);
  virtual void SetColumnTitles(const SALOMEDS::StringSeq& theTitles);
  virtual SALOMEDS::StringSeq* GetColumnTitles();

  virtual void SetRowUnit(CORBA::Long theIndex, const char* theUnit);
  virtual char* GetRowUnit(CORBA::Long theIndex);
  virtual void SetRowUnits(const SALOMEDS::StringSeq& theUnits);
  virtual SALOMEDS::StringSeq* GetRowUnits();

  virtual CORBA::Long GetNbRows();
  virtual CORBA::Long GetNbColumns();
  virtual void AddRow(const SALOMEDS::DoubleSeq& theData);
  virtual void SetRow(CORBA::Long theRow, const SALOMEDS::DoubleSeq& theData);
  virtual SALOMEDS::DoubleSeq* GetRow(CORBA::Long theRow);
  virtual void AddColumn(const SALOMEDS::DoubleSeq& theData);
  virtual void SetColumn(CORBA::Long theColumn, const SALOMEDS::DoubleSeq& theData);
  virtual SALOMEDS::DoubleSeq* GetColumn(CORBA::Long theColumn);
  virtual void PutValue(CORBA::Double theValue, CORBA::Long theRow, CORBA::Long theColumn);
  virtual CORBA::Boolean HasValue(CORBA::Long theRow, CORBA::Long theColumn);
  virtual CORBA::Double GetValue(CORBA::Long theRow, CORBA::Long theColumn);
  virtual void RemoveValue(CORBA::Long theRow, CORBA::Long theColumn);

  virtual SALOMEDS::LongSeq* GetRowSetIndices(CORBA::Long theRow);
  virtual void SetNbColumns(CORBA::Long theNbColumns);

  virtual SALOMEDS::LongSeq* SortRow(CORBA::Long theRow, SALOMEDS::AttributeTable::SortOrder sortOrder, 
                                     SALOMEDS::AttributeTable::SortPolicy sortPolicy);
  virtual SALOMEDS::LongSeq* SortColumn(CORBA::Long theColumn, SALOMEDS::AttributeTable::SortOrder sortOrder, 
                                        SALOMEDS::AttributeTable::SortPolicy sortPolicy);
  virtual SALOMEDS::LongSeq* SortByRow(CORBA::Long theRow, SALOMEDS::AttributeTable::SortOrder sortOrder, 
                                       SALOMEDS::AttributeTable::SortPolicy sortPolicy);
  virtual SALOMEDS::LongSeq* SortByColumn(CORBA::Long theColumn, SALOMEDS::AttributeTable::SortOrder sortOrder, 
                                          SALOMEDS::AttributeTable::SortPolicy sortPolicy);

  virtual void SwapCells(CORBA::Long theRow1, CORBA::Long theColumn1,
			 CORBA::Long theRow2, CORBA::Long theColumn2);
  virtual void SwapRows(CORBA::Long theRow1, CORBA::Long theRow2);
  virtual void SwapColumns(CORBA::Long theColumn1, CORBA::Long theColumn2);

  virtual bool ReadFromFile(const SALOMEDS::TMPFile& theStream);
  virtual SALOMEDS::TMPFile* SaveToFile();

};

#endif
