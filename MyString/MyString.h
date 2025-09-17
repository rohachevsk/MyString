#pragma once
class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(MyString&& obj);
	MyString(int size);
	MyString(const char* st);
	~MyString();
	void Print();
	void MyStrcpy(MyString& obj);// копирование строк
	bool MyStrStr(const char* str);// поиск подстроки в строке
	int  MyChr(char c); // поиск символа в строке(индекс найденного символа, либо -1)
	int MyStrLen();// возвращает длину строки
	void MyStrCat(MyString& b); // объединение строк
	void MyDelChr(char c); // удаляет указанный символ 
	int MyStrCmp(const MyString& b); // сравнение строк 
	
	
};

