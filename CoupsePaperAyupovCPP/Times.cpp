#include "Times.h"

Times::Times(microseconds nodeTime, microseconds mySetTime, microseconds listSetTime, microseconds setSetTime, microseconds mapSetTime, microseconds unorderedMapSetTime) {
	this->nodeTime = to_string(nodeTime.count());
	this->mySetTime = to_string(mySetTime.count());
	this->listSetTime = to_string(listSetTime.count());
	this->setSetTime = to_string(setSetTime.count());
	this->mapSetTime = to_string(mapSetTime.count());
	this->unorderedMapSetTime = to_string(unorderedMapSetTime.count());
}