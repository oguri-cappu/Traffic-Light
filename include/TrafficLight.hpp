#pragma once

#include<memory>
#include "Common.hpp"
#include "LightState.hpp"

class TrafficLight {
private:
	std::unique_ptr<LightState> currentState;
	int timeElapsedInState{ 0 };
	int redDuration;
	int yellowDuration;
	int greenDuration;
	bool isMalfunctioning{ false };

public:
	TrafficLight(int r, int y, int g); // Three paramaters

	void changeState(std::unique_ptr<LightState> newState);
	void tick();

	LightStateEnum getCurrentColor() const;
	int getTimeElapsed() const;
	void resetStateTimer();
	int getDurationForState(LightStateEnum) const;

	void triggerMalfunction();
	void repairMalfunction();

};

