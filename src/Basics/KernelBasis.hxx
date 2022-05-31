// Copyright (C) 2021-2022  CEA/DEN, EDF R&D
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

#pragma once

#include "SALOME_Basics.hxx"

#include <string>

bool BASICS_EXPORT getSSLMode();
void BASICS_EXPORT setSSLMode(bool sslMode);
bool BASICS_EXPORT getGUIMode();
void BASICS_EXPORT setGUIMode(bool guiMode);

std::string BASICS_EXPORT getIOROfEmbeddedNS();
void BASICS_EXPORT setIOROfEmbeddedNS(const std::string& ior);
