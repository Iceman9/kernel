//  SALOME SALOMEGUI : implementation of desktop and GUI kernel
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
//  File   : QAD_Config.cxx
//  Author : Nicolas REJNERI
//  Module : SALOME
//  $Header$

using namespace std;
/*!
  \class QAD_Config QAD_Config.h
  \brief Settings file management for QAD-based application.
*/

#include "QAD_Config.h"
#include "QAD_ParserSettings.h"

// QT Includes
#include <qapplication.h>
#include <qfile.h>
#include <qregexp.h>
#include <qtextstream.h>


/*!
    QAD_Config provides access to global settings.
*/
QAD_Config* QAD_Config::theOneAndOnlyConfig=0;


/*!
    Creates a new one on first call.
*/
QAD_Config* QAD_Config::getConfig()
{
  if(theOneAndOnlyConfig==0) {
    theOneAndOnlyConfig = new QAD_Config;
    theOneAndOnlyConfig->ini();
  }
  return theOneAndOnlyConfig;
}



/*!
    Constructor.
*/
QAD_Config::QAD_Config()
 : QAD_Settings('=', '"', '"')
{
}

/*!
    Destructor.
*/
QAD_Config::~QAD_Config()
{
}

/*!
   Initializes the config object (only called once).
*/
void QAD_Config::ini()
{
}


/*!
    Creates not existing config files.
*/
bool QAD_Config::createConfigFile( bool overwrite )
{
  bool ret=true;

#ifdef DEF_WINDOWS
  setConfigDir(QDir(prgDir.absPath()));
#else
  setConfigDir(QDir(QDir::home().absPath() + "/." + tr("MEN_APPNAME") ));
#endif

  // Create config directory:
  if(!configDir.exists()) {
    if(!configDir.mkdir(configDir.absPath(), true)) {
      // Can't create directory for config file!
      return false;
    }
  }
  
  // Create ".<app>.conf":
  QFile configFile(configDir.absPath() + "/" + tr("MEN_APPNAME") + ".conf");

  if(!configFile.exists() || overwrite) {
    if(configFile.open(IO_WriteOnly)) {    // file opened successfully
      QTextStream ts(&configFile);
      QAD_Setting* setting;

      ts <<
	"# This file is automatically generated by " << tr("MEN_APPNAME") << ".\n"
	"# Please edit only if " << tr("MEN_APPNAME") << " is not running.\n";
      
      int sep;
      QString section;
      QString variable;
      QStringList sectionList;      // List of all sections

      // Collect section list:
      for(setting=settingList.first(); setting!=0; setting=settingList.next()) {
        sep = setting->getName().find( ':' );
        section = setting->getName().left( sep );

        if( sectionList.find( section ) == sectionList.end() ) {
          sectionList += section;
        }
      }

      sectionList.sort();

      // Write the sections:
      for( QStringList::Iterator it = sectionList.begin(); it!=sectionList.end(); ++it ) {
        ts << "\n[" << (*it) << "]\n";
        for( setting=settingList.first(); setting!=0; setting=settingList.next() ) {
          sep = setting->getName().find( ':' );
          section = setting->getName().left( sep );

          if( section==(*it) ) {
            variable = setting->getName().right( setting->getName().length()-sep-1 );
            ts << variable << "=\"" << setting->getValue() << "\"\n";
          }
        }
      }

      configFile.close();
    }

    else {
      // Can't create file
      ret=false;
    }
  }

  return ret;
}

/*!
   Reads the config file.
*/
bool QAD_Config::readConfigFile()
{
#ifdef DEF_WINDOWS
  setConfigDir(QDir(prgDir.absPath()));
#else
  setConfigDir(QDir(QDir::home().absPath() + "/." + tr("MEN_APPNAME") ));
#endif

  QString configPath;
  configPath = configDir.absPath() + "/" + tr("MEN_APPNAME") + ".conf";

  int i=0, j, l=0;                    // Index, length of matching string
  QRegExp regSection("\\[[^]]*\\]");  // Reg exp for a section including brackets
  QRegExp regName("[^=[]*");          // Reg exp for a setting name (lvalue)
  QRegExp regValue("\"[^\"]*\"");     // Reg exp for a setting value (rvalue) including quote marks
  QString lSectionName;               // Section name excluding brackets
  QString setName;                    // Setting name
  QString setValue;                   // Setting value

  // Get file contents without comments:
  QString cont = QAD_ParserSettings::getContents(configPath, false);

  do {
    // Read next section (name/contents):
    i=regSection.match(cont, i, &l);
    if(i==-1) break;
    lSectionName = cont.mid(i+1, l-2);
    i+=l;

    // Read next setting:
    do {
      j=regName.match(cont, i, &l);
      if(j==-1) break;
      setName = cont.mid(j, l);
      if(setName.stripWhiteSpace().isEmpty()) break;
      i=j+l;

      j=regValue.match(cont, i, &l);
      if(j==-1) break;
      setValue = cont.mid(j+1, l-2);
      i=j+l;

      addSetting(lSectionName + ":" + setName.stripWhiteSpace(), setValue);

    } while(true);

  } while(true);

  // Add some values which were not saved in config file:

  return false;
}


// EOF
