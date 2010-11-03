#ifndef PASSIVE_ELECTRICAL_CIRCUIT_METAMODELBONX_H
#define PASSIVE_ELECTRICAL_CIRCUIT_METAMODELBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace StateMachine {    DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ElementImpl, Element ); }
namespace StateMachine {    DECLARE_ABSTRACT_BONEXTENSION( Element, BiTermElementImpl, BiTermElement ); }
namespace StateMachine {    DECLARE_ABSTRACT_BONEXTENSION( Element, MultiTermElementImpl, MultiTermElement ); }
namespace StateMachine {    DECLARE_ABSTRACT_BONEXTENSION( Element, TwoTermElementImpl, TwoTermElement ); }
namespace StateMachine {    DECLARE_BONEXTENSION( MultiTermElement, AssemblyImpl, Assembly ); }
namespace StateMachine {    DECLARE_BONEXTENSION( TwoTermElement, CapacitorImpl, Capacitor ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BiTermElement, CurrentSourceImpl, CurrentSource ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BiTermElement, DiodeImpl, Diode ); }
namespace StateMachine {    DECLARE_BONEXTENSION( TwoTermElement, InductorImpl, Inductor ); }
namespace StateMachine {    DECLARE_BONEXTENSION( TwoTermElement, ResistorImpl, Resistor ); }
namespace StateMachine {    DECLARE_ABSTRACT_BONEXTENSION2( Element, BiTermElement, TriTermElementImpl, TriTermElement ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BiTermElement, VoltageSourceImpl, VoltageSource ); }
namespace StateMachine {    DECLARE_BONEXTENSION( TriTermElement, BFETImpl, BFET ); }
namespace StateMachine {    DECLARE_ABSTRACT_BONEXTENSION( BON::FCO, StateBaseImpl, StateBase ); }
namespace StateMachine {    DECLARE_BONEXTENSION2( BON::Model, StateBase, StateImpl, State ); }
namespace StateMachine {    DECLARE_BONEXTENSION2( BON::Atom, StateBase, EndStateImpl, EndState ); }
namespace StateMachine {    DECLARE_BONEXTENSION2( BON::Atom, StateBase, StartStateImpl, StartState ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Model, PhysicsModelListImpl, PhysicsModelList ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Model, ResistanceDiffusionModelImpl, ResistanceDiffusionModel ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Model, StateMachineImpl, StateMachine ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Model, TerminalImpl, Terminal ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Connection, LineImpl, Line ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Connection, TransitionImpl, Transition ); }
namespace StateMachine {    DECLARE_BONEXTENSION( BON::Reference, DiffusionModelReferenceImpl, DiffusionModelReference ); }


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   ElementImpl
//*******************************************************************
class ElementImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::Line>    getLine();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   BiTermElementImpl
//*******************************************************************
class BiTermElementImpl :
	  virtual public ElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::Terminal>          getprimary();
	virtual std::set<StateMachine::Terminal>          getsecondary();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   MultiTermElementImpl
//*******************************************************************
class MultiTermElementImpl :
	  public ElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::Terminal>          getleads();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   TwoTermElementImpl
//*******************************************************************
class TwoTermElementImpl :
	  public ElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::Terminal>          getleads();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   AssemblyImpl
//*******************************************************************
class AssemblyImpl :
	  public MultiTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::Assembly>          getAssembly();
	virtual std::set<StateMachine::BFET>    getBFET();
	virtual std::set<StateMachine::Capacitor>         getCapacitor();
	virtual std::set<StateMachine::CurrentSource>     getCurrentSource();
	virtual std::set<StateMachine::Diode>   getDiode();
	virtual std::set<StateMachine::Element> getElement();
	virtual std::set<StateMachine::Inductor>          getInductor();
	virtual std::set<StateMachine::Resistor>          getResistor();
	virtual std::set<StateMachine::VoltageSource>     getVoltageSource();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   CapacitorImpl
//*******************************************************************
class CapacitorImpl :
	  public TwoTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual double      getcapacitance() ;
	virtual void        setcapacitance( const double val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   CurrentSourceImpl
//*******************************************************************
class CurrentSourceImpl :
	  public BiTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   DiodeImpl
//*******************************************************************
class DiodeImpl :
	  public BiTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   InductorImpl
//*******************************************************************
class InductorImpl :
	  public TwoTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual double      getinductance() ;
	virtual void        setinductance( const double val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   ResistorImpl
//*******************************************************************
class ResistorImpl :
	  public TwoTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getlength() ;
	virtual double      getresistance() ;
	virtual double      gettemp_1() ;
	virtual double      gettemp_2() ;
	virtual std::string getwidth() ;
	virtual void        setlength( const std::string& val);
	virtual void        setresistance( const double val);
	virtual void        settemp_1( const double val);
	virtual void        settemp_2( const double val);
	virtual void        setwidth( const std::string& val);
	//
	// kind and role getters
	virtual std::set<StateMachine::DiffusionModelReference> getDiffusionModelReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   TriTermElementImpl
//*******************************************************************
class TriTermElementImpl :
	  virtual public ElementImpl
	, public BiTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::Terminal>          gettertiary();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   VoltageSourceImpl
//*******************************************************************
class VoltageSourceImpl :
	  public BiTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   BFETImpl
//*******************************************************************
class BFETImpl :
	  public TriTermElementImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   StateBaseImpl
//*******************************************************************
class StateBaseImpl :
	  virtual public BON::FCOImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };

	//
	// connectionEnd getters
	virtual std::set<StateMachine::Transition>        getInTransitionLinks();
	virtual std::set<StateMachine::Transition>        getOutTransitionLinks();
	virtual std::multiset<StateMachine::StateBase>    getTransitionDsts();
	virtual std::set<StateMachine::Transition>        getTransitionLinks();
	virtual std::multiset<StateMachine::StateBase>    getTransitionSrcs();
	//
	// attribute getters and setters
	virtual std::string getDoAction() ;
	virtual void        setDoAction( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   StateImpl
//*******************************************************************
class StateImpl :
	  virtual public BON::ModelImpl
	, public StateBaseImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::EndState>          getEndState();
	virtual std::set<StateMachine::StartState>        getStartState();
	virtual std::set<StateMachine::State>   getState();
	virtual std::set<StateMachine::StateBase>         getStateBase();
	virtual std::set<StateMachine::Transition>        getTransition();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   EndStateImpl
//*******************************************************************
class EndStateImpl :
	  virtual public BON::AtomImpl
	, public StateBaseImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   StartStateImpl
//*******************************************************************
class StartStateImpl :
	  virtual public BON::AtomImpl
	, public StateBaseImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   PhysicsModelListImpl
//*******************************************************************
class PhysicsModelListImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::ResistanceDiffusionModel> getResistanceDiffusionModel();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   ResistanceDiffusionModelImpl
//*******************************************************************
class ResistanceDiffusionModelImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getdefw() ;
	virtual std::string getname() ;
	virtual std::string getnarrow() ;
	virtual std::string getrsh() ;
	virtual void        setdefw( const std::string& val);
	virtual void        setname( const std::string& val);
	virtual void        setnarrow( const std::string& val);
	virtual void        setrsh( const std::string& val);

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   StateMachineImpl
//*******************************************************************
class StateMachineImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<StateMachine::EndState>          getEndState();
	virtual std::set<StateMachine::StartState>        getStartState();
	virtual std::set<StateMachine::State>   getState();
	virtual std::set<StateMachine::StateBase>         getStateBase();
	virtual std::set<StateMachine::Transition>        getTransition();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   TerminalImpl
//*******************************************************************
class TerminalImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<StateMachine::Line>    getInLineLinks();
	virtual std::multiset<StateMachine::Terminal>     getLineDsts();
	virtual std::set<StateMachine::Line>    getLineLinks();
	virtual std::multiset<StateMachine::Terminal>     getLineSrcs();
	virtual std::set<StateMachine::Line>    getOutLineLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   LineImpl
//*******************************************************************
class LineImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual StateMachine::Terminal          getDst();
	virtual StateMachine::Terminal          getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   TransitionImpl
//*******************************************************************
class TransitionImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// attribute getters and setters
	virtual std::string getGuard() ;
	virtual void        setGuard( const std::string& val);
	//
	// connectionEnd getters
	virtual StateMachine::StateBase         getDst();
	virtual StateMachine::StateBase         getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace StateMachine
{
//*******************************************************************
//   C  L  A  S  S   DiffusionModelReferenceImpl
//*******************************************************************
class DiffusionModelReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual void        initialize() { };
	virtual void        finalize() { };
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// ref getters
	virtual StateMachine::ResistanceDiffusionModel    getResistanceDiffusionModel();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


///BUP
// add your additional class definitions here
///EUP

#endif // PASSIVE_ELECTRICAL_CIRCUIT_METAMODELBONX_H
