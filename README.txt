CS 388 Model Integrated Computing

Design and specify a small modeling language using MetaGME.
Create a modeling environment in GME.

Domain:
Passive electrical circuits

For the purposes of this project a passive electrical circuit is 
defined as a circuit consisting of simple electronic elements.
Specifically resistors, capacitors, inductors and some simple solid state elements.
In particular passive elements do not generate power.

This modeling language will take as its target audience the ng-spice circuit simulator.
http://ngspice.sourceforge.net/
With that audience in mind the modeling language will also have
some active elements, namely voltage and current sources.

As this is primarily a learning exercise for GME I have made two extensions.
The language includes a simple ng-spice resistor model.
These resistor models are then referenced by resistors as described in ng-spice.
The language also makes use of component assemblies.
Assemblies simply expose their terminals as ports.
For this reason element terminals are modeled using contained terminal elements
rather than connections.
