#include <cb20/Hardware.hpp>
#include <eeros/hal/HAL.hpp>
#include <cb20/constants.hpp>

using namespace cb20;

namespace {
	namespace Subdevice {
		enum {
			pwm = 0,
			fqd = 1,
			dac = 2,
			gpio = 4,
			ready_enable = 5
		};
	}
}

Hardware::Hardware() :
	device("/dev/flink0"),
	
	dac1("dac1", &device, Subdevice::dac, 0, dac1Scale, dac1Offset),
	dac2("dac2", &device, Subdevice::dac, 1, dac2Scale, dac2Offset),
	dac3("dac3", &device, Subdevice::dac, 2, dac3Scale, dac3Offset),
	dac4("dac4", &device, Subdevice::dac, 3, dac4Scale, dac4Offset),
	dac5("dac5", &device, Subdevice::dac, 4, dac5Scale, dac5Offset),
	dac6("dac6", &device, Subdevice::dac, 5, dac6Scale, dac6Offset),
	dac7("dac7", &device, Subdevice::dac, 6, dac7Scale, dac7Offset),
	dac8("dac8", &device, Subdevice::dac, 7, dac8Scale, dac8Offset),
	
	enableDrv("enableDrv", &device, Subdevice::ready_enable, 0),
	readySig1("readySig1", &device, Subdevice::ready_enable, 1),
	readySig2("readySig2", &device, Subdevice::ready_enable, 2),
	readySig3("readySig3", &device, Subdevice::ready_enable, 3),
	readySig4("readySig4", &device, Subdevice::ready_enable, 4),
	readySig5("readySig5", &device, Subdevice::ready_enable, 5),
	readySig6("readySig6", &device, Subdevice::ready_enable, 6),
	readySig7("readySig7", &device, Subdevice::ready_enable, 7),
	readySig8("readySig8", &device, Subdevice::ready_enable, 8),
	
	enc1("enc1", &device, Subdevice::fqd, 0, -enc1Scale, enc1Offset), 
	enc2("enc2", &device, Subdevice::fqd, 1, -enc2Scale, enc2Offset),
	enc3("enc3", &device, Subdevice::fqd, 2, -enc3Scale, enc3Offset),
	enc4("enc4", &device, Subdevice::fqd, 3, -enc4Scale, enc4Offset),
	enc5("enc5", &device, Subdevice::fqd, 4, -enc5Scale, enc5Offset),
	enc6("enc6", &device, Subdevice::fqd, 5, -enc6Scale, enc6Offset),
	enc7("enc7", &device, Subdevice::fqd, 6, -enc7Scale, enc7Offset),
	enc8("enc8", &device, Subdevice::fqd, 7, -enc8Scale, enc8Offset),
	
	io1("io1", &device, Subdevice::gpio, 0),
	io2("io2", &device, Subdevice::gpio, 1),
	io3("io3", &device, Subdevice::gpio, 2),
	io4("io4", &device, Subdevice::gpio, 3),
	io5("io5", &device, Subdevice::gpio, 4),
	io6("io6", &device, Subdevice::gpio, 5),
	io7("io7", &device, Subdevice::gpio, 6),
	io8("io8", &device, Subdevice::gpio, 7),
	
	pwm1("pwm1", &device, Subdevice::pwm, 0),
	pwm2("pwm2", &device, Subdevice::pwm, 1),
	pwm3("pwm3", &device, Subdevice::pwm, 2),
	pwm4("pwm4", &device, Subdevice::pwm, 3),
	pwm5("pwm5", &device, Subdevice::pwm, 4),
	pwm6("pwm6", &device, Subdevice::pwm, 5),
	pwm7("pwm7", &device, Subdevice::pwm, 6),
	pwm8("pwm8", &device, Subdevice::pwm, 7)
{
	using namespace eeros::hal;
	
	HAL& hal = HAL::instance();
	hal.addPeripheralOutput(&dac1);
	hal.addPeripheralOutput(&dac2);
	hal.addPeripheralOutput(&dac3);
	hal.addPeripheralOutput(&dac4);
	hal.addPeripheralOutput(&dac5);
	hal.addPeripheralOutput(&dac6);
	hal.addPeripheralOutput(&dac7);
	hal.addPeripheralOutput(&dac8);
	
	dac1.set(0.0);
	dac2.set(0.0);
	dac3.set(0.0);
	dac4.set(0.0);
	dac5.set(0.0);
	dac6.set(0.0);
	dac7.set(0.0);
	dac8.set(0.0);

	hal.addPeripheralOutput(&enableDrv);
	hal.addPeripheralOutput(&readySig1);
	hal.addPeripheralOutput(&readySig2);
	hal.addPeripheralOutput(&readySig3);
	hal.addPeripheralOutput(&readySig4);
	hal.addPeripheralOutput(&readySig5);
	hal.addPeripheralOutput(&readySig6);
	hal.addPeripheralOutput(&readySig7);
	hal.addPeripheralOutput(&readySig8);
	
	hal.addPeripheralInput(&enc1);
	hal.addPeripheralInput(&enc2);
	hal.addPeripheralInput(&enc3);
	hal.addPeripheralInput(&enc4);
	hal.addPeripheralInput(&enc5);
	hal.addPeripheralInput(&enc6);
	hal.addPeripheralInput(&enc7);
	hal.addPeripheralInput(&enc8);
	
	hal.addPeripheralOutput(&io1);
	hal.addPeripheralOutput(&io2);
	hal.addPeripheralOutput(&io3);
	hal.addPeripheralOutput(&io4);
	hal.addPeripheralOutput(&io5);
	hal.addPeripheralOutput(&io6);
	hal.addPeripheralOutput(&io7);
	hal.addPeripheralOutput(&io8);
	
	hal.addPeripheralOutput(&pwm1);
	hal.addPeripheralOutput(&pwm2);
	hal.addPeripheralOutput(&pwm3);
	hal.addPeripheralOutput(&pwm4);
	hal.addPeripheralOutput(&pwm5);
	hal.addPeripheralOutput(&pwm6);
	hal.addPeripheralOutput(&pwm7);
	hal.addPeripheralOutput(&pwm8);
	pwm1.setFrequency(100);
	pwm2.setFrequency(100);
	pwm3.setFrequency(100);
	pwm4.setFrequency(100);
	pwm5.setFrequency(100);
	pwm6.setFrequency(100);
	pwm7.setFrequency(100);
	pwm8.setFrequency(100);
}
