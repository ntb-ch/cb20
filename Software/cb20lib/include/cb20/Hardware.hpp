#ifndef CB20_HARDWARE_HPP_
#define CB20_HARDWARE_HPP_

#include <eeros/hal/FlinkDevice.hpp>
#include <eeros/hal/FlinkAnalogOut.hpp>
#include <eeros/hal/FlinkFqd.hpp>
#include <eeros/hal/FlinkDigOut.hpp>
#include <eeros/hal/FlinkDigIn.hpp>
#include <eeros/hal/FlinkPwm.hpp>

namespace cb20 {
	
    class Hardware {
    public:
		Hardware();
    private:
		eeros::hal::FlinkDevice device;
		
		eeros::hal::FlinkAnalogOut dac1;
		eeros::hal::FlinkAnalogOut dac2;
		eeros::hal::FlinkAnalogOut dac3;
		eeros::hal::FlinkAnalogOut dac4;
		eeros::hal::FlinkAnalogOut dac5;
		eeros::hal::FlinkAnalogOut dac6;
		eeros::hal::FlinkAnalogOut dac7;
		eeros::hal::FlinkAnalogOut dac8;		

		eeros::hal::FlinkDigOut enableDrv;
		eeros::hal::FlinkDigOut readySig1;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig2;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig3;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig4;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig5;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig6;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig7;	// only output for test purposes -> will be FlinkDigIn
		eeros::hal::FlinkDigOut readySig8;	// only output for test purposes -> will be FlinkDigIn
		
		eeros::hal::FlinkFqd enc1;
		eeros::hal::FlinkFqd enc2;
		eeros::hal::FlinkFqd enc3;
		eeros::hal::FlinkFqd enc4;
		eeros::hal::FlinkFqd enc5;
		eeros::hal::FlinkFqd enc6;
		eeros::hal::FlinkFqd enc7;
		eeros::hal::FlinkFqd enc8;
		
		eeros::hal::FlinkDigOut io1;
		eeros::hal::FlinkDigOut io2;
		eeros::hal::FlinkDigOut io3;
		eeros::hal::FlinkDigOut io4;
		eeros::hal::FlinkDigOut io5;
		eeros::hal::FlinkDigOut io6;
		eeros::hal::FlinkDigOut io7;
		eeros::hal::FlinkDigOut io8;
		
		eeros::hal::FlinkPwm pwm1;
		eeros::hal::FlinkPwm pwm2;
		eeros::hal::FlinkPwm pwm3;
		eeros::hal::FlinkPwm pwm4;
		eeros::hal::FlinkPwm pwm5;
		eeros::hal::FlinkPwm pwm6;
		eeros::hal::FlinkPwm pwm7;
		eeros::hal::FlinkPwm pwm8;
    };
}

/*
 * Signal Names:
 * *************
 * 
 * 
 * 
 */

#endif // CB20_HARDWARE_HPP_
