# cb20
Controller Board for Toradex Colibri iMX6

## FPGA Designs
There are two standard FPGA designs in the repository:
* standard: design with encoder inputs, DAC, PWM outputs and some digital I/O pins
* spi: design similar to standard design, but there is a SPI interface for the MPU-9250 IMU chip of InvenSense and only 3 PWM channels

## Software
Test software for Colibri iMX6 of Toradex for standard FPGA design.
To build the sources, follow these steps:
 1. clone this repository (cb20.git) and navigate into the Software folder
 1. run clone.sh script
 1. run make.sh script
 1. copy the executable to your target device
 
## Electronics
Contains the Schematic as a PDF file and the Altium Designer files. Also the Pin Mapping for the FPGA is included and the pin layout on the PCB.
