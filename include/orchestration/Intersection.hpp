#pragma once

#include "Common.hpp"
#include "signaling/Phase.hpp"
#include "sensing/Sensor.hpp"
#include <vector>
#include <memory>
#include <string>

class Intersection {
private:
	std::string intersectionID;
	std::vector<std::unique_ptr<Phase>> phases;
	std::vector<std::unique_ptr<Sensor>> sensors;
public:
	Intersection(std::string id);
	void addPhase(std::unique_ptr<Phase>);
	void addSensor(std::unique_ptr<Sensor>);
	std::vector<std::unique_ptr<Phase>>& getPhases();
	std::vector<std::unique_ptr<Sensor>>& getSensor();
	void tickAllPhases();
};