#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length] {};
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
	strcat(newChar, this->str);
	delete[] this->str;
	this->str = newChar;
}
	
