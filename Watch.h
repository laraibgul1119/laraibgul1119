#include"Date.h"
#include"Time.h"
#ifndef WATCH_H
#define WATCH_H
class Watch
{
	Date dt;
	Time tm;
public:
	Watch();
	Watch(Date,Time);
	void setDate(Date);
	void setTime(Time);
	Date& getDate();
	Time& getTime();
	void incDay(int = 1);
	void incMonth(int = 1);
	void incYear(int = 1);
	void decDay(int = 1);
	void decMonth(int = 1);
	void decYear(int = 1);
	void incSec(int = 1);
	void incMin(int = 1);
	void incHour(int = 1);
	void decSec(int = 1);
	void decMin(int = 1);
	void decHour(int = 1);
	void printDateTimeFormat1()const;
	void printDateTimeFormat2()const;
	void printDateTimeFormat3()const;
};

#endif 
