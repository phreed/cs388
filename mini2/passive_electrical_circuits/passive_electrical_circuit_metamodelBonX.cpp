#include "stdafx.h"
#include "passive_electrical_circuit_metamodelBonX.h"


namespace BON
{

IMPLEMENT_ABSTRACT_BONEXTENSION( StateMachine::Element );
IMPLEMENT_ABSTRACT_BONEXTENSION( StateMachine::BiTermElement );
IMPLEMENT_ABSTRACT_BONEXTENSION( StateMachine::MultiTermElement );
IMPLEMENT_ABSTRACT_BONEXTENSION( StateMachine::TwoTermElement );
IMPLEMENT_BONEXTENSION( StateMachine::Assembly, "Assembly" );
IMPLEMENT_BONEXTENSION( StateMachine::Capacitor, "Capacitor" );
IMPLEMENT_BONEXTENSION( StateMachine::CurrentSource, "CurrentSource" );
IMPLEMENT_BONEXTENSION( StateMachine::Diode, "Diode" );
IMPLEMENT_BONEXTENSION( StateMachine::Inductor, "Inductor" );
IMPLEMENT_BONEXTENSION( StateMachine::Resistor, "Resistor" );
IMPLEMENT_ABSTRACT_BONEXTENSION( StateMachine::TriTermElement );
IMPLEMENT_BONEXTENSION( StateMachine::VoltageSource, "VoltageSource" );
IMPLEMENT_BONEXTENSION( StateMachine::BFET, "BFET" );
IMPLEMENT_ABSTRACT_BONEXTENSION( StateMachine::StateBase );
IMPLEMENT_BONEXTENSION( StateMachine::State, "State" );
IMPLEMENT_BONEXTENSION( StateMachine::EndState, "EndState" );
IMPLEMENT_BONEXTENSION( StateMachine::StartState, "StartState" );
IMPLEMENT_BONEXTENSION( StateMachine::PhysicsModelList, "PhysicsModelList" );
IMPLEMENT_BONEXTENSION( StateMachine::ResistanceDiffusionModel, "ResistanceDiffusionModel" );
IMPLEMENT_BONEXTENSION( StateMachine::StateMachine, "StateMachine" );
IMPLEMENT_BONEXTENSION( StateMachine::Terminal, "Terminal" );
IMPLEMENT_BONEXTENSION( StateMachine::Line, "Line" );
IMPLEMENT_BONEXTENSION( StateMachine::Transition, "Transition" );
IMPLEMENT_BONEXTENSION( StateMachine::DiffusionModelReference, "DiffusionModelReference" );


} // namespace BON

//********************************************************************************
// 
//********************************************************************************
void StateMachine::ElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Line" among "StateMachine::Line"s
//********************************************************************************
std::set<StateMachine::Line> StateMachine::ElementImpl::getLine()
{
	std::set<StateMachine::Line> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Line");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Line elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::BiTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "primary" among "StateMachine::Terminal"s
//********************************************************************************
std::set<StateMachine::Terminal> StateMachine::BiTermElementImpl::getprimary()
{
	std::set<StateMachine::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("primary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "secondary" among "StateMachine::Terminal"s
//********************************************************************************
std::set<StateMachine::Terminal> StateMachine::BiTermElementImpl::getsecondary()
{
	std::set<StateMachine::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("secondary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::MultiTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "leads" among "StateMachine::Terminal"s
//********************************************************************************
std::set<StateMachine::Terminal> StateMachine::MultiTermElementImpl::getleads()
{
	std::set<StateMachine::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("leads");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::TwoTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "leads" among "StateMachine::Terminal"s
//********************************************************************************
std::set<StateMachine::Terminal> StateMachine::TwoTermElementImpl::getleads()
{
	std::set<StateMachine::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("leads");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::AssemblyImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "Assembly" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::Assembly> StateMachine::AssemblyImpl::getAssembly()
{
	std::set<StateMachine::Assembly> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Assembly");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Assembly elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "BFET" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::BFET> StateMachine::AssemblyImpl::getBFET()
{
	std::set<StateMachine::BFET> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("BFET");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::BFET elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Capacitor" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::Capacitor> StateMachine::AssemblyImpl::getCapacitor()
{
	std::set<StateMachine::Capacitor> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Capacitor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Capacitor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "CurrentSource" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::CurrentSource> StateMachine::AssemblyImpl::getCurrentSource()
{
	std::set<StateMachine::CurrentSource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("CurrentSource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::CurrentSource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Diode" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::Diode> StateMachine::AssemblyImpl::getDiode()
{
	std::set<StateMachine::Diode> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Diode");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Diode elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "StateMachine::" among "StateMachine::Element"s and its descendants
//********************************************************************************
std::set<StateMachine::Element> StateMachine::AssemblyImpl::getElement()
{
	std::set<StateMachine::Element> res;
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
			StateMachine::Element elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Inductor" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::Inductor> StateMachine::AssemblyImpl::getInductor()
{
	std::set<StateMachine::Inductor> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Inductor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Inductor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "Resistor" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::Resistor> StateMachine::AssemblyImpl::getResistor()
{
	std::set<StateMachine::Resistor> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Resistor");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Resistor elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "VoltageSource" among "Element"s and its descendants
//********************************************************************************
std::set<StateMachine::VoltageSource> StateMachine::AssemblyImpl::getVoltageSource()
{
	std::set<StateMachine::VoltageSource> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("VoltageSource");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::VoltageSource elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::CapacitorImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
double StateMachine::CapacitorImpl::getcapacitance() 
{
	return FCOImpl::getAttribute("capacitance")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::CapacitorImpl::setcapacitance( const double val)
{
	FCOImpl::getAttribute("capacitance")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::CurrentSourceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::DiodeImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::InductorImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
double StateMachine::InductorImpl::getinductance() 
{
	return FCOImpl::getAttribute("inductance")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::InductorImpl::setinductance( const double val)
{
	FCOImpl::getAttribute("inductance")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistorImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::ResistorImpl::getlength() 
{
	return FCOImpl::getAttribute("length")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
double StateMachine::ResistorImpl::getresistance() 
{
	return FCOImpl::getAttribute("resistance")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
double StateMachine::ResistorImpl::gettemp_1() 
{
	return FCOImpl::getAttribute("temp_1")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
double StateMachine::ResistorImpl::gettemp_2() 
{
	return FCOImpl::getAttribute("temp_2")->getRealValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::ResistorImpl::getwidth() 
{
	return FCOImpl::getAttribute("width")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistorImpl::setlength( const std::string& val)
{
	FCOImpl::getAttribute("length")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistorImpl::setresistance( const double val)
{
	FCOImpl::getAttribute("resistance")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistorImpl::settemp_1( const double val)
{
	FCOImpl::getAttribute("temp_1")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistorImpl::settemp_2( const double val)
{
	FCOImpl::getAttribute("temp_2")->setRealValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistorImpl::setwidth( const std::string& val)
{
	FCOImpl::getAttribute("width")->setStringValue( val);
}


//********************************************************************************
// getter for role "DiffusionModelReference" among "StateMachine::DiffusionModelReference"s
//********************************************************************************
std::set<StateMachine::DiffusionModelReference> StateMachine::ResistorImpl::getDiffusionModelReference()
{
	std::set<StateMachine::DiffusionModelReference> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("DiffusionModelReference");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::DiffusionModelReference elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::TriTermElementImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "tertiary" among "StateMachine::Terminal"s
//********************************************************************************
std::set<StateMachine::Terminal> StateMachine::TriTermElementImpl::gettertiary()
{
	std::set<StateMachine::Terminal> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("tertiary");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Terminal elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::VoltageSourceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::BFETImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<StateMachine::Transition> StateMachine::StateBaseImpl::getInTransitionLinks()
{
	std::set<StateMachine::Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		StateMachine::Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
std::set<StateMachine::Transition> StateMachine::StateBaseImpl::getOutTransitionLinks()
{
	std::set<StateMachine::Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		StateMachine::Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst StateMachine::StateBases
//********************************************************************************
std::multiset<StateMachine::StateBase> StateMachine::StateBaseImpl::getTransitionDsts()
{
	std::multiset<StateMachine::StateBase> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Transition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			StateMachine::StateBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<StateMachine::Transition> StateMachine::StateBaseImpl::getTransitionLinks()
{
	std::set<StateMachine::Transition> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		StateMachine::Transition c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src StateMachine::StateBases
//********************************************************************************
std::multiset<StateMachine::StateBase> StateMachine::StateBaseImpl::getTransitionSrcs()
{
	std::multiset<StateMachine::StateBase> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Transition");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			StateMachine::StateBase dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::StateBaseImpl::getDoAction() 
{
	return FCOImpl::getAttribute("DoAction")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::StateBaseImpl::setDoAction( const std::string& val)
{
	FCOImpl::getAttribute("DoAction")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::StateImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "EndState" among "StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::EndState> StateMachine::StateImpl::getEndState()
{
	std::set<StateMachine::EndState> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EndState");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::EndState elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "StartState" among "StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::StartState> StateMachine::StateImpl::getStartState()
{
	std::set<StateMachine::StartState> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("StartState");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::StartState elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "State" among "StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::State> StateMachine::StateImpl::getState()
{
	std::set<StateMachine::State> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("State");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::State elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "StateMachine::" among "StateMachine::StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::StateBase> StateMachine::StateImpl::getStateBase()
{
	std::set<StateMachine::StateBase> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("EndState");
	roles_vec[1] = ModelImpl::getChildFCOsAs("StartState");
	roles_vec[2] = ModelImpl::getChildFCOsAs("State");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			StateMachine::StateBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Transition" among "StateMachine::Transition"s
//********************************************************************************
std::set<StateMachine::Transition> StateMachine::StateImpl::getTransition()
{
	std::set<StateMachine::Transition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Transition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Transition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::EndStateImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::StartStateImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Atom
	pVisitor->visitAtom( BON::Atom( this));

}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::PhysicsModelListImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "ResistanceDiffusionModel" among "StateMachine::ResistanceDiffusionModel"s
//********************************************************************************
std::set<StateMachine::ResistanceDiffusionModel> StateMachine::PhysicsModelListImpl::getResistanceDiffusionModel()
{
	std::set<StateMachine::ResistanceDiffusionModel> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("ResistanceDiffusionModel");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::ResistanceDiffusionModel elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistanceDiffusionModelImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::ResistanceDiffusionModelImpl::getdefw() 
{
	return FCOImpl::getAttribute("defw")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::ResistanceDiffusionModelImpl::getname() 
{
	return FCOImpl::getAttribute("name")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::ResistanceDiffusionModelImpl::getnarrow() 
{
	return FCOImpl::getAttribute("narrow")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::ResistanceDiffusionModelImpl::getrsh() 
{
	return FCOImpl::getAttribute("rsh")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistanceDiffusionModelImpl::setdefw( const std::string& val)
{
	FCOImpl::getAttribute("defw")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistanceDiffusionModelImpl::setname( const std::string& val)
{
	FCOImpl::getAttribute("name")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistanceDiffusionModelImpl::setnarrow( const std::string& val)
{
	FCOImpl::getAttribute("narrow")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::ResistanceDiffusionModelImpl::setrsh( const std::string& val)
{
	FCOImpl::getAttribute("rsh")->setStringValue( val);
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::StateMachineImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// getter for role "EndState" among "StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::EndState> StateMachine::StateMachineImpl::getEndState()
{
	std::set<StateMachine::EndState> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("EndState");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::EndState elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "StartState" among "StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::StartState> StateMachine::StateMachineImpl::getStartState()
{
	std::set<StateMachine::StartState> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("StartState");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::StartState elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// getter for role "State" among "StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::State> StateMachine::StateMachineImpl::getState()
{
	std::set<StateMachine::State> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("State");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::State elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// aggregated getter for role "StateMachine::" among "StateMachine::StateBase"s and its descendants
//********************************************************************************
std::set<StateMachine::StateBase> StateMachine::StateMachineImpl::getStateBase()
{
	std::set<StateMachine::StateBase> res;
	const int len = 3;
	std::set<BON::FCO> roles_vec[ len];
	roles_vec[0] = ModelImpl::getChildFCOsAs("EndState");
	roles_vec[1] = ModelImpl::getChildFCOsAs("StartState");
	roles_vec[2] = ModelImpl::getChildFCOsAs("State");
	for( int k = 0; k < len; ++k)
		for( std::set<BON::FCO>::iterator i = roles_vec[k].begin(); i != roles_vec[k].end(); ++i)
		{
			StateMachine::StateBase elem(*i);
			ASSERT(elem);
			res.insert(elem);
		}
	return res;
}


//********************************************************************************
// getter for role "Transition" among "StateMachine::Transition"s
//********************************************************************************
std::set<StateMachine::Transition> StateMachine::StateMachineImpl::getTransition()
{
	std::set<StateMachine::Transition> res;
	std::set<BON::FCO> roles = ModelImpl::getChildFCOsAs("Transition");
	for( std::set<BON::FCO>::iterator i = roles.begin(); i != roles.end(); ++i)
	{
		StateMachine::Transition elem(*i);
		ASSERT(elem);
		res.insert(elem);
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::TerminalImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Model
	pVisitor->visitModel( BON::Model( this));

}


//********************************************************************************
// 
//********************************************************************************
std::set<StateMachine::Line> StateMachine::TerminalImpl::getInLineLinks()
{
	std::set<StateMachine::Line> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getInConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		StateMachine::Line c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns dst StateMachine::Terminals
//********************************************************************************
std::multiset<StateMachine::Terminal> StateMachine::TerminalImpl::getLineDsts()
{
	std::multiset<StateMachine::Terminal> res;
	{
		std::multiset<BON::ConnectionEnd> out_ends = BON::ConnectionEndImpl::getOutConnEnds("Line");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = out_ends.begin() ; cit != out_ends.end() ; ++cit )
		{
			StateMachine::Terminal dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<StateMachine::Line> StateMachine::TerminalImpl::getLineLinks()
{
	std::set<StateMachine::Line> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		StateMachine::Line c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// returns src StateMachine::Terminals
//********************************************************************************
std::multiset<StateMachine::Terminal> StateMachine::TerminalImpl::getLineSrcs()
{
	std::multiset<StateMachine::Terminal> res;
	{
		std::multiset<BON::ConnectionEnd> in_ends = BON::ConnectionEndImpl::getInConnEnds("Line");
		for ( std::multiset<BON::ConnectionEnd>::iterator cit = in_ends.begin() ; cit != in_ends.end() ; ++cit )
		{
			StateMachine::Terminal dst( *cit );
			ASSERT(dst);
			res.insert( dst);
		}
	}
	return res;
}


//********************************************************************************
// 
//********************************************************************************
std::set<StateMachine::Line> StateMachine::TerminalImpl::getOutLineLinks()
{
	std::set<StateMachine::Line> result;
	std::set<BON::Connection> conns = ConnectionEndImpl::getOutConnLinks();
	std::set<BON::Connection>::iterator it = conns.begin();
	for( ; it != conns.end(); ++it)
	{
		StateMachine::Line c( *it);
		if (c)
			result.insert( c);
	}
	return result;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::LineImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to StateMachine::Terminal
//********************************************************************************
StateMachine::Terminal StateMachine::LineImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	StateMachine::Terminal sp( ce);
	if ( sp)
		return sp;

	StateMachine::Terminal empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to StateMachine::Terminal
//********************************************************************************
StateMachine::Terminal StateMachine::LineImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	StateMachine::Terminal sp( ce);
	if ( sp)
		return sp;

	StateMachine::Terminal empty;
	return empty;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::TransitionImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Connection
	pVisitor->visitConnection( BON::Connection( this));

}


//********************************************************************************
// 
//********************************************************************************
std::string StateMachine::TransitionImpl::getGuard() 
{
	return FCOImpl::getAttribute("Guard")->getStringValue();
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::TransitionImpl::setGuard( const std::string& val)
{
	FCOImpl::getAttribute("Guard")->setStringValue( val);
}


//********************************************************************************
// getDst() return value is a ConnectionEnd casted to StateMachine::StateBase
//********************************************************************************
StateMachine::StateBase StateMachine::TransitionImpl::getDst()
{
	BON::ConnectionEnd ce = ConnectionImpl::getDst();
	StateMachine::StateBase sp( ce);
	if ( sp)
		return sp;

	StateMachine::StateBase empty;
	return empty;
}


//********************************************************************************
// getSrc() return value is a ConnectionEnd casted to StateMachine::StateBase
//********************************************************************************
StateMachine::StateBase StateMachine::TransitionImpl::getSrc()
{
	BON::ConnectionEnd ce = ConnectionImpl::getSrc();
	StateMachine::StateBase sp( ce);
	if ( sp)
		return sp;

	StateMachine::StateBase empty;
	return empty;
}


//********************************************************************************
// 
//********************************************************************************
void StateMachine::DiffusionModelReferenceImpl::accept( BON::Visitor *pVisitor)
{
	// visit the Reference
	pVisitor->visitReference( BON::Reference( this));

}


//********************************************************************************
// 
//********************************************************************************
StateMachine::ResistanceDiffusionModel StateMachine::DiffusionModelReferenceImpl::getResistanceDiffusionModel()
{
	BON::FCO r = BON::ReferenceImpl::getReferred();
	return StateMachine::ResistanceDiffusionModel(r);
}


