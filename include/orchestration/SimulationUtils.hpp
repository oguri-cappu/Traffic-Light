#pragma once

#include "Common.hpp"
#include <string>

class MetricsLogger {
private:
	std::string logFileName;
	int criticalEventCount;
public:
	MetricsLogger(std::string filename);
	void logTelemetryFrame(int timeTick, std::string id, int count);
	void logFaultAlert(int timeTick, std::string errorMsg);
};

class SimulationClock {
private:
	int currentTick;
	int timeScale;
public:
	SimulationClock();
	void advanceClock();
	int getCurrentTick();
	bool isNightHours();
};