#include <iostream>
#include <windows.h>
using namespace std;

struct Date{
	int day;
	int month;
	int year;
	
	Date(); //текущая дата
	Date(int);
	Date(int, int);
	Date(int, int, int);
	void add_day();
	void print(); // в формате 9/2/2017
};

int main(){	
	Date A;
	Date D(30);
	D.print();
	Date C(30, 12);
	C.print();
	C.add_day();
	C.print();
	A.print();
	return 0;
}

	Date::Date(){
		SYSTEMTIME time;
		GetSystemTime(&time);
		day = time.wDay;
		month = time.wMonth;
		year = time.wYear;
	}
	
	Date::Date(int d){
		SYSTEMTIME time;
		GetSystemTime(&time);
		day = d;
		month = time.wMonth;
		year = time.wYear;
	}
	
	Date::Date(int d, int m){
		SYSTEMTIME time;
		GetSystemTime(&time);
		day = d;
		month = m;
		year = time.wYear;
	}
	
	Date::Date(int d, int m, int y){
		day = d;
		month = m;
		year = y;
	}
	
	void Date::add_day(){
		day++;
		if (day > 30)
			day = 1, month++;
		if (month > 12)
			month = 1, year++;
	}
	void Date::print(){
		cout << day << "/" << month << "/" << year << endl;
	}
