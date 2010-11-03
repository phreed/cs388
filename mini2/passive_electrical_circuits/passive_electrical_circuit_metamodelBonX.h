#ifndef PASSIVE_ELECTRICAL_CIRCUIT_METAMODELBONX_H
#define PASSIVE_ELECTRICAL_CIRCUIT_METAMODELBONX_H

#include "BON.h"
#include "BONImpl.h"
#include "Extensions.h"

///BUP
// add your include files/class definitions here
///EUP

namespace passive_electrical_circuit_metamodel_BON {      DECLARE_ABSTRACT_BONEXTENSION( BON::Model, ElementImpl, Element ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_ABSTRACT_BONEXTENSION( Element, BiTermElementImpl, BiTermElement ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_ABSTRACT_BONEXTENSION( Element, MultiTermElementImpl, MultiTermElement ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_ABSTRACT_BONEXTENSION( Element, TwoTermElementImpl, TwoTermElement ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( MultiTermElement, AssemblyImpl, Assembly ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( TwoTermElement, CapacitorImpl, Capacitor ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BiTermElement, CurrentSourceImpl, CurrentSource ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BiTermElement, DiodeImpl, Diode ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( TwoTermElement, InductorImpl, Inductor ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( TwoTermElement, ResistorImpl, Resistor ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_ABSTRACT_BONEXTENSION2( BiTermElement, Element, TriTermElementImpl, TriTermElement ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BiTermElement, VoltageSourceImpl, VoltageSource ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( TriTermElement, BFETImpl, BFET ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BON::Model, PhysicsModelListImpl, PhysicsModelList ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BON::Model, ResistanceDiffusionModelImpl, ResistanceDiffusionModel ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BON::Model, TerminalImpl, Terminal ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BON::Connection, LineImpl, Line ); }
namespace passive_electrical_circuit_metamodel_BON {      DECLARE_BONEXTENSION( BON::Reference, DiffusionModelReferenceImpl, DiffusionModelReference ); }


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   ElementImpl
//*******************************************************************
class ElementImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Line> getLine();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   BiTermElementImpl
//*******************************************************************
class BiTermElementImpl :
	  virtual public ElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Terminal> getprimary();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Terminal> getsecondary();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   MultiTermElementImpl
//*******************************************************************
class MultiTermElementImpl :
	  public ElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Terminal> getleads();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   TwoTermElementImpl
//*******************************************************************
class TwoTermElementImpl :
	  public ElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Terminal> getleads();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   AssemblyImpl
//*******************************************************************
class AssemblyImpl :
	  public MultiTermElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Assembly> getAssembly();
	virtual std::set<passive_electrical_circuit_metamodel_BON::BFET> getBFET();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Capacitor> getCapacitor();
	virtual std::set<passive_electrical_circuit_metamodel_BON::CurrentSource> getCurrentSource();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Diode> getDiode();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Element> getElement();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Inductor> getInductor();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Resistor> getResistor();
	virtual std::set<passive_electrical_circuit_metamodel_BON::VoltageSource> getVoltageSource();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   CapacitorImpl
//*******************************************************************
class CapacitorImpl :
	  public TwoTermElementImpl
{
public:
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


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   CurrentSourceImpl
//*******************************************************************
class CurrentSourceImpl :
	  public BiTermElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   DiodeImpl
//*******************************************************************
class DiodeImpl :
	  public BiTermElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   InductorImpl
//*******************************************************************
class InductorImpl :
	  public TwoTermElementImpl
{
public:
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


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   ResistorImpl
//*******************************************************************
class ResistorImpl :
	  public TwoTermElementImpl
{
public:
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
	virtual std::set<passive_electrical_circuit_metamodel_BON::DiffusionModelReference> getDiffusionModelReference();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   TriTermElementImpl
//*******************************************************************
class TriTermElementImpl :
	  public BiTermElementImpl
	, virtual public ElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Terminal> gettertiary();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   VoltageSourceImpl
//*******************************************************************
class VoltageSourceImpl :
	  public BiTermElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   BFETImpl
//*******************************************************************
class BFETImpl :
	  public TriTermElementImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);


	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   PhysicsModelListImpl
//*******************************************************************
class PhysicsModelListImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// kind and role getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel> getResistanceDiffusionModel();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   ResistanceDiffusionModelImpl
//*******************************************************************
class ResistanceDiffusionModelImpl :
	  virtual public BON::ModelImpl
{
public:
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


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   TerminalImpl
//*******************************************************************
class TerminalImpl :
	  virtual public BON::ModelImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual std::set<passive_electrical_circuit_metamodel_BON::Line> getInLineLinks();
	virtual std::multiset<passive_electrical_circuit_metamodel_BON::Terminal> getLineDsts();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Line> getLineLinks();
	virtual std::multiset<passive_electrical_circuit_metamodel_BON::Terminal> getLineSrcs();
	virtual std::set<passive_electrical_circuit_metamodel_BON::Line> getOutLineLinks();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   LineImpl
//*******************************************************************
class LineImpl :
	  virtual public BON::ConnectionImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// connectionEnd getters
	virtual passive_electrical_circuit_metamodel_BON::Terminal getDst();
	virtual passive_electrical_circuit_metamodel_BON::Terminal getSrc();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


namespace passive_electrical_circuit_metamodel_BON
{
//*******************************************************************
//   C  L  A  S  S   DiffusionModelReferenceImpl
//*******************************************************************
class DiffusionModelReferenceImpl :
	  virtual public BON::ReferenceImpl
{
public:
	virtual void        accept( BON::Visitor *pVisitor);

	//
	// ref getters
	virtual passive_electrical_circuit_metamodel_BON::ResistanceDiffusionModel getResistanceDiffusionModel();

	///BUP
	// add your own members here
	///EUP
}; // class
}  // namespace


///BUP
// add your additional class definitions here
///EUP

#endif // PASSIVE_ELECTRICAL_CIRCUIT_METAMODELBONX_H
