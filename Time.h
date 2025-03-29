#ifndef TIME_H
#define TIME_H
class Time
{
	int hour;
	int minute;
	int second;
public:
	Time(int =0, int= 0, int =0 );
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour()const;
	int getSecond()const;
	int getMinute()const;
	void setTime(int h, int m, int s);
	void decHour(int = 1);
	void decMin(int = 1);
	void decSec(int = 1);
	void incSec(int increament = 1);
	void incMin(int increament = 1);
	void incHour(int increament = 1);
	void printTwentyFoursHourFormat()const;
	void printTwelveHourFormat()const;
};
#endif
