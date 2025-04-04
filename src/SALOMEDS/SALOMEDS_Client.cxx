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

//  SALOME SALOMEDS : data structure of SALOME and sources of Salome data server 
//  File   : SALOMEDS_Client.cxx
//  Author : Yves FRICAUD
//  Module : SALOME
//  $Header$
//
#include <SALOMEconfig.h>
#include CORBA_SERVER_HEADER(SALOMEDS)
#include "SALOMEDS_AttributeName_i.hxx"
#include "SALOME_KernelServices.hxx"
#include "ArgvKeeper.hxx"
#include "Basics_Utils.hxx"
#include "OpUtil.hxx"
#include "utilities.h"
#include "HDFOI.hxx"

//============================================================================
/*! Function :
 *  Purpose  : 
 */
//============================================================================
static void DumpComponent(SALOMEDS::SObject_ptr SO, int offset) {
  SALOMEDS::SObject_var RefSO;
  SALOMEDS::ChildIterator_var it = KERNEL::getStudyServant()->NewChildIterator(SO);
  for (; it->More();it->Next()){
    SALOMEDS::SObject_var CSO= it->Value();
    SALOMEDS::GenericAttribute_var anAttr;
    if (CSO->FindAttribute(anAttr,"AttributeName")) 
    {
      SALOMEDS::AttributeName_var Name = SALOMEDS::AttributeName::_narrow(anAttr);
      CORBA::String_var Val = Name->Value();
      for (int i = 1; i <= offset ; i++) 
        MESSAGE("--");
      MESSAGE(">"<<CSO->GetID()<<Val);
    }
    if (CSO->ReferencedObject(RefSO)) {
      for (int i = 1; i <= offset ; i++) 
        MESSAGE(" ");
      MESSAGE("*Reference"<<RefSO->GetID());
    }
    DumpComponent(CSO,offset+2);
  }
}

//============================================================================
/*! Function :
 *  Purpose  : 
 */
//============================================================================
static void DumpStudy() {
  MESSAGE("Explore Study and Write name of each object if it exists");
  
  char* name;
  SALOME_UNUSED(name); // unused in release mode
  SALOMEDS::SComponentIterator_var itcomp = KERNEL::getStudyServant()->NewComponentIterator();
  int offset = 1;
  for (; itcomp->More(); itcomp->Next()) {
    SALOMEDS::SComponent_var SC = itcomp->Value();
    name = SC->ComponentDataType();
    MESSAGE("-> ComponentDataType is "<<name);  
    DumpComponent(SC,offset);
  }
}

//============================================================================
/*! Function :
 *  Purpose  : 
 */
//============================================================================
static void Test()
{
  try {
  char* name;
  SALOME_UNUSED(name); // unused in release mode

  SALOMEDS::Study_var myStudy = KERNEL::getStudyServant();

  MESSAGE("Create Builder ");
  SALOMEDS::StudyBuilder_var StudyBuild = myStudy->NewBuilder();

  // Create new components
  SALOMEDS::GenericAttribute_var anAttr;
  SALOMEDS::AttributeName_var Name;
  SALOMEDS::AttributeComment_var Comment;
  SALOMEDS::AttributePersistentRef_var PRef;

  // GEOM
  MESSAGE("Add Component GEOM"); 
  SALOMEDS::SComponent_var Geom = StudyBuild->NewComponent("GEOM");
  MESSAGE("Add attribute name GEOM to component Geom");
  anAttr = StudyBuild->FindOrCreateAttribute(Geom, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("Geometry");

  // MESH
  MESSAGE("Add Component MESH");
  SALOMEDS::SComponent_var Mesh = StudyBuild->NewComponent("MESH");
  anAttr = StudyBuild->FindOrCreateAttribute(Mesh, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("Mesh");

  //Create objects

  //Value
  //box
  MESSAGE("Add Object  box under GEOM");
  SALOMEDS::SObject_var box = StudyBuild->NewObject(Geom);

  MESSAGE("Add Attribute Name in object box");
  anAttr = StudyBuild->FindOrCreateAttribute(box, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("box_0");

  MESSAGE("Add Attribute Comment in object box");
  anAttr = StudyBuild->FindOrCreateAttribute(box, "AttributeComment");
  Comment = SALOMEDS::AttributeComment::_narrow(anAttr);
  Comment->SetValue("this is a box");

  //mesh_box
  MESSAGE("Add Object  mesh_box under MESH");
  SALOMEDS::SObject_var mesh_box = StudyBuild->NewObject(Mesh);

  MESSAGE("Add Attribute Name in object mesh_box");
  anAttr = StudyBuild->FindOrCreateAttribute(mesh_box, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("mesh_box_0");

  // Test attribute delete
  //MESSAGE("Delete Attribute Name in object mesh_box");
  //StudyBuild->RemoveAttribute (mesh_box,SALOMEDS::Name);

  //mesh_box_face
  MESSAGE("Add Object mesh_box_face under mesh_box");
  SALOMEDS::SObject_var mesh_box_face = StudyBuild->NewObject(mesh_box);

  MESSAGE("Add Attribute Name in object mesh_box_face");
  anAttr = StudyBuild->FindOrCreateAttribute(mesh_box_face, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("mesh_box_face_0");

  MESSAGE("Add Reference mesh_box_face to box");
  StudyBuild->Addreference (mesh_box_face,box);

  //cylinder
  MESSAGE("Add Object  cylinder under GEOM");
  SALOMEDS::SObject_var cylinder = StudyBuild->NewObject(Geom);

  MESSAGE("Add Attribute Name in object cylinder");
  anAttr = StudyBuild->FindOrCreateAttribute(cylinder, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("cylinder_0");

  MESSAGE("Add Attribute Persistent Reference in object cylinder");
  anAttr = StudyBuild->FindOrCreateAttribute(cylinder, "AttributePersistentRef");
  PRef = SALOMEDS::AttributePersistentRef::_narrow(anAttr);
  PRef->SetValue("/HDFROOT/GEOM/cylinder");

  // Test Undo
  MESSAGE("Test Undo");

  StudyBuild->UndoLimit(3);
  StudyBuild->NewCommand();
  MESSAGE("Add Object  mesh_cylinder under MESH");
  SALOMEDS::SObject_var mesh_cylinder = StudyBuild->NewObject(Mesh);
  MESSAGE("Add Attribute Name in object mesh_cylinder");
  anAttr = StudyBuild->FindOrCreateAttribute(mesh_cylinder, "AttributeName");
  Name = SALOMEDS::AttributeName::_narrow(anAttr);
  Name->SetValue("mesh_cylinder_0");
  StudyBuild->CommitCommand();

  DumpStudy();

  StudyBuild->Undo();
  // Study should have no trace of object mesh_cylinder
  DumpStudy();
  
  // Save as
  myStudy->SaveAs(Kernel_Utils::decode("/home/edeville/Study1.hdf"), false, false);

  // Get Persistent Reference of the study test
  name = myStudy->GetPersistentReference();
  MESSAGE("Persitent Reference of the study " << name);

  // FindComponent Test
  SALOMEDS::SComponent_var compo = myStudy->FindComponent("GEOM");
  // Get ComponentDataType test
  MESSAGE("Find ComponentDataType of compo");
  name = compo->ComponentDataType();
  MESSAGE("-> ComponentDataType is "<<name);

  // FindComponentID Test
  SALOMEDS::SComponent_var compo1 = myStudy->FindComponentID("0:1:2");
  // Get ComponentDataType test
  MESSAGE("Find ComponentDataType of compo1");
  name = compo1->ComponentDataType();
  MESSAGE("-> ComponentDataType is "<<name);
  
  // FindObject Test
  SALOMEDS::SObject_var objn = myStudy->FindObject("cylinder_0");
 // Test FindAttribute function : get AttributeName attribute
  MESSAGE("Find Name in object objn");
  if (objn->FindAttribute(anAttr, "AttributeName")) {
    Name = SALOMEDS::AttributeName::_narrow(anAttr);
    CORBA::String_var Val = Name->Value();
    MESSAGE("-> Name is "<<Val);
  }
  else {
    MESSAGE("-> Name is not found");
  }

  // FindObjectID Test
  SALOMEDS::SObject_var obj = myStudy->FindObjectID("0:1:2:1:1");
 // Test FindAttribute function : get AttributeName attribute
  MESSAGE("Find Name in object obj");
  if (obj->FindAttribute(anAttr, "AttributeName")) {
    Name = SALOMEDS::AttributeName::_narrow(anAttr);
    CORBA::String_var Val = Name->Value();
    MESSAGE("-> Name is "<<Val);
  }
  else {
    MESSAGE("-> Name is not found");
  }
  //DumpStudy();
  }
  catch(HDFexception)
    {
      MESSAGE("HDFexception ! ");
    } 
}

///////////////////////////// MAIN ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{ 
  try {
    // Initialise the ORB.
    SetArgcArgv(argc, argv);
    CORBA::ORB_var orb = KERNEL::GetRefToORB() ;
    
    // Obtain a reference to the root POA.
    CORBA::Object_var obj = orb->resolve_initial_references("RootPOA");
    PortableServer::POA_var poa = PortableServer::POA::_narrow(obj);

    // Obtain a POAManager, and tell the POA to start accepting
    // requests on its objects.
    PortableServer::POAManager_var pman = poa->the_POAManager();
    pman->activate();

    // Test basic services
    Test();

    orb->run();
    orb->destroy();
  }
  catch(CORBA::SystemException&) {
    MESSAGE("Caught CORBA::SystemException.");
  }
  catch(CORBA::Exception&) {
    MESSAGE("Caught CORBA::Exception.");
  }
  catch(omniORB::fatalException& fe) { //!< TODO: unused variable
    MESSAGE("Caught omniORB::fatalException:");
    MESSAGE("  file: " << fe.file());
    MESSAGE("  line: " << fe.line());
    MESSAGE("  mesg: " << fe.errmsg());
  }
  catch(...) {
    MESSAGE("Caught unknown exception.");
  }
  return 0;
}
