#pragma once

#include <string>
//#include <vector>
#include <stdexcept>

class IObserver {
public:
	virtual ~IObserver() = default;
	virtual void update(std::string eventSourceID) = 0;
};

class ISubject {
public:
	virtual ~ISubject() = default;
	virtual void registerObserver(IObserver* observer) = 0;
	virtual void removeObserver(IObserver* observer) = 0;
	virtual void notifyObservers() = 0;
};

enum class VehicleType {
	Sedan,
	PublicTransitBus,
	Motorcycle,
	Truck,
	EmergencyVehicle
};

struct VehicleTelemetry {
	double speedMps;
	double distanceMeter;
	double weightTon;
};

enum class LightStateEnum {
	RED,
	YELLOW,
	GREEN,
	ALL_RED,
	FLASHING_YELLOW,
	FLASHING_RED,
	PEDESTRIAN_WALK,
	PEDESTRIAN_CLEARANCE
};

enum class StrategyType {
	FIXED_TIME,
	ACTUATUED,
	PEDESTRIAN_PRIORITY,
	DILEMMA_ZONE,
	EMERGENCY_PRIORITY
};

class InvalidPhaseException :public std::runtime_error {
public:
	InvalidPhaseException(const std::string& msg) :std::runtime_error(msg) {}
};

class SensorFailureException :public std::runtime_error {
public:
	SensorFailureException(const std::string& msg) :std::runtime_error(msg) {}
};