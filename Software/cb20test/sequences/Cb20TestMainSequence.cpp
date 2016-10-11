#include <eeros/safety/SafetySystem.hpp>
#include "Cb20TestMainSequence.hpp"
#include "../control/Cb20ControlSystem.hpp"
#include <unistd.h>
#include <iostream>
#include <eeros/hal/FlinkDigOut.hpp>
#include <eeros/hal/FlinkDigIn.hpp>
#include <eeros/hal/FlinkAnalogOut.hpp>
#include <eeros/hal/FlinkFqd.hpp>
#include <eeros/hal/FlinkPwm.hpp>

using namespace eeros;
using namespace eeros::sequencer;
using namespace eeros::safety;
using namespace eeros::hal;


Cb20TestMainSequence::Cb20TestMainSequence(Sequencer* sequencer, Cb20ControlSystem* controlSys, SafetySystem* safetySys) :
							Sequence<void>("main", sequencer), controlSys(controlSys), safetySys(safetySys) {
	
}

bool Cb20TestMainSequence::checkPreCondition() {
	return true;
}

void Cb20TestMainSequence::run() {
	log.trace() << "[ Main Sequence Started ]";
	
	
	int cnt = 0;
	
	log.info() << "Starting...";
	
	pwm1.set(0.1);
	pwm2.set(0.2);
	pwm3.set(0.3);
	pwm4.set(0.4);
	pwm5.set(0.5);
	pwm6.set(0.6);
	pwm7.set(0.7);
	pwm8.set(0.8);
	
	
	for(cnt = 0; (cnt < 1000000) && (!isTerminating()); cnt++){
	  
		if(cnt%10 == 0){
			// GPIO
			io1.set(!io1.get());
			io4.set(!io4.get());
			io7.set(!io7.get());
			enableDrv.set(!enableDrv.get());
			readySig3.set(!readySig3.get());
			readySig6.set(!readySig6.get());
			
			
		}
		if(cnt%15 == 0){
			io2.set(!io2.get());
			io5.set(!io5.get());
			io8.set(!io8.get());
			readySig1.set(!readySig1.get());
			readySig4.set(!readySig4.get());
			readySig7.set(!readySig7.get());
		}
		if(cnt%20 == 0){
			io3.set(!io3.get());
			io6.set(!io6.get());
			readySig2.set(!readySig2.get());
			readySig5.set(!readySig5.get());
			readySig8.set(!readySig8.get());
		}
		if(cnt%100 == 0){
			std::cout << enc1.get() << "\t" << enc2.get() << "\t"
			<< enc3.get() << "\t" << enc4.get() << "\t" << enc5.get() << "\t" 
			<< enc6.get() << "\t" << enc7.get() << "\t" << enc8.get() << std::endl;
		}
		
		// DAC
		if((dac1val+=0.5) > 10.0){
			dac1val = -10.0;
		}
		dac1.set(dac1val);
		if((dac2val+=1.0) > 10.0){
			dac2val = -10.0;
		}
		dac2.set(dac2val);
		if((dac3val+=0.4) > 10.0){
			dac3val = -10.0;
		}
		dac3.set(dac3val);
		if((dac4val+=0.8) > 10.0){
			dac4val = -10.0;
		}
		dac4.set(dac4val);
		if((dac5val+=0.5) > 10.0){
			dac5val = -10.0;
		}
		dac5.set(dac5val);
		if((dac6val+=0.2) > 10.0){
			dac6val = -10.0;
		}
		dac6.set(dac6val);
		if((dac7val+=0.6) > 10.0){
			dac7val = -10.0;
		}
		dac7.set(dac7val);
		if((dac8val+= 0.8) > 10.0){
			dac8val = -10.0;
		}
		dac8.set(dac8val);
		
		usleep(10000);
	}

}

void Cb20TestMainSequence::exit() {
	log.info() << "[ Exit Main Sequence ]";
}

inline bool Cb20TestMainSequence::isTerminating() {
	return sequencer->getState() == state::terminating;
}
