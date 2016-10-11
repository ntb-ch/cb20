#include "Cb20ControlSystem.hpp"
#include <eeros/core/Executor.hpp>
#include <iostream>

using namespace eeros::control;

Cb20ControlSystem::Cb20ControlSystem(double ts) :
	
	setPos(),
	timedomain("Main time domain", ts, true)
{
	
	timedomain.addBlock(&setPos);
	
	eeros::task::Periodic td("control system",ts, timedomain);
	eeros::Executor::instance().add(timedomain);
}

Cb20ControlSystem::~Cb20ControlSystem(){
}

