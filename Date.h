#include "String.h"
#ifndef DATE_H
#define DATE_H
class Date
{
	int day;
	int year;
	int month;
	static const int _DAYS_IN_MONTH[13];
	int getDaysInMonth();
public:
	Date();
	Date(int, int, int);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int isEqual(const Date d)const;
	void decDay(int = 1);
	void decMonth(int = 1);
	void decYear(int = 1);
	void setDate(int d, int m, int y);
	bool isLeapYear()const;
	int getDay()const;
	int getMonth()const;
	int getYear()const;
	void incDay(int = 1);
	void incMonth(int = 1);
	void incYear(int = 1);
	void printFormat1()const;
	void printFormat2()const;
	void printFormat3()const;
	String getDateInFormat1()const;
	String getDateInFormat2()const;
	String getDateInFormat3()const;
};
#endif 




