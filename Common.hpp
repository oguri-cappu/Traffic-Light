#pragma once

#include <string>

class IObserver {
	virtual ~IObserver() = default;
	virtual void update(std::string eventSourceID) = 0;
};

class ISubject {
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
	FLASHING_YELLOW
};

enum class StrategyType {
	FIXED_TIME,
	ACTUATUED,
	DILEMMA_ZONE,
	EMERGENCY_PRIORITY
};