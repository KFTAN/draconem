#pragma once
#include <iostream>
using namespace std;

//Constant
const int SECONDS_PER_HOUR = 3600;
const int MINUTES_PER_HOUR = 60;
const int SECONDS_PER_MINUTE = 60;

class TimeSpan
{

	friend ostream & operator<<(ostream & os, const TimeSpan & ts);
	friend istream & operator>>(istream & is, const TimeSpan & ts);

public:
	TimeSpan();
	~TimeSpan();
	TimeSpan(double sec);
	TimeSpan(double min, double sec);
	TimeSpan(double hour, double min, double sec);

	int getSeconds() const;
	int getMinutes() const;
	int getHours() const;
	void setSeconds(int sec);
	void setMinutes(int min);
	void setHours(int hour);
	bool setTime(int hours, int minutes, int seconds);
	TimeSpan operator+(const TimeSpan & time) const;
	TimeSpan operator-(const TimeSpan & time) const;
	TimeSpan operator+=(const TimeSpan & time);
	TimeSpan operator-=(const TimeSpan & time);
	//void operator-(TimeSpan & t);

private:
	int seconds, minutes, hours;
	void normalize(double hour, double min, double sec);


};

