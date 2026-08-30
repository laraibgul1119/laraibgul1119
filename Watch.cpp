#define _CRT_SECURE_NO_WARNINGS
#include"Watch.h"
#include<ctime>
#include"Time.h"
#include"Date.h"
#include"String.h"
#include<iostream>
using namespace std;
Watch::Watch()
{
	Time curTime;
	Date curDate;
	time_t t = time(nullptr);
	std::tm sysTime = *localtime(&t);
	curDate.setDay(sysTime.tm_mday);
	curDate.setMonth(sysTime.tm_mon + 1);
	curDate.setYear(sysTime.tm_year + 1900);
	curTime.setHour(sysTime.tm_hour);
	curTime.setMinute(sysTime.tm_min);
	curTime.setSecond(sysTime.tm_sec);
	tm = curTime;
	dt = curDate;
}
Watch::Watch(Date d, Time t):Watch()
{
	dt = d;
	tm = t;
}

void Watch::setDate(Date d)
{
	dt = d;
}
void Watch::setTime(Time t) 
{
	tm = t;
}
Date& Watch::getDate()
{
	return dt;
}
Time& Watch::getTime()
{
	return tm;
}
void Watch::incDay(int increament)
{
	dt.incDay(increament);
}
void Watch::incMonth(int increament)
{
	dt.incMonth(increament);
}

void Watch::incYear(int increament)
{
	dt.incYear(increament);
}

void Watch::decMonth(int decreament)
{
	dt.decMonth(decreament);
}

void Watch::decYear(int decreament)
{
	dt.decYear(decreament);
}
void Watch::incSec(int increament)
{
	int preHour = tm.getHour();
	while (increament != 0)
	{
		tm.incSec();
		if (tm.getHour() < preHour)
		{
			dt.incDay();
		}
		preHour = tm.getHour();
		increament--;
	}
}
void Watch::incMin(int increament)
{
	int preHour = tm.getHour();
	while (increament != 0)
	{
		tm.incMin();
		if (tm.getHour() < preHour)
		{
			dt.incDay();
			preHour = tm.getHour();
		}
		increament--;
	}
}
void Watch::incHour(int increament)
{
	incDay((increament + tm.getHour()) / 24);
	tm.incHour(increament % 24);
}
void Watch::decSec(int dec)
{
	int h = tm.getHour();
	for (int i = 1; i <= dec; i++)
	{
		tm.decSec();
		if (tm.getHour() > h)
		{
			dt.decDay();
			h = tm.getHour();
		}
	}
}
void Watch::decMin(int dec)
{
	int h = tm.getHour();
	for (int i = 1; i <= dec; i++)
	{
		tm.decMin();
		if (tm.getHour() > h)
		{
			dt.decDay();
			h = tm.getHour();
		}
	}
}
void Watch::decHour(int dec)
{
	while (dec != 0)
	{
		tm.decHour();
		if (tm.getHour()==23)
		{
			dt.decDay();
		}
		dec--;
	}
}
void Watch::printDateTimeFormat1()const
{
	cout << tm.getHour() << ":" << tm.getMinute() << ":" << tm.getSecond();
	cout << " <> ";
	dt.printFormat1();
}
void Watch::printDateTimeFormat2()const
{
	const char* month[13] = { "","Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec" };
	cout << tm.getHour() << ":" << tm.getMinute() << ":" << tm.getSecond();
	cout << " <> ";
	cout << month[dt.getMonth()];
	cout << "-";
	cout << dt.getYear();
}
void Watch::printDateTimeFormat3()const
{
	const char* month[13] = { "","January","Febrary","March","April","May","June","July","Augest","September","October","November","December" };
	cout << tm.getHour()%12 << ":" << tm.getMinute() << ":" << tm.getSecond();
	cout << " <> ";
	cout << dt.getDay()<<"-"<<month[dt.getMonth()]<<"-"<<dt.getYear();

}
void Watch::decDay(int decreament)
{
	dt.decDay(decreament);
}
