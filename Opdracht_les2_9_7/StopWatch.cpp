#include "StopWatch.h"
#include <ctime>
#include <chrono>

unsigned long getCurrentTime()
{
	unsigned long milliseconds_since_epoch =
		std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::system_clock::now().time_since_epoch()).count();

	return milliseconds_since_epoch;
}

void StopWatch::start()
{
	startTime = getCurrentTime();
}

void StopWatch::stop()
{
	endTime = getCurrentTime();
}

StopWatch::StopWatch()
{
	
}


StopWatch::~StopWatch()
{
}

long StopWatch::getStartTime()
{
	return startTime;
}

long StopWatch::getEndTime()
{
	return endTime;
}

long StopWatch::getElapsedTime()
{
	return endTime - startTime;
}
