
#include <iostream>
#include "MyString.h"
using namespace std;
int main()
{
	MyString obj1("Hello world!");
	obj1.Print();
	cout << obj1.MyStrStr("wo") << endl;
	cout << "Index: " << obj1.MyChr('o') << endl;
	cout << "length of line: " << obj1.MyStrLen() << endl;
	MyString obj2("Bye world");
	char* resultCat = obj1.MyStrCat(obj2);

}