//#############################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.cpp
//
//#############################################

/*
	Copyright (c) Vanderbilt University, 2000-2004
	ALL RIGHTS RESERVED

	Vanderbilt University disclaims all warranties with regard to this
	software, including all implied warranties of merchantability
	and fitness.  In no event shall Vanderbilt University be liable for
	any special, indirect or consequential damages or any damages
	whatsoever resulting from loss of use, data or profits, whether
	in an action of contract, negligence or other tortious action,
	arising out of or in connection with the use or performance of
	this software.
*/

#include "stdafx.h"
#include <Console.h>
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include "BON2Component.h"
#include "passive_electrical_circuit_metamodelBonX.h"

namespace BON
{

//#############################################
//
// 	C L A S S : BON::Component
//
//#############################################

Component::Component()
	: m_bIsInteractive( false )
{
}

Component::~Component()
{
	if ( m_project ) {
		m_project->finalizeObjects();
		finalize( m_project );
		m_project = NULL;
	}
}

// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This is the obsolete component interface
// This present implementation either tries to call InvokeEx, or does nothing except of a notification

void Component::invoke( Project& project, const std::set<FCO>& setModels, long lParam )
{
	#ifdef SUPPORT_OLD_INVOKE
		Object focus;
		invokeEx( project, focus, setModels, lParam );
	#else
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support the obsolete invoke mechanism!");
	#endif
}

// ====================================================
// This is the main component method for Interpereters and Plugins.
// May also be used in case of invokeable Add-Ons

void Component::invokeEx( Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam )
{
#ifdef GME_ADDON
	project->setAutoCommit( false);
#endif
	using namespace GMEConsole;
	boost::filesystem2::path path = boost::filesystem::current_path();
	Console::Out::WriteLine("Interpreter started...");
	
	// ======================
	std::ofstream ofs("passive_electrical_circuit_outline.txt",std::ios_base::out);
	ofs << "CS388 Mini Project 2 : A Passive Electrical Circuit Outline" << '\n'
		<< "Fred Eisele" << '\n' 
		<< std::endl;

	Folder rootFolder = project->getRootFolder();
	Component::ProcessObject(ofs, rootFolder, 0);
    ofs.close();
    // ======================
	GMEConsole::Console::Out::WriteLine("Interpreter completed...");
}


/**
 * Write the children in order, use depth first search
 * References should display the name of what they point to an not the name of the reference.
 * Connections should name the objects which are connected.
*/
void Component::ProcessObject(std::ostream &ostr, const Object object, int level)
{
	++level;
	std::string indent;
	indent.append(level,'\t');
	std::string name = object->getName();

	MON::Object meta = object->getObjectMeta();
	GMEConsole::Console::Out::WriteLine(meta.name().c_str());

	if (BON::Model(object)) {
		ostr << indent << name << std::endl;
		Model model = Model(object);
		std::set<FCO> children = model->getChildFCOs();
		for(std::set<FCO>::iterator child=children.begin(); 
			child!= children.end(); ++child)
		{		
			Component::ProcessObject(ostr, *child, level); 
		}
	} else if (BON::Atom(object)) {
		ostr << indent << name << std::endl;
	} else if (BON::Folder(object)) {
		ostr << indent <<  name << std::endl;
		Folder folder = Folder(object);
		std::set<Object> children = folder->getChildObjects();
		for(std::set<Object>::iterator child=children.begin(); 
			child!= children.end(); ++child)
		{		
			Component::ProcessObject(ostr, *child, level); 
		}
	} else if (BON::Reference(object)) {
		Reference reference = Reference(object);
		BON::FCO fco = reference->getReferred();
		ostr << indent << name << " -> Ref( " << fco->getName() << " )" << std::endl;
	} else if (BON::Connection(object)) {
		BON::Connection connection = BON::Connection(object);
		std::multiset<BON::ConnectionEnd> ends = connection->getConnEnds();
		ostr << indent <<  name << '(';
		for (std::multiset<BON::ConnectionEnd>::iterator endItr = ends.begin(); endItr != ends.end(); ++endItr) {
			if (endItr != ends.begin()) ostr << ", ";
			BON::FCO endpoint = FCO(*endItr);
			ostr << endpoint->getName();
		}
		ostr << ')' << std::endl;
	} else {
		ostr << indent <<  meta.name() << std::endl;
	}
}
// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
	{
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
	}

// ====================================================
// Implement application specific parameter-mechanism in these functions

Util::Variant Component::getParameter( const std::string& strName )
{
	// ======================
	// Insert application specific code here

	return Util::Variant();
}

void Component::setParameter( const std::string& strName, const Util::Variant& varValue )
{
	// ======================
	// Insert application specific code here
}

#ifdef GME_ADDON

// ====================================================
// If the component is an Add-On, then this method is called for every Global Event

void Component::globalEventPerformed( globalevent_enum event )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// If the component is an Add-On, then this method is called for every Object Event

void Component::objectEventPerformed( Object& object, unsigned long event, VARIANT v )
{
	// ======================
	// Insert application specific code here
}

#endif // GME_ADDON

}; // namespace BON

