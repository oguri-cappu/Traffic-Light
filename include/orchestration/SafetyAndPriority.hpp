#pragma once

#include "Common.hpp"
#include "signaling/Phase.hpp"
#include <string>
#include <vector>

class DilemmaZoneProtectionStrategy {
private:
	int yellowDurationSeconds;
	double speedThresholdMps;
public:
	DilemmaZoneProtectionStrategy(int yellowTime, double speedThresh);
	bool checkDilemmaZoneHazard(double speed, double distance);
};

class EmergencyPriorityHandler {
private:
	bool preEmptionActive;
	int savedPhaseId;
public:
	EmergencyPriorityHandler();
	void handleEmergencyPreemtion(std::string triggerLaneId, std::vector<Phase*>& managedPhases);
};

