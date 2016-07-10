Author: Yijia Zhang

This is an application simulating a working virtual 'brain' which is in a preliminary form of binary signals.
Currently one 'brain' here have nodeNum=100 neurons, neurons are chosen to be randomly connected at the time of initialization.
For every time step, firing neurons send signals to all the directly connected neurons, and the neurons' state at the next time
step is determined by the number of signals it received: if the number is odd, the neuron will fire; if even, the neuron will be silent.
(implemented in Cell::ObserveThink)

A cell is a living creature which itself has a brain. The first neuron of its brain also serves as an eye detecting the environment.
Environment only have 2 states: 1 and 0. The 2nd and 3rd neurons of the brain also serves as muscle neurons, which controls
the movement of the cell.

The world is a large 2-dimensional grid with each grid point being one of the two states: 0 and 1. If a cell move onto a grid of state 1,
it grabs 1 piece of food, increase its NotHunger value, and change the grid value to be 0. The cell will die if it starves, which will
happen when its NotHunger value comes to 0.

A cell can reproduce after a certain time interval if it's not dead. The reproduce procedure will maintain most of the links arrangement
of the original brain, but will also have a small mutability rate.

A lab is an independent world-cell combination that isolate a world and a cell for us to do experiment on the cell's behavior.

version0.3 implements a large number of labs with the same type of world and cells with different neural arrangements when initialized. 
Then we can see the evolution of these cells.

I hope to see some cells will gain the ability to travel far along the 'food trail' through evolution.

===========================================

When the world is initialized, click to begin simulation!

branch singleBrain shows the firing of neurons of a single brain.
branch master/version0.3 shows the cell evolution process.

source code in C++
GUI is implemented with MFC.

===========================================

Network.h   nodeNum initialized here.
			Network class is inherited by Cell.

Cell.h		initNotHunger initialized here.
			Inherited from Network.
			Cell walk decision time range minDelay/maxDelay initialized.

World.cpp	Initial setup of world in World(). Three different initial configuration can be chosen.

BinaryNetwork0.1Doc.cpp    Parameter initialization in CBinaryNetwork01Doc().

BinaryNetwork0.1View.cpp   Beginning screen and updateWindow() results are set in OnDraw().
						   Main function is implemented in OnLButtonDown().
						   OnKeyDown() is the results of on-step-move, without reproduction.

BinaryNetwork0.1View.h	   Display attributes are defined here.
