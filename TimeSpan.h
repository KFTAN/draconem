#pragma once
#include <iostream>
using namespace std;

class TimeSpan
{
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
	//TimeSpan operator+(const TimeSpan & t) const;
	//TimeSpan operator-(const TimeSpan & t) const;
	//TimeSpan operator+=(const TimeSpan & t) const;
	//void operator-() const;
	friend ostream & operator<<(ostream & os, const TimeSpan & ts);
	//friend istream & operator>>(istream & is, const TimeSpan & ts);
	
private:
	int Seconds, Minutes, Hours;
	void normalize(double hour, double min, double sec);


};

