#include "orchestration/SafetyAndPriority.hpp"

//Dilemma Protection
DilemmaZoneProtectionStrategy::DilemmaZoneProtectionStrategy(int yellowTime, double speedThresh)
	: yellowDurationSeconds(yellowTime), speedThresholdMps(speedThresh) {}

bool DilemmaZoneProtectionStrategy::checkDilemmaZoneHazard(double speed, double distance) {
	
}