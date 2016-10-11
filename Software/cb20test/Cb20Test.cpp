#include <iostream>
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include <eeros/core/Executor.hpp>
#include "control/Cb20ControlSystem.hpp"
#include "safety/Cb20SafetyProperties.hpp"
#include "sequences/Cb20TestMainSequence.hpp"
#include <signal.h>
#include <unistd.h>
#include <eeros/hal/HAL.hpp>

#include <cb20/Hardware.hpp>

using namespace eeros;
using namespace eeros::logger;
using namespace eeros::control;
using namespace eeros::safety;
using namespace eeros::sequencer;

using namespace cb20;

volatile bool running = true;
const double dt = 0.001;

void signalHandler(int signum){
	running = false;
}

int main() {
	signal(SIGINT, signalHandler);
      
	StreamLogWriter w(std::cout);
	Logger<LogWriter>::setDefaultWriter(&w);
	Logger<LogWriter> log;
	Cb20ControlSystem* cb20CtrlSys; 

	w.show();
	
	log.info() << "Cb20 Testing...";
	  
	Hardware hw;
// 	eeros::hal::HAL& hal = eeros::hal::HAL::instance();
	
	cb20CtrlSys = new Cb20ControlSystem(dt);
		
	// Create safety system
	Cb20SafetyProperties safetyProperties(cb20CtrlSys);
	SafetySystem safetySystem(safetyProperties, dt);
	
	// Sequencer
	Sequencer sequencer;
	Cb20TestMainSequence mainSequence(&sequencer, cb20CtrlSys, &safetySystem);
	sequencer.start(&mainSequence);
	
	// Set executor & create safety system
	auto &executor = Executor::instance();
	executor.setPeriod(dt);
	executor.setMainTask(safetySystem);
	
	// Start control system
	executor.run();
	
	sequencer.shutdown();
	usleep(3);
	if(sequencer.getState()!=state::terminated) {
		sequencer.abort();
	}
// 	while(sequencer.getState()!=state::terminated){
// 		usleep(100000);
// 		std::cout << ".";
// 	}
	
	log.info() << "Shuting down...";
		
	return 0;
}
