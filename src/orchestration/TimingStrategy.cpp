#include "orchestration/TimingStrategy.hpp"

//Pedestrian Strategy
PedestrianPriorityStrategy::PedestrianPriorityStrategy(int walkTime, int extSec, int maxHold)
	:baseWalkTime(walkTime), clearanceExtensionSec(extSec), maxWalkHoldTime(maxHold) {}

int PedestrianPriorityStrategy::calculateGreenDuration(int parallelCarCount) {
	int adjustedDuration;
	if (parallelCarCount > 0) adjustedDuration = baseWalkTime + parallelCarCount;
	else adjustedDuration = baseWalkTime;

	if (adjustedDuration > maxWalkHoldTime) return maxWalkHoldTime;
	return adjustedDuration;
}

int PedestrianPriorityStrategy::extendClearanceIfCrossing(bool isStllCrossing) {
	if (!isStllCrossing) return 0;
	return clearanceExtensionSec;
}

StrategyType PedestrianPriorityStrategy::getStrategyType()const {
	return StrategyType::PEDESTRIAN_PRIORITY;
}

//Actuated Strategy
ActuatedTimingStrategy::ActuatedTimingStrategy(int base, int step, int max)
	:baseGreenTime(base), secPerCar(step), maxGreenTime(max) {}

int ActuatedTimingStrategy::calculateGreenDuration(int carCount) {
	int adjustedDuration;
	if (carCount <= 0) return 0;
	adjustedDuration = carCount * secPerCar;
	if (adjustedDuration > maxGreenTime) return maxGreenTime;
	return adjustedDuration;
}

StrategyType ActuatedTimingStrategy::getStrategyType()const {
	return StrategyType::ACTUATUED;
}

//Fixed Strategy
FixedTimingStrategy::FixedTimingStrategy(int duration)
	:defaultGreenTime(duration) {}

int FixedTimingStrategy::calculateGreenDuration(int carCount) {
	return defaultGreenTime;
}

StrategyType FixedTimingStrategy::getStrategyType()const {
	return StrategyType::FIXED_TIME;
}