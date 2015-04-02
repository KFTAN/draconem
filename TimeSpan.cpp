#include "stdafx.h"
#include "TimeSpan.h"

TimeSpan::TimeSpan()
{
	seconds = 0;
	minutes = 0;
	hours = 0;
}

TimeSpan::TimeSpan(double sec)
{
	this->normalize(0, 0, sec);
}

TimeSpan::TimeSpan(double min, double sec)
{
	this->normalize(0, min, sec);
}

TimeSpan::TimeSpan(double hour, double min, double sec)
{
	this->normalize(hour, min, sec);
}

void TimeSpan::normalize(double hour, double min, double sec)
{
	int totalSeconds, tmpHrs, tmpMin, tmpSec;
	double remainder, wholeNum;

	if (hour == 0 && min == 0 && sec == 0)
	{
		this->setTime(0, 0, 0);
	}
	else
	{
		/*
			remainder = (int)hour / hour;

			Compute remainder from hour -> minute

			double minRemainder = (int)minute / minute;

			compute remainder from minute -> second

			double second = (int)second / second;
		*/

		//Phase 1: Convert hours to minutes and seconds
		remainder = modf(hour, & wholeNum); //Separate whole hour from its remainder
		totalSeconds = (wholeNum * SECONDS_PER_HOUR); //Convert, store whole hours to seconds
		wholeNum = (remainder * MINUTES_PER_HOUR); //Convert, store remainder(hr) to minutes

		//Phase 2: Convert minutes to seconds
		wholeNum += min;
		remainder = modf(wholeNum, & wholeNum); //Separate whole minute from its remainder
		totalSeconds += (wholeNum * SECONDS_PER_MINUTE); //Convert, store whole minutes into seconds
		totalSeconds += (remainder * SECONDS_PER_MINUTE); //Convert, store remainder(min) to seconds

		//Phase 3: Add total seconds
		totalSeconds += sec;

		//Phase 4: Calculate/store time values 
		tmpHrs = (totalSeconds / SECONDS_PER_HOUR);
		tmpMin = ((totalSeconds / MINUTES_PER_HOUR) % SECONDS_PER_MINUTE);
		tmpSec = (totalSeconds % SECONDS_PER_MINUTE);

		this->setTime(tmpHrs, tmpMin, tmpSec);
	}

}

int TimeSpan::getHours() const
{
	return this->hours;
}

int TimeSpan::getMinutes() const
{
	return this->minutes;
}

int TimeSpan::getSeconds() const
{
	return this->seconds;
}

void TimeSpan::setHours(int hour)
{
	this->normalize(hour, this->minutes, this->seconds);
	
}

void TimeSpan::setMinutes(int min)
{
	this->normalize(this->hours, min, this->seconds);
}

void TimeSpan::setSeconds(int sec)
{
	this->normalize(this->hours, this->minutes, sec);
}

bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
	this->hours = hours;
	this->minutes = minutes; 
	this->seconds = seconds;
	return true;
}

TimeSpan TimeSpan::operator+(const TimeSpan & time) const
{
	TimeSpan timeSum;
	int totalHrs, totalMin, totalSec;

	totalHrs = this->hours + time.hours;
	totalMin = this->minutes + time.minutes;
	totalSec = this->seconds + time.seconds;

	timeSum.normalize(totalHrs, totalMin, totalSec);

	return timeSum;
}

TimeSpan TimeSpan::operator-(const TimeSpan & time) const
{
	TimeSpan timeDiff;
	int totalHrs, totalMin, totalSec;

	totalHrs = this->hours - time.hours;
	totalMin = this->minutes - time.minutes;
	totalSec = this->seconds - time.seconds;

	timeDiff.normalize(totalHrs, totalMin, totalSec);

	return timeDiff;
}

TimeSpan TimeSpan::operator+=(const TimeSpan & time)
{
	TimeSpan timeSum;
	int totalHrs, totalMin, totalSec;

	totalHrs = this->hours + time.hours;
	totalMin = this->minutes + time.minutes;
	totalSec = this->seconds + time.seconds;

	this->normalize(totalHrs, totalMin, totalSec);

	return timeSum;
}

TimeSpan TimeSpan::operator-=(const TimeSpan & time)
{
	TimeSpan timeDiff;
	int totalHrs, totalMin, totalSec;

	totalHrs = this->hours - time.hours;
	totalMin = this->minutes - time.minutes;
	totalSec = this->seconds - time.seconds;

	this->normalize(totalHrs, totalMin, totalSec);

	return timeDiff;
}

ostream & operator<<(ostream & os, const TimeSpan & time)
{
	os << "Hours: " << time.hours << " Minutes: " << time.minutes << " Seconds: " << time.seconds << endl;
	return os;
}

istream & operator>>(istream & is, const TimeSpan & time)
{
	is >> time.hours >> time.minutes >> time.seconds;
	return is;
}


TimeSpan::~TimeSpan()
{

}
