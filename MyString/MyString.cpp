#include "MyString.h"
#include <iostream>
#include <cstring>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length + 1] {};
}

MyString::MyString(MyString&& obj)
{
	this->str = obj.str;
	this->length = obj.length;
	obj.str = nullptr;
	obj.length = 0;
	cout << "Move constructor!\n";
}
MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
}

MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
}

MyString::~MyString()
{
	delete[]str;
	length = 0;
}

void MyString::Print()
{
	cout << str << endl;
}


void MyString::MyStrcpy(MyString& obj)
{
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
	return s - 1;
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

MyString MyString::operator+(const char *b)
{
	MyString result(length+1 + strlen(b)+1);
	strcpy_s(result.str, result.length + 1, this->str);
	strcat_s(result.str, length + strlen(b)+2, b);
	return result;
}
MyString MyString::operator-(const char* b)
{
	MyString result(this->length + 1);
	char* pos = strstr(result.str, b);
	if (pos != nullptr)
	{
		int newLenght = strlen(this->str) - strlen(b);
		result.str = new char[newLenght + 1];
	}
	
}


	
