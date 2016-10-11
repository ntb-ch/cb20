#ifndef CH_NTB_CB20LIB_CONSTANTS_HPP_
#define CH_NTB_CB20LIB_CONSTANTS_HPP_

namespace cb20{
  
	// DACs offsets
	static constexpr double dacResolution = 65535;
	
	static constexpr double dac1min = -9.761;
	static constexpr double dac1max =  9.899;
	static constexpr double dac1lsbs = (dac1max - dac1min) / (64000.0 - 2000);
	static constexpr double x1min = 2000 - (dac1min + 10.0) / dac1lsbs;
	static constexpr double x1max = 64000 - (dac1max - 10.0) / dac1lsbs;
	static constexpr double m1 = (x1max - x1min) / (2 * 10.0);
	static constexpr double dac1Scale  = 1.0 / m1;
	static constexpr double dac1Offset = -(10.0 + x1min / m1);
	
	static constexpr double dac2min = -9.882;
	static constexpr double dac2max =  9.766;
	static constexpr double dac2lsbs = (dac2max - dac2min) / (64000.0 - 2000);
	static constexpr double x2min = 2000 - (dac2min + 10.0) / dac2lsbs;
	static constexpr double x2max = 64000 - (dac2max - 10.0) / dac2lsbs;
	static constexpr double m2 = (x2max - x2min) / (2 * 10.0);
	static constexpr double dac2Scale  = 1.0 / m2;
	static constexpr double dac2Offset = - (10.0 + x2min / m2);
	
	static constexpr double dac3min = -9.760;
	static constexpr double dac3max =  9.879;
	static constexpr double dac3lsbs = (dac3max - dac3min) / (64000.0 - 2000);
	static constexpr double x3min = 2000 - (dac3min + 10.0) / dac3lsbs;
	static constexpr double x3max = 64000 - (dac3max - 10.0) / dac3lsbs;
	static constexpr double m3 = (x3max - x3min) / (2 * 10.0);
	static constexpr double dac3Scale  = 1.0 / m3;
	static constexpr double dac3Offset = - (10.0 + x3min / m3);
	
	static constexpr double dac4min = -9.821;
	static constexpr double dac4max =  9.756;
	static constexpr double dac4lsbs = (dac4max - dac4min) / (64000.0 - 2000);
	static constexpr double x4min = 2000 - (dac4min + 10.0) / dac4lsbs;
	static constexpr double x4max = 64000 - (dac4max - 10.0) / dac4lsbs;
	static constexpr double m4 = (x4max - x4min) / (2 * 10.0);
	static constexpr double dac4Scale  = 1.0 / m4;
	static constexpr double dac4Offset = - (10.0 + x4min / m4);
	
	static constexpr double dac5min = -9.772;
	static constexpr double dac5max =  9.879;
	static constexpr double dac5lsbs = (dac5max - dac5min) / (64000.0 - 2000);
	static constexpr double x5min = 2000 - (dac5min + 10.0) / dac5lsbs;
	static constexpr double x5max = 64000 - (dac5max - 10.0) / dac5lsbs;
	static constexpr double m5 = (x5max - x5min) / (2 * 10.0);
	static constexpr double dac5Scale  = 1.0 / m5;
	static constexpr double dac5Offset = - (10.0 + x5min / m5);
	
	static constexpr double dac6min = -9.715;
	static constexpr double dac6max =  9.972;
	static constexpr double dac6lsbs = (dac6max - dac6min) / (64000.0 - 2000);
	static constexpr double x6min = 2000 - (dac6min + 10.0) / dac6lsbs;
	static constexpr double x6max = 64000 - (dac6max - 10.0) / dac6lsbs;
	static constexpr double m6 = (x6max - x6min) / (2 * 10.0);
	static constexpr double dac6Scale  = 1.0 / m6;
	static constexpr double dac6Offset = - (10.0 + x6min / m6);
	
	static constexpr double dac7min = -9.820;
	static constexpr double dac7max =  9.808;
	static constexpr double dac7lsbs = (dac7max - dac7min) / (64000.0 - 2000);
	static constexpr double x7min = 2000 - (dac7min + 10.0) / dac7lsbs;
	static constexpr double x7max = 64000 - (dac7max - 10.0) / dac7lsbs;
	static constexpr double m7 = (x7max - x7min) / (2 * 10.0);
	static constexpr double dac7Scale  = 1.0 / m7;
	static constexpr double dac7Offset = - (10.0 + x7min / m7);
	
	static constexpr double dac8min = -9.653;
	static constexpr double dac8max =  9.964;
	static constexpr double dac8lsbs = (dac8max - dac8min) / (64000.0 - 2000);
	static constexpr double x8min = 2000 - (dac8min + 10.0) / dac8lsbs;
	static constexpr double x8max = 64000 - (dac8max - 10.0) / dac8lsbs;
	static constexpr double m8 = (x8max - x8min) / (2 * 10.0);
	static constexpr double dac8Scale  = 1.0 / m8;
	static constexpr double dac8Offset = - (10.0 + x8min / m8);
	
	static constexpr double enc1Scale = 1;
	static constexpr double enc2Scale = 1;
	static constexpr double enc3Scale = 1;
	static constexpr double enc4Scale = 1;
	static constexpr double enc5Scale = 1;
	static constexpr double enc6Scale = 1;
	static constexpr double enc7Scale = 1;
	static constexpr double enc8Scale = 1;
	
	static constexpr double enc1Offset = 0.0;
	static constexpr double enc2Offset = 0.0;
	static constexpr double enc3Offset = 0.0;
	static constexpr double enc4Offset = 0.0;
	static constexpr double enc5Offset = 0.0;
	static constexpr double enc6Offset = 0.0;
	static constexpr double enc7Offset = 0.0;
	static constexpr double enc8Offset = 0.0;

}
#endif
