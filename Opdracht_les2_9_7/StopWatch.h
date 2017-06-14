#pragma once
class StopWatch
{
private:
	long startTime;
	long endTime;
public:
	StopWatch();
	~StopWatch();
	long getStartTime();
	long getEndTime();
	long getElapsedTime();
	void start();
	void stop();
};

