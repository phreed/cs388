#include "stdafx.h"
#include "passive_electrical_circuit_metamodelBonX.h"


namespace BON
{

IMPLEMENT_ABSTRACT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Element );
IMPLEMENT_ABSTRACT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::BiTermElement );
IMPLEMENT_ABSTRACT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::MultiTermElement );
IMPLEMENT_ABSTRACT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::TwoTermElement );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Assembly, "Assembly" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Capacitor, "Capacitor" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::CurrentSource, "CurrentSource" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Diode, "Diode" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Inductor, "Inductor" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Resistor, "Resistor" );
IMPLEMENT_ABSTRACT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::TriTermElement );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::VoltageSource, "VoltageSource" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::BFET, "BFET" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::PhysicsModelList, "PhysicsModelList" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel, "ResistanceDiffusionModel" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Terminal, "Terminal" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::Line, "Line" );
IMPLEMENT_BONEXTENSION( passive_electrical_circuit_metamodel_BON::DiffusionModelReference, "DiffusionModelReference" );


} // namespace BON

//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Line" among "passive_electrical_circuit_metamodel_BON::Line"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Line> passive_electrical_circuit_metamodel_BON::ElementImpl::getLine()
{
	std::set<passive_electrical_circuit_metamodel_BON::Line> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Line");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Line elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::BiTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "primary" among "passive_electrical_circuit_metamodel_BON::Terminal"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::BiTermElementImpl::getprimary()
{
	std::set<passive_electrical_circuit_metamodel_BON::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("primary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "secondary" among "passive_electrical_circuit_metamodel_BON::Terminal"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::BiTermElementImpl::getsecondary()
{
	std::set<passive_electrical_circuit_metamodel_BON::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("secondary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::MultiTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "leads" among "passive_electrical_circuit_metamodel_BON::Terminal"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::MultiTermElementImpl::getleads()
{
	std::set<passive_electrical_circuit_metamodel_BON::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("leads");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::TwoTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "leads" among "passive_electrical_circuit_metamodel_BON::Terminal"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::TwoTermElementImpl::getleads()
{
	std::set<passive_electrical_circuit_metamodel_BON::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("leads");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::AssemblyImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Assembly" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Assembly> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getAssembly()
{
	std::set<passive_electrical_circuit_metamodel_BON::Assembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Assembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Assembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BFET" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::BFET> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getBFET()
{
	std::set<passive_electrical_circuit_metamodel_BON::BFET> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BFET");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::BFET elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Capacitor" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Capacitor> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getCapacitor()
{
	std::set<passive_electrical_circuit_metamodel_BON::Capacitor> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Capacitor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Capacitor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CurrentSource" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::CurrentSource> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getCurrentSource()
{
	std::set<passive_electrical_circuit_metamodel_BON::CurrentSource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CurrentSource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::CurrentSource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Diode" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Diode> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getDiode()
{
	std::set<passive_electrical_circuit_metamodel_BON::Diode> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Diode");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Diode elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "passive_electrical_circuit_metamodel_BON::" among "passive_electrical_circuit_metamodel_BON::Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Element> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getElement()
{
	std::set<passive_electrical_circuit_metamodel_BON::Element> res;
	const int len = 8;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("Assembly");
	roles_vec[1] = ModelImpl::getChildFCOsAs("BFET");
	roles_vec[2] = ModelImpl::getChildFCOsAs("Capacitor");
	roles_vec[3] = ModelImpl::getChildFCOsAs("CurrentSource");
	roles_vec[4] = ModelImpl::getChildFCOsAs("Diode");
	roles_vec[5] = ModelImpl::getChildFCOsAs("Inductor");
	roles_vec[6] = ModelImpl::getChildFCOsAs("Resistor");
	roles_vec[7] = ModelImpl::getChildFCOsAs("VoltageSource");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			passive_electrical_circuit_metamodel_BON::Element elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Inductor" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Inductor> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getInductor()
{
	std::set<passive_electrical_circuit_metamodel_BON::Inductor> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Inductor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Inductor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Resistor" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Resistor> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getResistor()
{
	std::set<passive_electrical_circuit_metamodel_BON::Resistor> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Resistor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Resistor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "VoltageSource" among "Element"s and its descendants
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::VoltageSource> passive_electrical_circuit_metamodel_BON::AssemblyImpl::getVoltageSource()
{
	std::set<passive_electrical_circuit_metamodel_BON::VoltageSource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("VoltageSource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::VoltageSource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::CapacitorImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
double passive_electrical_circuit_metamodel_BON::CapacitorImpl::getcapacitance() 
{
	return FCOImpl::getAttribute("capacitance")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::CapacitorImpl::setcapacitance( const double val)
{
	FCOImpl::getAttribute("capacitance")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::CurrentSourceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::DiodeImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::InductorImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
double passive_electrical_circuit_metamodel_BON::InductorImpl::getinductance() 
{
	return FCOImpl::getAttribute("inductance")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::InductorImpl::setinductance( const double val)
{
	FCOImpl::getAttribute("inductance")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistorImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string passive_electrical_circuit_metamodel_BON::ResistorImpl::getlength() 
{
	return FCOImpl::getAttribute("length")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
double passive_electrical_circuit_metamodel_BON::ResistorImpl::getresistance() 
{
	return FCOImpl::getAttribute("resistance")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
double passive_electrical_circuit_metamodel_BON::ResistorImpl::gettemp_1() 
{
	return FCOImpl::getAttribute("temp_1")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
double passive_electrical_circuit_metamodel_BON::ResistorImpl::gettemp_2() 
{
	return FCOImpl::getAttribute("temp_2")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string passive_electrical_circuit_metamodel_BON::ResistorImpl::getwidth() 
{
	return FCOImpl::getAttribute("width")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistorImpl::setlength( const std::string& val)
{
	FCOImpl::getAttribute("length")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistorImpl::setresistance( const double val)
{
	FCOImpl::getAttribute("resistance")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistorImpl::settemp_1( const double val)
{
	FCOImpl::getAttribute("temp_1")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistorImpl::settemp_2( const double val)
{
	FCOImpl::getAttribute("temp_2")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistorImpl::setwidth( const std::string& val)
{
	FCOImpl::getAttribute("width")->setStringValue( val);
}


//********************************************************************************
// getter for role "DiffusionModelReference" among "passive_electrical_circuit_metamodel_BON::DiffusionModelReference"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::DiffusionModelReference> passive_electrical_circuit_metamodel_BON::ResistorImpl::getDiffusionModelReference()
{
	std::set<passive_electrical_circuit_metamodel_BON::DiffusionModelReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DiffusionModelReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::DiffusionModelReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::TriTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "tertiary" among "passive_electrical_circuit_metamodel_BON::Terminal"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::TriTermElementImpl::gettertiary()
{
	std::set<passive_electrical_circuit_metamodel_BON::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("tertiary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::VoltageSourceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::BFETImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::PhysicsModelListImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "ResistanceDiffusionModel" among "passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel"s
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel> passive_electrical_circuit_metamodel_BON::PhysicsModelListImpl::getResistanceDiffusionModel()
{
	std::set<passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ResistanceDiffusionModel");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::getdefw() 
{
	return FCOImpl::getAttribute("defw")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::getname() 
{
	return FCOImpl::getAttribute("name")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::getnarrow() 
{
	return FCOImpl::getAttribute("narrow")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::getrsh() 
{
	return FCOImpl::getAttribute("rsh")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::setdefw( const std::string& val)
{
	FCOImpl::getAttribute("defw")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::setname( const std::string& val)
{
	FCOImpl::getAttribute("name")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::setnarrow( const std::string& val)
{
	FCOImpl::getAttribute("narrow")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModelImpl::setrsh( const std::string& val)
{
	FCOImpl::getAttribute("rsh")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::TerminalImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Line> passive_electrical_circuit_metamodel_BON::TerminalImpl::getInLineLinks()
{
	std::set<passive_electrical_circuit_metamodel_BON::Line> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		passive_electrical_circuit_metamodel_BON::Line c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst passive_electrical_circuit_metamodel_BON::Terminals
//********************************************************************************
std::multiset<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::TerminalImpl::getLineDsts()
{
	std::multiset<passive_electrical_circuit_metamodel_BON::Terminal> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Line");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			passive_electrical_circuit_metamodel_BON::Terminal dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Line> passive_electrical_circuit_metamodel_BON::TerminalImpl::getLineLinks()
{
	std::set<passive_electrical_circuit_metamodel_BON::Line> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		passive_electrical_circuit_metamodel_BON::Line c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src passive_electrical_circuit_metamodel_BON::Terminals
//********************************************************************************
std::multiset<passive_electrical_circuit_metamodel_BON::Terminal> passive_electrical_circuit_metamodel_BON::TerminalImpl::getLineSrcs()
{
	std::multiset<passive_electrical_circuit_metamodel_BON::Terminal> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Line");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			passive_electrical_circuit_metamodel_BON::Terminal dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<passive_electrical_circuit_metamodel_BON::Line> passive_electrical_circuit_metamodel_BON::TerminalImpl::getOutLineLinks()
{
	std::set<passive_electrical_circuit_metamodel_BON::Line> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		passive_electrical_circuit_metamodel_BON::Line c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::LineImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to passive_electrical_circuit_metamodel_BON::Terminal
//********************************************************************************
passive_electrical_circuit_metamodel_BON::Terminal passive_electrical_circuit_metamodel_BON::LineImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	passive_electrical_circuit_metamodel_BON::Terminal sp( ce);
	if ( sp)
		return sp;

	passive_electrical_circuit_metamodel_BON::Terminal empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to passive_electrical_circuit_metamodel_BON::Terminal
//********************************************************************************
passive_electrical_circuit_metamodel_BON::Terminal passive_electrical_circuit_metamodel_BON::LineImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	passive_electrical_circuit_metamodel_BON::Terminal sp( ce);
	if ( sp)
		return sp;

	passive_electrical_circuit_metamodel_BON::Terminal empty;
	return empty;
}


//********************************************************************************
// 
//********************************************************************************
void passive_electrical_circuit_metamodel_BON::DiffusionModelReferenceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Reference
	pVisitor->visitReference( BON::Reference( this));

}


//********************************************************************************
// 
//********************************************************************************
passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel passive_electrical_circuit_metamodel_BON::DiffusionModelReferenceImpl::getResistanceDiffusionModel()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel(r);
}


