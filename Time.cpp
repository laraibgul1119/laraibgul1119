#include<iostream>
#include"Time.h"
#include"Date.h"
#include"Watch.h"
using namespace std;
Time::Time(int h, int m, int s)
{
	setTime(h, m, s);
}
void Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		hour = h;
	}
}
void Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		minute = m;
	}
}
void Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		second = s;
	}
}
int Time::getHour()const
{
	return hour;
}
int Time::getSecond()const 
{
	return second;
}
int Time::getMinute()const
{
	return minute;
}
void Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
}
void Time::incSec(int increament)
{
	int previousSecond = second + increament;
	second = previousSecond % 60;
	incMin(previousSecond / 60);
}
void Time::incMin(int increament)
{
	int previousMin = minute + increament;
	minute = previousMin % 60;
	incHour(previousMin / 60);

}
void Time::incHour(int increament)
{
	int previousHour = hour + increament;
	hour = previousHour % 24;
}
void Time::printTwentyFoursHourFormat()const
{
	cout << hour << ":";
	cout << minute << ":";
	cout << second;
	cout << (hour >= 12 ? " PM" : " AM");
}
void Time::printTwelveHourFormat()const
{
	cout << hour % 12 << ":";
	cout << minute << ":";
	cout << second;
	cout << (hour >= 12 ? " PM" : " AM");
}
void Time::decHour(int dec)
{
		hour =hour-(dec % 24);
		if (hour < 0)
		{
			hour =hour+24;
		}
}
void Time::decMin(int dec)
{
	minute = minute - (dec % 60);
	if (minute < 0)
	{
		minute = minute + 60;
		decHour();
		return;
	}
	decHour(dec / 60);

}
void Time::decSec(int dec)
{
	second = second - (dec % 60);
	if (second < 0)
	{
		second = second + 60;
		decMin();
		return;
	}
	decMin(dec / 60);
}
