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

//  SALOME NamingService : wrapping NamingService services
//  File   : ServiceUnreachable.hxx
//  Author : Paul RASCLE, EDF
//  Module : SALOME
//  $Header$
//
#if !defined ( SERVICEUNREACHABLE_H )
#define SERVICEUNREACHABLE_H

#include "SALOME_NamingService_defs.hxx"
#include "Utils_SALOME_Exception.hxx"

//! exception class for NamingService : ServiceUnreachable

class NAMINGSERVICE_EXPORT ServiceUnreachable : public SALOME_Exception
{
public :
        ServiceUnreachable( void );
        ServiceUnreachable( const ServiceUnreachable &ex  );
} ;

#endif  /* #if ( !defined  SERVICEUNREACHABLE_H ) */
