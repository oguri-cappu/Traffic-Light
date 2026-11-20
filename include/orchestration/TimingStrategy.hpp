#pragma once

#include "Common.hpp"

class TimingStrategy {
public:
	virtual ~TimingStrategy() = default;
	virtual int calculateGreenDuration(int carCount) = 0;
	virtual StrategyType getStrategyType()const = 0;
};

class PedestrianPriorityStrategy :public TimingStrategy {
private:
	int baseWalkTime;
	int clearanceExtensionSec;
	int maxWalkHoldTime;
public:
	PedestrianPriorityStrategy(int walkTime, int extSec, int maxHold);
	int calculateGreenDuration(int parallelCarCount)override;
	int extendClearanceIfCrossing(bool stillCrossing);
	StrategyType getStrategyType()const override;
};

class ActuatedTimingStrategy :public TimingStrategy {
private:
	int baseGreenTime;
	int secPerCar;
	int maxGreenTime;
public:
	ActuatedTimingStrategy(int base, int step, int max);
	int calculateGreenDuration(int carCount)override;
	StrategyType getStrategyType()const override;
};

class FixedTimingStrategy :public TimingStrategy {
private:
	int defaultGreenTime;
public:
	FixedTimingStrategy(int duration);
	int calculateGreenDuration(int carCount)override;
	StrategyType getStrategyType()const override;
};