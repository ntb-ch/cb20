#ifndef CH_NTB_CB20CONTROLSYSTEM_HPP_
#define CH_NTB_CB20CONTROLSYSTEM_HPP_

#include <eeros/core/Runnable.hpp>
#include <eeros/control/TimeDomain.hpp>
#include <eeros/control/Constant.hpp>

class Cb20ControlSystem {
  
public:
	Cb20ControlSystem(double ts);
	virtual ~Cb20ControlSystem();
	
	eeros::control::Constant<int> setPos;
	eeros::control::TimeDomain timedomain;
  
private:
	// ...
};

#endif // CH_NTB_CB20CONTROLSYSTEM_HPP_