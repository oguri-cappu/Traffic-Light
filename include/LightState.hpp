#pragma once
#include "Common.hpp"

class TrafficLight; 

class LightState {
public:
	virtual ~LightState() = default;
	virtual void handleTick(TrafficLight& context) = 0;
	virtual LightStateEnum getStateEnum() const = 0;
};