#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length + 1] {};
	count++;
}
int MyString::count = 0;
MyString::MyString(MyString&& obj)
{
	this->str = obj.str;
	this->length = obj.length;
	obj.str = nullptr;
	obj.length = 0;
	cout << "Move constructor!\n";
	count++;
}
MyString::MyString(int size)
{
	length = size;
	str = new char[length + 1] {};
	count++;
}

MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
	count++;
}

MyString::~MyString()
{
	delete[]str;
	str = nullptr;
	length = 0;
}

void MyString::Print()
{
	cout << str << endl;
}


void MyString::MyStrcpy(MyString& obj)
{
	delete[] str;
	length = strlen(obj.str);
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}

bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str,str);
	if (s != nullptr)
	{
		return true;
	}
	return false;
}

int MyString::MyChr(char c)
{
	char* s = strchr(str, c);
	if (s != nullptr)
	{
		return s - str; // вычесление индекса символа через указатели 
	}
	else 
	{
		return -1;
	}
}

int MyString::MyStrLen()
{
	int s = strlen(str);
	return s;
}

void MyString::MyStrCat(MyString& b)
{
	int s = strlen(str) + strlen(b.str) + 1;
	char * newChar = new char[s];
	strcpy_s(newChar, strlen(str) + strlen(b.str) + 1, this->str);
	strcat_s(newChar,s, b.str);
	delete[] this->str;
	this->str = newChar;
}

void MyString::MyDelChr(char c)
{
	int count = 0;
	for (int i = 0; i < length + 1; ++i)
	{
		if (str[i] == c)
		{
			count++;
		}
	}
	int newSize = length - count;
	char* newStr = new char[newSize + 1];

	int j = 0; // index newStr
	for (int i = 0; i < length + 1; ++i)
	{
		if (str[i] != c)
		{
			newStr[j] = str[i];
			j++;
		}
	}
	newStr[newSize] = '\0';
	delete[]str;
	str = newStr;
	length = newSize;
}

int MyString::MyStrCmp(const MyString& b)
{
	int result1 = strlen(this->str);
	int result2 = strlen(b.str);

	if (result1 > result2)
	{
		return 1;
	}
	else if (result1 < result2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

MyString MyString::operator+(MyString& b)
{
	MyString result(this->length + b.length);
	strcpy_s(result.str, this->length + 1, this->str);
	strcat_s(result.str, this->length + b.length + 1, b.str);
	return result;
}
MyString MyString::operator-(MyString& b)
{
	MyString result(this->length);
	strcpy_s(result.str, this->length + 1, this->str);
	for (int i = 0; i < b.length; ++i) 
	{
		result.MyDelChr(b.str[i]);
	}
	return result;
}
bool MyString::operator==(MyString& b)
{
	return strcmp(this->str, b.str) == 0;
}
void MyString::printCount()
{
	cout << "Count => " << count << endl;
}
MyString MyString::operator=(const MyString& obj)
{
	if (this == &obj) return *this; 

	if (str != nullptr)
	{
		delete[]str;
	}
	length = obj.length;
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	return *this;

}
MyString MyString::operator=(MyString&& obj)
{
	if (str != nullptr)
	{
		delete[]str;
	}
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = 0;
	return *this;
}
MyString& MyString::operator++()
{
	length++;
	return *this;
}

MyString& MyString::operator--()
{
	length--;
	return *this;
}

MyString MyString::operator++(int)
{
	MyString temp(*this);
	length++;
	return temp;
}

MyString MyString::operator--(int)
{
	MyString temp(*this);
	length--;
	return temp;
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	count++;
}

MyString& MyString::operator+=(int a)
{
	length += a;
	return *this;
}

MyString& MyString::operator-=(int a)
{
	length -= a;
	return *this;
}

MyString& MyString::operator+=(const char* st)
{
	int addLen = strlen(st);
	if (addLen == 0)
	{
		return *this;
	}
	char* newStr = new char[length + addLen + 1];
	strcpy(newStr, str);
	strcat(newStr, st);
	delete[] str;
	str = newStr;
	length += addLen;
	return *this;
}

MyString& MyString::operator-=(const char* st)
{
	int subLen = strlen(st);

	if (subLen == 0 || length == 0)
	{
		return *this;
	}
	char* pos = strstr(str, st);
	int newLen = length - subLen;
	char* newStr = new char[newLen + 1];
	int prefixLen = pos - str;
	strncpy(newStr, str, prefixLen);
	strcpy(newStr + prefixLen, pos + subLen);
	delete[] str;
	str = newStr;
	length = newLen;
	return *this;
}

ostream& operator<<(ostream& out, const MyString& s)
{
	if (s.str) {
		out << s.str;
	}
	else {
		out << "";
	}
	return out;
}

istream& operator>>(istream& in, MyString& s)
{
	char buffer[100];
	in >> buffer;
	delete[] s.str;
	s.length = strlen(buffer);
	s.str = new char[s.length + 1];
	strcpy(s.str, buffer);
	return in;
}
