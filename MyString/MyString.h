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
	MyString(const char *s) : length(strlen(s)), str(new char[strlen(s) + 1]) // ������ �������������
	{
		strcpy(str, s);
	}
	~MyString();
	void Print();
	void MyStrcpy(MyString& obj);// ����������� �����
	bool MyStrStr(const char* str);// ����� ��������� � ������
	int  MyChr(char c); // ����� ������� � ������(������ ���������� �������, ���� -1)
	int MyStrLen();// ���������� ����� ������
	void MyStrCat(MyString& b); // ����������� �����
	void MyDelChr(char c); // ������� ��������� ������ 
	int MyStrCmp(const MyString& b); // ��������� ����� 
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



