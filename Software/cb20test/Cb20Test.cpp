#include <iostream>
#include <eeros/logger/Logger.hpp>
#include <eeros/logger/StreamLogWriter.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include <eeros/core/Executor.hpp>
#include <eeros/hal/HAL.hpp>
#include "Cb20Test.hpp"

using namespace eeros;
using namespace eeros::logger;
using namespace eeros::safety;
using namespace eeros::sequencer;

int main(int argc, char **argv){
	StreamLogWriter w(std::cout);
	Logger::setDefaultWriter(&w);
	Logger log;
	w.show();
	
	log.info() << "Cb20 Testing...";
	  
	HAL::instance().readConfigFromFile(&argc, argv);

	// Create safety system
	MySafetyProperties safetyProperties;
	SafetySystem safetySystem(safetyProperties, dt);
	
	// Sequencer
	Sequencer sequencer = Sequencer::instance();
	MyMainSequence mainSequence(sequencer);
	sequencer.addMainSequence(&mainSequence);
	
	// Set executor & create safety system
	auto &executor = Executor::instance();
	executor.setMainTask(safetySystem);
	executor.run();
	
	mainSequence.join();
	
	log.info() << "Test end...";
		
	return 0;
}
