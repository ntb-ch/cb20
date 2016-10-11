#ifndef CH_NTB_CB20SAFETYPROPERTIES_HPP_
#define CH_NTB_CB20SAFETYPROPERTIES_HPP_

#include <eeros/safety/SafetyProperties.hpp>
#include <eeros/hal/HAL.hpp>
#include <eeros/hal/ScalablePeripheralInput.hpp>
	
	class Cb20ControlSystem;
	
	// Define events
	enum {
	  doOff = 1,
	};
	
	// Define levels
	enum {
	  off = 1,
	};
	
	class Cb20SafetyProperties : public eeros::safety::SafetyProperties {

		public:
			Cb20SafetyProperties(Cb20ControlSystem* cs);
			virtual ~Cb20SafetyProperties();
		
			// outputs
			// inputs
		
		private:
			Cb20ControlSystem* controlSys;
	};

	#endif // CH_NTB_CB20SAFETYPROPERTIES_HPP_