#pragma once

#include "Common.hpp"
#include "orchestration/TimingStrategy.hpp"
#include "orchestration/SafetyAndPriority.hpp"
#include "orchestration/SimulationUtils.hpp"
#include "orchestration/Intersection.hpp"
#include <memory>
#include <string>

class Controller :public IObserver {
private:
	std::unique_ptr<Intersection> targetIntersection;
	std::unique_ptr<TimingStrategy> activeStrategy;
	std::unique_ptr<DilemmaZoneProtectionStrategy> safetyStrategy;
	std::unique_ptr<EmergencyPriorityHandler> emergencyHandler;
	std::unique_ptr<SimulationClock> clock;
	std::unique_ptr<MetricsLogger> diagnostics;
	bool pedestrianCrossRequested;
	bool pedestrianInCrosswalk;
	bool nightModeActive;
	bool failSafeActive;
public:
	Controller(std::unique_ptr<Intersection> intersection);
	void setTimingStrategy(std::unique_ptr<TimingStrategy> newStrategy);
	void setNightMode(bool enabled);
	void update(std::string eventSourceId);
	void stepSimulationClock();
};