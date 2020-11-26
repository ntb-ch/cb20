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

void signalHandler(int signum) {
	Sequencer::instance().abort();
}

int main(int argc, char **argv){
  Logger::setDefaultStreamLogger(std::cout);
  Logger log = Logger::getLogger();
  log.show();
	
	log.info() << "Cb20 Testing...";
	  
	HAL::instance().readConfigFromFile(&argc, argv);

	// Create safety system
	TestSafetyProperties sp;
	SafetySystem ss(sp, dt);
	
	// Sequencer
	auto& seq = Sequencer::instance();
	MainSequence mainSequence(seq);
	mainSequence();
	
	// Set executor & create safety system
	auto &executor = Executor::instance();
	executor.setMainTask(ss);
	executor.run();
	
	seq.wait();
	
	log.info() << "Test end...";
		
	return 0;
}
