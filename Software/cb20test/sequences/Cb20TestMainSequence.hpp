#ifndef CH_NTB_CB20TESTMAINSEQUENCE_HPP_
#define CH_NTB_CB20TESTMAINSEQUENCE_HPP_

#include <eeros/sequencer/Sequence.hpp>
#include <eeros/safety/SafetySystem.hpp>
#include "../control/Cb20ControlSystem.hpp"
#include <eeros/hal/HAL.hpp>
#include <eeros/hal/PeripheralOutput.hpp>

class Cb20TestMainSequence : public eeros::sequencer::Sequence<void> {

public:
	Cb20TestMainSequence(eeros::sequencer::Sequencer* sequencer, Cb20ControlSystem* controlSys, eeros::safety::SafetySystem* safetySys);
	
	virtual bool checkPreCondition();
	virtual void run();
	virtual void exit();
	
private:
	eeros::hal::HAL& hal = eeros::hal::HAL::instance();
	bool isTerminating();
	
	Cb20ControlSystem* controlSys;
	eeros::safety::SafetySystem* safetySys;
	
	eeros::hal::PeripheralOutput<bool> &io1 = *hal.getLogicPeripheralOutput("io1");
	eeros::hal::PeripheralOutput<bool> &io2 = *hal.getLogicPeripheralOutput("io2");
	eeros::hal::PeripheralOutput<bool> &io3 = *hal.getLogicPeripheralOutput("io3");
	eeros::hal::PeripheralOutput<bool> &io4 = *hal.getLogicPeripheralOutput("io4");
	eeros::hal::PeripheralOutput<bool> &io5 = *hal.getLogicPeripheralOutput("io5");
	eeros::hal::PeripheralOutput<bool> &io6 = *hal.getLogicPeripheralOutput("io6");
	eeros::hal::PeripheralOutput<bool> &io7 = *hal.getLogicPeripheralOutput("io7");
	eeros::hal::PeripheralOutput<bool> &io8 = *hal.getLogicPeripheralOutput("io8");
	
	eeros::hal::PeripheralOutput<double> &pwm1 = *hal.getRealPeripheralOutput("pwm1");
	eeros::hal::PeripheralOutput<double> &pwm2 = *hal.getRealPeripheralOutput("pwm2");
	eeros::hal::PeripheralOutput<double> &pwm3 = *hal.getRealPeripheralOutput("pwm3");
	eeros::hal::PeripheralOutput<double> &pwm4 = *hal.getRealPeripheralOutput("pwm4");
	eeros::hal::PeripheralOutput<double> &pwm5 = *hal.getRealPeripheralOutput("pwm5");
	eeros::hal::PeripheralOutput<double> &pwm6 = *hal.getRealPeripheralOutput("pwm6");
	eeros::hal::PeripheralOutput<double> &pwm7 = *hal.getRealPeripheralOutput("pwm7");
	eeros::hal::PeripheralOutput<double> &pwm8 = *hal.getRealPeripheralOutput("pwm8");
		
	eeros::hal::PeripheralOutput<bool> &enableDrv = *hal.getLogicPeripheralOutput("enableDrv");
	eeros::hal::PeripheralOutput<bool> &readySig1 = *hal.getLogicPeripheralOutput("readySig1");
	eeros::hal::PeripheralOutput<bool> &readySig2 = *hal.getLogicPeripheralOutput("readySig2");
	eeros::hal::PeripheralOutput<bool> &readySig3 = *hal.getLogicPeripheralOutput("readySig3");
	eeros::hal::PeripheralOutput<bool> &readySig4 = *hal.getLogicPeripheralOutput("readySig4");
	eeros::hal::PeripheralOutput<bool> &readySig5 = *hal.getLogicPeripheralOutput("readySig5");
	eeros::hal::PeripheralOutput<bool> &readySig6 = *hal.getLogicPeripheralOutput("readySig6");
	eeros::hal::PeripheralOutput<bool> &readySig7 = *hal.getLogicPeripheralOutput("readySig7");
	eeros::hal::PeripheralOutput<bool> &readySig8 = *hal.getLogicPeripheralOutput("readySig8");
	
	eeros::hal::PeripheralOutput<double> &dac1 = *hal.getRealPeripheralOutput("dac1");
	eeros::hal::PeripheralOutput<double> &dac2 = *hal.getRealPeripheralOutput("dac2");
	eeros::hal::PeripheralOutput<double> &dac3 = *hal.getRealPeripheralOutput("dac3");
	eeros::hal::PeripheralOutput<double> &dac4 = *hal.getRealPeripheralOutput("dac4");
	eeros::hal::PeripheralOutput<double> &dac5 = *hal.getRealPeripheralOutput("dac5");
	eeros::hal::PeripheralOutput<double> &dac6 = *hal.getRealPeripheralOutput("dac6");
	eeros::hal::PeripheralOutput<double> &dac7 = *hal.getRealPeripheralOutput("dac7");
	eeros::hal::PeripheralOutput<double> &dac8 = *hal.getRealPeripheralOutput("dac8");
	
	double dac1val = 0.0;
	double dac2val = 0.0;
	double dac3val = 0.0;
	double dac4val = 0.0;
	double dac5val = 0.0;
	double dac6val = 0.0;
	double dac7val = 0.0;
	double dac8val = 0.0;
	
	eeros::hal::PeripheralInput<double> &enc1 = *hal.getRealPeripheralInput("enc1");
	eeros::hal::PeripheralInput<double> &enc2 = *hal.getRealPeripheralInput("enc2");
	eeros::hal::PeripheralInput<double> &enc3 = *hal.getRealPeripheralInput("enc3");
	eeros::hal::PeripheralInput<double> &enc4 = *hal.getRealPeripheralInput("enc4");
	eeros::hal::PeripheralInput<double> &enc5 = *hal.getRealPeripheralInput("enc5");
	eeros::hal::PeripheralInput<double> &enc6 = *hal.getRealPeripheralInput("enc6");
	eeros::hal::PeripheralInput<double> &enc7 = *hal.getRealPeripheralInput("enc7");
	eeros::hal::PeripheralInput<double> &enc8 = *hal.getRealPeripheralInput("enc8");
	
};
		
#endif // CH_NTB_CB20TESTMAINSEQUENCE_HPP_  
