#ifndef CB11_TEST_HPP_
#define CB11_TEST_HPP_

#include <eeros/control/PeripheralOutput.hpp>
#include <eeros/control/PeripheralInput.hpp>
#include <eeros/control/Constant.hpp>
#include <eeros/control/TimeDomain.hpp>
#include <eeros/hal/HAL.hpp>
#include <eeros/core/Executor.hpp>
#include <eeros/sequencer/Sequence.hpp>
#include <eeros/sequencer/Sequencer.hpp>
#include <unistd.h>

using namespace eeros::safety;
using namespace eeros::control;
using namespace eeros::sequencer;
using namespace eeros::hal;

const double dt = 0.001;

class TestSafetyProperties : public SafetyProperties {
public:
	TestSafetyProperties() : slSingle("single level") {
		addLevel(slSingle);
		setEntryLevel(slSingle);
	}
	SafetyLevel slSingle;
};

class MainSequence : public Sequence {
public:
	MainSequence(Sequencer& sequencer) : Sequence("main", sequencer) {
		hal.callOutputFeature(&pwm1, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm2, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm3, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm4, "setPwmFrequency", 100.0);
		dac1.set(0.1);
		dac2.set(0.1);
		dac3.set(0.1);
		dac4.set(0.1);
		enableDrv.set(true);
	}
	
	int action() {
		int cnt = 0;
		pwm1.set(0.1);
		pwm2.set(0.2);
		pwm3.set(0.3);
		pwm4.set(0.4);
		
		while (Sequencer::running) {
			if(cnt%10 == 0){
				// GPIO
				io1.set(!io1.get());
				io4.set(!io4.get());
				readySig3.set(!readySig3.get());
			}
			if(cnt%15 == 0){
				io2.set(!io2.get());
				io5.set(!io5.get());
				readySig1.set(!readySig1.get());
				readySig4.set(!readySig4.get());
			}
			if(cnt%20 == 0){
				io3.set(!io3.get());
				io6.set(!io6.get());
				readySig2.set(!readySig2.get());
			}
			if(cnt%100 == 0){
				log.info() << enc1.get() << "\t" << enc2.get() << "\t"
				<< enc3.get() << "\t" << enc4.get();
			}
			
			if((dac1val+=0.5) > 10.0) dac1val = -10.0;
			dac1.set(dac1val);
			if((dac2val+=1.0) > 10.0) dac2val = -10.0;
			dac2.set(dac2val);
			if((dac3val+=0.4) > 10.0) dac3val = -10.0;
			dac3.set(dac3val);
			if((dac4val+=0.8) > 10.0) dac4val = -10.0;
			dac4.set(dac4val);
			
			cnt++;
			usleep(10000);
		}
	}
	
private:
	HAL& hal = HAL::instance();
	eeros::hal::Output<bool>& io1 = *hal.getLogicOutput("io1");
	eeros::hal::Output<bool>& io2 = *hal.getLogicOutput("io2");
	eeros::hal::Output<bool>& io3 = *hal.getLogicOutput("io3");
	eeros::hal::Output<bool>& io4 = *hal.getLogicOutput("io4");
	eeros::hal::Output<bool>& io5 = *hal.getLogicOutput("io5");
	eeros::hal::Output<bool>& io6 = *hal.getLogicOutput("io6");
	eeros::hal::Output<double>& pwm1 = *hal.getScalableOutput("pwm1");
	eeros::hal::Output<double>& pwm2 = *hal.getScalableOutput("pwm2");
	eeros::hal::Output<double>& pwm3 = *hal.getScalableOutput("pwm3");
	eeros::hal::Output<double>& pwm4 = *hal.getScalableOutput("pwm4");
	eeros::hal::Output<double>& dac1 = *hal.getScalableOutput("dac1");
	eeros::hal::Output<double>& dac2 = *hal.getScalableOutput("dac2");
	eeros::hal::Output<double>& dac3 = *hal.getScalableOutput("dac3");
	eeros::hal::Output<double>& dac4 = *hal.getScalableOutput("dac4");
	eeros::hal::Output<bool>& enableDrv = *hal.getLogicOutput("enableDrv");
	// the ready signals are inputs when connected to drives
	// for testing purposes we configure them as outputs 
	eeros::hal::Output<bool>& readySig1 = *hal.getLogicOutput("readySig1");
	eeros::hal::Output<bool>& readySig2 = *hal.getLogicOutput("readySig2");
	eeros::hal::Output<bool>& readySig3 = *hal.getLogicOutput("readySig3");
	eeros::hal::Output<bool>& readySig4 = *hal.getLogicOutput("readySig4");
	eeros::hal::Input<double>& enc1 = *hal.getScalableInput("enc1");
	eeros::hal::Input<double>& enc2 = *hal.getScalableInput("enc2");
	eeros::hal::Input<double>& enc3 = *hal.getScalableInput("enc3");
	eeros::hal::Input<double>& enc4 = *hal.getScalableInput("enc4");
	double dac1val = 0.0;
	double dac2val = 0.0;
	double dac3val = 0.0;
	double dac4val = 0.0;
};

#endif // CB11_TEST_HPP_
