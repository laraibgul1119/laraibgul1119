#include<iostream>
#include<iomanip>
#include "String.h"
#include "Date.h"
using namespace std;
const int Date::_DAYS_IN_MONTH[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31};
bool Date::isLeapYear()const
{
	if ((year % 4 == 0) && (year % 100 != 0))
	{
		return true;
	}
	else if ((year % 100 == 0) && (year % 400 == 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}
Date::Date() :day(14), month(10), year(2019)
{
}
Date::Date(int d, int m, int y) :Date()
{
	setDate(d, m, y);
}
void Date::setDay(int d)
{
	if (d >= 1 && d <= Date::_DAYS_IN_MONTH[month])
	{
		day = d;
	}
}
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
	}
}
void Date::setYear(int y)
{
	if (y >= 1500)
	{
		year = y;
	}
}
void Date::setDate(int d, int m, int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
int Date::getDaysInMonth()
{
	if (month == 2 && isLeapYear())
	{
		return 29;
	}
	return Date::_DAYS_IN_MONTH[month];
}
void Date::incDay(int increament)
{
	do {
		int remainingDays = getDaysInMonth() - day + 1;
		if (increament >= remainingDays)
		{
			increament = increament - remainingDays;
			day = 1;
			month++;
			if (month > 12)
			{
				month = 1;
				year++;
			}
		}
		else
		{
			day = day + increament;
			increament = 0;
		}

	} while (increament > 0);
}
void Date::incMonth(int increament)
{
	int preMonth = month;
	month = (preMonth + increament) % 12;
	incYear((preMonth + increament) / 12);
}
void Date::incYear(int increament)
{
	year = year + increament;
}
String Date::getDateInFormat1()const
{
	String date{ '\0' };
	String temp;
	temp.setNumber(day);
	date.concatEqual(temp);
	date.concatEqual("/");
	temp.setNumber(month);
	date.concatEqual(temp);
	date.concatEqual("/");
	temp.setNumber(year);
	date.concatEqual(temp);
	return date;
}
void Date::printFormat1()const
{
	cout.fill(0);
	cout << setw(2) << day << "/" << setw(2) << month << "/" << setw(4) << year;
}
String Date::getDateInFormat2()const
{
	const char* monthName[13] = { "\0","January","Feburary","March","April","May","June","July","Augest","September","October","November","December" };
	String date{monthName[month] }, temp;
	temp.setNumber(day);
	date.concatEqual(temp);
	date.concatEqual(",");
	temp.setNumber(year);
	date.concatEqual(temp);
	return date;
}
void Date::printFormat2()const
{
	const char* monthName[13] = { "\0","January","Feburary","March","April","May","June","July","Augest","September","October","November","December" };
	cout << monthName[month] << " " << day << "," << year;
}
String Date::getDateInFormat3()const
{
	const char *monShortName[13]= { "\0","Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec" };
	String date, temp;
	temp.setNumber(day);
	date.concatEqual(temp);
	date.concatEqual("-");
	date.concatEqual(monShortName[month]);
	date.concatEqual("-");
	temp.setNumber(year);
	date.concatEqual(temp);
	return date;
}
void Date::printFormat3()const
{
	const char* monShortName[13] = { "\0","Jan","Feb","Mar","Apr","May","June","July","Aug","Sep","Oct","Nov","Dec" };
	cout << day << "-" << monShortName[month] << "-" << year;
}
int  Date::isEqual(const Date d) const
{
	if ((getDay() == d.getDay()) && (getMonth() == d.getMonth()) && (getYear() == d.getYear()))
	{
		return 0;
	}
	else if ((getYear() > d.getYear()) || (getMonth() > d.getMonth()) || (getDay() > d.getDay()))
	{
		return 1;
	}
	return -1;
}
void Date::decDay(int dec)
{
	do {
		int previousDays = day;
		if (dec >= previousDays)
		{
			dec = dec - previousDays;
			month--;
			if (month < 1 )
			{
				month = 12;
				year--;
			}
			day = getDaysInMonth();
		}
		else
		{
			day = day -dec;
			dec = 0;
		}

	} while (dec > 0);
}
void Date::decMonth(int dec)
{
	int remainingMonths = month - dec;
	while(remainingMonths<=0)
	{
		remainingMonths = remainingMonths + 12;
		decYear(1);
	}
	month = remainingMonths;
}
void Date::decYear(int dec)
{
	year = year - dec;
}