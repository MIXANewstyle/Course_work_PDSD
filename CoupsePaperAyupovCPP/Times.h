#pragma once
#include <chrono>
#include <string>

using namespace std;
using namespace chrono;
class Times
{
public:
	string nodeTime;
	string mySetTime;
	string listSetTime;
	string setSetTime;
	string mapSetTime;
	string unorderedMapSetTime;
	Times(microseconds, microseconds, microseconds, microseconds, microseconds, microseconds);
};

