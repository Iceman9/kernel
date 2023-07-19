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

/*!
 * Check all methods of SALOMEDS_AttributeSelectable
 * Use code of SALOMEDS_AttributeSelectable.cxx
 */
void SALOMEDSTest::testAttributeSelectable()
{
  //Create Study
  _PTR(Study) study(new SALOMEDS_Study(_study));

  CPPUNIT_ASSERT(study);

  //Create Study Builder
  _PTR(StudyBuilder) studyBuilder = study->NewBuilder();

  CPPUNIT_ASSERT(studyBuilder);

  //Create a SObject with entry 0:1:1
  _PTR(SObject) so = study->CreateObjectID("0:1:1");

  CPPUNIT_ASSERT(so);

  //Create an attribute AttributeSelectable
  _PTR(AttributeSelectable) _attr = studyBuilder->FindOrCreateAttribute(so, "AttributeSelectable");

  //Check the attribute creation
  CPPUNIT_ASSERT(_attr);

  //Check method IsSelectable
  bool isSelectable = _attr->IsSelectable();

  CPPUNIT_ASSERT(isSelectable);

  //Check method SetSelectable
  _attr->SetSelectable(false);

  CPPUNIT_ASSERT(!_attr->IsSelectable());

  _attr->SetSelectable(true);

  CPPUNIT_ASSERT(_attr->IsSelectable());

  study->Clear();
}



