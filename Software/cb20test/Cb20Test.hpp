#ifndef CB20_TEST_HPP_
#define CB20_TEST_HPP_

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

class MySafetyProperties : public SafetyProperties {
public:
	MySafetyProperties() : slSingle("single level") {
		addLevel(slSingle);
		setEntryLevel(slSingle);
	}
	virtual ~MySafetyProperties() { }
	SafetyLevel slSingle;
};

class MyMainSequence : public Sequence<> {
public:
	MyMainSequence(Sequencer* sequencer) : Sequence<void>("main", sequencer) {
		hal.callOutputFeature(&pwm1, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm2, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm3, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm4, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm5, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm6, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm7, "setPwmFrequency", 100.0);
		hal.callOutputFeature(&pwm8, "setPwmFrequency", 100.0);
		dac1.set(0);
		dac2.set(0);
		dac3.set(0);
		dac4.set(0);
		dac5.set(0);
		dac6.set(0);
		dac7.set(0);
		dac8.set(0);
	}
	
	virtual bool checkPreCondition() {return true;}
	virtual void run() {
		log.trace() << "[ Main Sequence Started ]";
		int cnt = 0;
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
				log.info() << enc1.get() << "\t" << enc2.get() << "\t"
				<< enc3.get() << "\t" << enc4.get() << "\t" << enc5.get() << "\t" 
				<< enc6.get() << "\t" << enc7.get() << "\t" << enc8.get();
			}
			
			if((dac1val+=0.5) > 10.0) dac1val = -10.0;
			dac1.set(dac1val);
			if((dac2val+=1.0) > 10.0) dac2val = -10.0;
			dac2.set(dac2val);
			if((dac3val+=0.4) > 10.0) dac3val = -10.0;
			dac3.set(dac3val);
			if((dac4val+=0.8) > 10.0) dac4val = -10.0;
			dac4.set(dac4val);
			if((dac5val+=0.5) > 10.0) dac5val = -10.0;
			dac5.set(dac5val);
			if((dac6val+=0.2) > 10.0) dac6val = -10.0;
			dac6.set(dac6val);
			if((dac7val+=0.6) > 10.0) dac7val = -10.0;
			dac7.set(dac7val);
			if((dac8val+= 0.8) > 10.0) dac8val = -10.0;
			dac8.set(dac8val);
			
			usleep(10000);
		}
	}

	virtual void exit() {log.info() << "[ Exit Main Sequence ]";}
	
private:
	inline bool isTerminating() {return sequencer->getState() == state::terminating;}
	HAL& hal = HAL::instance();
	eeros::hal::Output<bool>& io1 = *hal.getLogicOutput("io1");
	eeros::hal::Output<bool>& io2 = *hal.getLogicOutput("io2");
	eeros::hal::Output<bool>& io3 = *hal.getLogicOutput("io3");
	eeros::hal::Output<bool>& io4 = *hal.getLogicOutput("io4");
	eeros::hal::Output<bool>& io5 = *hal.getLogicOutput("io5");
	eeros::hal::Output<bool>& io6 = *hal.getLogicOutput("io6");
	eeros::hal::Output<bool>& io7 = *hal.getLogicOutput("io7");
	eeros::hal::Output<bool>& io8 = *hal.getLogicOutput("io8");
	eeros::hal::Output<double>& pwm1 = *hal.getScalableOutput("pwm1");
	eeros::hal::Output<double>& pwm2 = *hal.getScalableOutput("pwm2");
	eeros::hal::Output<double>& pwm3 = *hal.getScalableOutput("pwm3");
	eeros::hal::Output<double>& pwm4 = *hal.getScalableOutput("pwm4");
	eeros::hal::Output<double>& pwm5 = *hal.getScalableOutput("pwm5");
	eeros::hal::Output<double>& pwm6 = *hal.getScalableOutput("pwm6");
	eeros::hal::Output<double>& pwm7 = *hal.getScalableOutput("pwm7");
	eeros::hal::Output<double>& pwm8 = *hal.getScalableOutput("pwm8");
	eeros::hal::Output<double>& dac1 = *hal.getScalableOutput("dac1");
	eeros::hal::Output<double>& dac2 = *hal.getScalableOutput("dac2");
	eeros::hal::Output<double>& dac3 = *hal.getScalableOutput("dac3");
	eeros::hal::Output<double>& dac4 = *hal.getScalableOutput("dac4");
	eeros::hal::Output<double>& dac5 = *hal.getScalableOutput("dac5");
	eeros::hal::Output<double>& dac6 = *hal.getScalableOutput("dac6");
	eeros::hal::Output<double>& dac7 = *hal.getScalableOutput("dac7");
	eeros::hal::Output<double>& dac8 = *hal.getScalableOutput("dac8");
	eeros::hal::Output<bool>& enableDrv = *hal.getLogicOutput("enableDrv");
	// the ready signals are inputs when connected to drives
	// for testing purposes we configure them as outputs 
	eeros::hal::Output<bool>& readySig1 = *hal.getLogicOutput("readySig1");
	eeros::hal::Output<bool>& readySig2 = *hal.getLogicOutput("readySig2");
	eeros::hal::Output<bool>& readySig3 = *hal.getLogicOutput("readySig3");
	eeros::hal::Output<bool>& readySig4 = *hal.getLogicOutput("readySig4");
	eeros::hal::Output<bool>& readySig5 = *hal.getLogicOutput("readySig5");
	eeros::hal::Output<bool>& readySig6 = *hal.getLogicOutput("readySig6");
	eeros::hal::Output<bool>& readySig7 = *hal.getLogicOutput("readySig7");
	eeros::hal::Output<bool>& readySig8 = *hal.getLogicOutput("readySig8");
	eeros::hal::Input<double>& enc1 = *hal.getScalableInput("enc1");
	eeros::hal::Input<double>& enc2 = *hal.getScalableInput("enc2");
	eeros::hal::Input<double>& enc3 = *hal.getScalableInput("enc3");
	eeros::hal::Input<double>& enc4 = *hal.getScalableInput("enc4");
	eeros::hal::Input<double>& enc5 = *hal.getScalableInput("enc5");
	eeros::hal::Input<double>& enc6 = *hal.getScalableInput("enc6");
	eeros::hal::Input<double>& enc7 = *hal.getScalableInput("enc7");
	eeros::hal::Input<double>& enc8 = *hal.getScalableInput("enc8");
	double dac1val = 0.0;
	double dac2val = 0.0;
	double dac3val = 0.0;
	double dac4val = 0.0;
	double dac5val = 0.0;
	double dac6val = 0.0;
	double dac7val = 0.0;
	double dac8val = 0.0;
};

#endif // CB20_TEST_HPP_
