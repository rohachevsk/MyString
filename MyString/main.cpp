
#include <iostream>
#include "MyString.h"
using namespace std;
int main()
{
	MyString obj1("Hello worldd!");
	obj1.Print();
	cout << obj1.MyStrStr("wo") << endl;
	cout << "Index: " << obj1.MyChr('o') << endl;
	cout << "length of line: " << obj1.MyStrLen() << endl;
	MyString obj2("Bye world1221");
	cout << "length of line: " << obj2.MyStrLen() << endl;
	cout << obj1.MyStrCmp(obj2);
	obj1.MyStrCat(obj2);
	obj1.MyDelChr('l');
	cout << endl;
	MyString obj3(move(obj1));
	obj3.Print();
}