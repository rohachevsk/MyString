#pragma once
#include <iostream>
class MyString
{
	char* str;
	int length;
public:
	MyString();
	static int count;
	MyString(MyString&& obj);
	MyString(int size);
	MyString(const char* st);
	MyString(const char *s) : length(strlen(s)), str(new char[strlen(s) + 1]) // список инициализации
	{
		strcpy(str, s);
	}
	~MyString();
	void Print();
	void MyStrcpy(MyString& obj);// копирование строк
	bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyStrCat(MyString& b); // объединение строк
	void MyDelChr(char c); // удаляет указанный символ 
	int MyStrCmp(const MyString& b); // сравнение строк 
	MyString operator+(MyString& b);
	MyString operator-(MyString& b);
	bool operator==(MyString& b);
	static void printCount();
	MyString operator=(const MyString& obj);
	MyString operator=(MyString&& obj);
	MyString& operator++(); //prefix
	MyString& operator--();
	MyString operator++(int);// postfix
	MyString operator--(int);
	MyString(const MyString& obj);
	MyString& operator+=(int a);
	MyString& operator-=(int a);
	MyString& operator+=(const char* st);
	MyString& operator-=(const char* st);
	friend ostream& operator<<(ostream& out, const MyString& s);
	friend istream& operator>>(istream& in, MyString& s);
};



