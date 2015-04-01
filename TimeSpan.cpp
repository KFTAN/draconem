#include "stdafx.h"
#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	Seconds = 0;
	Minutes = 0;
	Hours = 0;
}

TimeSpan::TimeSpan(double sec)
{
	normalize(0, 0, sec);
}

TimeSpan::TimeSpan(double min, double sec)
{
	normalize(0, min, sec);
}

TimeSpan::TimeSpan(double hour, double min, double sec)
{
	normalize(hour, min, sec);
}

void TimeSpan::normalize(double hour, double min, double sec)
{
	int totalSeconds;
	double remainder, wholeNum;

	//Phase 1: Convert hours to seconds
	/*
		double hourRemander = (int)hour / hour;

		Compute remainder from hour -> minute
		
		double minRemander = (int)minute / minute;
		compute remainder from minute -> second

		double second = (int)second / second;
	*/
	remainder = modf(hour, & wholeNum); //wholeNum(hr) = 2hr, remainder = 0.8hr 
	totalSeconds = (wholeNum * 3600); //totalSec += (2hr * 3600min)
	wholeNum = (remainder * 60); //wholeNum(min) = (0.8hr * 60min)

	remainder = modf(wholeNum, & wholeNum); //wholeNum(min) = 52min, remainder 0.88min
	totalSeconds += (wholeNum * 60); //totalSec += (52min * 60sec) 
	totalSeconds += (remainder * 60); //totalSec += (0.88min * 60 sec)

	//Phase 2: Convert minutes to seconds
	remainder = modf(min, & wholeNum); //wholeNum(min) = 2min, remainder = 0.8min 
	totalSeconds += (wholeNum * 60); //totalSec += (2min * 60sec) 
	totalSeconds += (remainder * 60); // totalSec += (0.8min * 60 sec)

	//Phase 3: Add total seconds
	totalSeconds += (int) sec; 

	//Phase 4: Calculate/store time values 
	this->Hours = (totalSeconds / 3600);
	this->Minutes = ((totalSeconds / 60) % 60);
	this->Seconds = (totalSeconds % 60);
}

int TimeSpan::getHours() const
{
	return this->Hours;
}

int TimeSpan::getMinutes() const
{
	return this->Minutes;
}

int TimeSpan::getSeconds() const
{
	return this->Seconds;
}

void TimeSpan::setHours(int hour)
{
	this->normalize(hour, this->Minutes, this->Seconds);
}

void TimeSpan::setMinutes(int min)
{
	this->normalize(this->Hours, min, this->Seconds);
}

void TimeSpan::setSeconds(int sec)
{
	this->normalize(this->Hours, this->Minutes, sec);
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{

	this->normalize(hours, minutes, seconds);
	return true;
}

ostream & operator<<(ostream & os, const TimeSpan & ts)
{
	cout << "Hours: " << ts.Hours << " Minutes: " << ts.Minutes << " Seconds: " << ts.Seconds << endl;
	return os;
}

TimeSpan::~TimeSpan()
{

}