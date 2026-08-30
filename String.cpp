#include<iostream>
#include"String.h"
using namespace std;
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c)
{
	size = 2;
	data = new char[size] {c, '\0'};
}
String::String(const char* str) :String()
{
	int strLength = getLength(str);
	if (strLength == 0)
	{
		return;
	}
	size = strLength + 1;
	data = new char[size];
	stringCopy(data, str);
}
String::String(const String& ref) :String()
{
	if (ref.data == nullptr)
	{
		return;
	}
	size = ref.size;
	data = new char[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = ref.data[i];
	}
}
int String::getLength(const char* str)const
{
	int i = 0;
	if (str == nullptr)
	{
		return i;
	}
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
void String::stringCopy(char* dest, const char* src)const
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}
bool String::isEmpty()const
{
	return data == nullptr || data[0] == '\0';
}
void String::display()const
{
	if (!isEmpty())
	{
		cout << data;
	}
}
const char& String::at(const int index)const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
char& String::at(const int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	exit(0);
}
void String::reSize(const int newSize)
{
	if (newSize <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[newSize];
	int i = 0;
	while (i < newSize - 1 && i < getLength())
	{
		temp[i] = data[i] >= 0 ? data[i] : 0;
		i++;
	}
	temp[i] = '\0';
	this->~String();
	size = newSize;
	data = temp;
}
void String::concatEqual(const String& s2)
{
	if (!s2.isEmpty())
	{
		reSize(getLength() + s2.getLength() + 1);
		stringCopy(&data[getLength()], s2.data);
	}
}
void String::setNumber(const long long int num)
{
	size = 0;
	long long int temp = num;
	while (temp != 0)
	{
		temp = temp / 10;
		size++;
	}
	long long int tempNum = num;
	char* ch;
	if (num != 0)
	{
		ch = new char[size + 2];
		for (int i = size; i >= 1; i--)
		{
			ch[i] = ((num < 0 ? -1 : 1) * (tempNum % 10)) + '0';
			tempNum = tempNum / 10;
		}
		num < 0 ? ch[0] = '-' : ch[0] = ' ';
		ch[size + 1] = '\0';
	}
	else
	{
		ch = new char[2] {'0', '\0'};
	}
	size = size + 2;
	delete[]data;
	data = ch;
}
bool String::isValidIndex(const int index)const
{
	return index >= 0 && index < getSize() ? true : false;
}
int String::getLength()const
{
	return getLength(data);
}
int String::getSize()const
{
	return size;
}
void String::input()
{
	reSize(data == nullptr ? 1 : size + 1);
	int count = getLength();
	char ch;
	while ((ch = cin.get()) != '\n')
	{
		data[count] = ch;
		if (count + 1 == size)
		{
			reSize(size * 2);
		}
		count++;
	}
	data[count] = '\0';
}
void String::reverse()
{
	if (getLength() != 0)
	{
		for (int j = getLength() - 1, i = 0; i < j; j--, i++)
		{
			swap(data[i], data[j]);
		}
	}
}
bool String::isSameString(const char* firstStr, const char* secondStr)
{
	if (firstStr[0] != '\0')
	{
		for (int i = 0; firstStr[i] != '\0'; i++)
		{
			if (firstStr[i] != secondStr[i])
			{
				return false;
			}
		}
		return true;
	}
	return firstStr[0] == secondStr[0];
}
void String::shrink()
{
	if (getLength())
	{
		reSize(getLength() + 1);
	}
}
bool String::isWideSpaceCharacter(char ch)const
{
	return ch == ' ' || ch == '\t' || ch == '\n';
}

void String::trimLeft()
{
	if (!isEmpty())
	{
		int i = 0;
		while (i < getLength() && isWideSpaceCharacter(data[i]))
		{
			i++;
		}
		if (i == getLength())
		{
			this->~String();
			return;
		}
		else if (i > 0)//this condition is used if our string does not have any wide space at start "Hello"
		{
			char* temp = new char[getLength() - i + 1];
			stringCopy(temp, &data[i]);
			delete[]data;
			data = temp;
			size = getLength() - i;
		}
	}
}
void String::trim()
{
	if (!isEmpty())
	{
		trimLeft();
		trimRight();
	}
}
void String::trimRight()
{
	if (!isEmpty())
	{
		int i = getLength() - 1;
		while (i >= 0 && isWideSpaceCharacter(data[i]))
		{
			i--;
		}
		data[i + 1] = '\0';
		size = i + 1;
	}
}
void String::makeUpper()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = (data[i] - 'a') + 'A';
		}
	}
}
void String::makeLower()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = (data[i] - 'A') + 'a';
		}
	}
}
String String::concatenate(const String& s2)const
{
	if (data == nullptr && s2.data == nullptr)
	{
		return String();
	}
	else if (s2.data == nullptr || data == nullptr)
	{
		String s{ data == nullptr ? s2.data : data };
		return s;
	}
	int i = getLength();
	int j = s2.getLength();
	char* temp = new char[i + j + 1];
	stringCopy(temp, data);
	stringCopy(&temp[getLength()], s2.data);
	String s{ temp };
	delete[]temp;
	return s;
}
String String::left(const int count)
{
	if (count <= 0)
	{
		return String();
	}
	if (count >= getLength())
	{
		String s(*this);
		this->~String();
		return s;
	}
	char temp = data[count];
	data[count] = '\0';
	String s{ data };
	data[count] = temp;
	stringCopy(&data[0], &data[count]);
	return s;
}
String String::right(const int count)
{
	if (count <= 0)
	{
		return String();
	}
	if (count >= getLength())
	{
		String s(*this);//this has a type of String * const this
		this->~String();
		return s;
	}
	String s(&data[getLength() - count]);
	reSize(getLength() - count + 1);
	return s;
}
bool String::isPalindromeString()const
{
	if (getLength() == 1)
	{
		return true;
	}
	for (int i = 0, j = getLength() - 1; i < j; i++, j--)
	{
		if (data[i] != data[j])
		{
			return false;
		}
	}
	return true;
}
int String::compare(const String& s2)const
{
	int str1Length = getLength();
	int str2Length = s2.getLength();
	int minLength = str1Length < str2Length ? str1Length : str2Length;
	for (int i = 0; i < minLength; i++)
	{
		if (data[i] > s2.data[i])
		{
			return 1;
		}
		else if (data[i] < s2.data[i])
		{
			return -1;
		}
	}
	if (str1Length > str2Length)
	{
		return 1;
	}
	else if (str2Length > str1Length)
	{
		return -1;
	}
	return 0;
}
int String::find(const String subStr, const int start)
{
	if (!isEmpty() && !subStr.isEmpty())
	{
		for (int i = start; i < getLength(); i++)
		{
			if (isSameString(subStr.data, &data[i]))
			{
				return i;
			}
		}
	}
	return -1;
}
void String::insert(const int index, const String& subStr)
{
	if (isValidIndex(index) && !(subStr.isEmpty()))
	{
		reSize(getLength() + subStr.getLength() + 1);
		char* temp = new char[getLength() - index + 1];
		stringCopy(temp, &data[index]);
		stringCopy(&data[index], subStr.data);
		stringCopy(&data[getLength()], temp);
		reSize(getLength() + 1);
		delete[]temp;
	}
}
void String::remove(const int index, const int count)
{
	if (!isValidIndex(index) || isEmpty() || count <= 0)
	{
		return;
	}
	else if (index == 0 && count >= getLength())
	{
		reSize(1);
		return;
	}
	else if (index + count >= getLength())
	{
		reSize(index + 1);
		return;
	}
	char* temp = new char[getLength() - count + 1];
	stringCopy(temp, &data[index + count]);
	stringCopy(&data[index], temp);
	delete[]temp;
	reSize(getLength() + 1);
}
void String::concatenate(char* dest, const char* src)const
{
	int i = getLength(dest);
	stringCopy(&dest[i], src);
}
int String::replace(const String& old, const String& newSubStr)
{
	if (isEmpty() || old.isEmpty() || newSubStr.isEmpty())
	{
		return 0;
	}
	int count = 0;
	int sizeOfNewString = (find(old) * getLength(newSubStr.data) + getLength()) - (find(old) * getLength(old.data)) + 1;
	char* temp = new char[sizeOfNewString] {'\0'};
	for (int i = 0; i < getLength(); i++)
	{
		if (isSameString(old.data, &data[i]))
		{
			concatenate(temp, newSubStr.data);
			i = getLength(old.data) + i - 1;
		}
		else
		{
			int j = getLength(temp);
			temp[j] = data[i];
			temp[j + 1] = '\0';
		}
	}
	this->~String();
	data = temp;
	size = sizeOfNewString;
	return count;
}
long long int String::convertToInteger()const
{
	int i = 0;
	long long int  number = 0;
	if (!isEmpty())
	{
		while (data[i] >= '0' && data[i] <= '9')
		{
			number = number * 10 + ((int)data[i] - '0');
			i++;
		}
	}
	return number;
}
float String::convertToFloat()const
{
	if (!isEmpty())
	{
		return (getDecimalPart() + convertToInteger());
	}
	return 0;
}
int String::getPositionOfDecimalPoint()const
{
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] == '.')
		{
			return i;
		}
		i++;
	}
	return -1;
}
// Precision issue will remain because in backened the float number is stored as IEEE-754
float String::getDecimalPart()const
{
	float deciNumber = 0, p = 10.0;
	if (getPositionOfDecimalPoint() != -1)
	{
		int i = getPositionOfDecimalPoint() + 1;
		while (data[i] >= '0' && data[i] <= '9')
		{
			deciNumber = deciNumber + (float)(data[i] - '0') / p;
			p = p * 10;
			i++;
		}
	}
	return deciNumber;
}
String::~String()
{
	delete[]data;
	data = nullptr;
	size = 0;
}