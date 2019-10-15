# cb20
Controller Board with Processor Module Toradex Colibri iMX6

## Documentation
- Hardware and software: https://wiki.ntb.ch/infoportal/embedded_systems/imx6/cb
- Linux on the cb20: https://wiki.ntb.ch/infoportal/software/linux/toradex/start

## FPGA Designs
There are two standard FPGA designs in the repository:
* standard: design with encoder inputs, DAC, PWM outputs and some digital I/O pins
* spi: design similar to standard design, but there is a SPI interface for the MPU-9250 IMU chip of InvenSense and only 3 PWM channels

## Software
We use the board together with [EEROS Robotics Framework](https://github.com/eeros-project/eeros-framework) and [flink](https://github.com/flink-project).
- Demo application: in this repository under Software/cb20test
- How to use, see [Get Started Using EEROS](https://wiki.eeros.org/getting_started/start)
 
