#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int daytab[2][13] = {
    {
        0,31,28,31,30,31,30,31,31,30,31,30,31
    },//平年
    {
         0,31,29,31,30,31,30,31,31,30,31,30,31
    }//闰年
};

bool IsLeapYear (int year)//判断是否是闰年
{
    if ( (year%4 == 0 && year%100 != 0 ) || (year%400 == 0)) return true;
    return false;
}

string mon[13] = {"null","January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
    int day,year;
    string month;
    while (cin >> day >> month >> year)
    {
        int month_int = 0;
        for (month_int=1; month_int<13; month_int++)
        {
            if(mon[month_int] == month) break;
        }

        int sum = 0;

        for(int i=2001; i<year; i++)
        {
            if(IsLeapYear(i)) sum +=366;
            else sum += 365;
        }

        int tag = IsLeapYear(year);
        for(int i=0; i<month_int; i++)
        {
            sum += daytab[tag][i];
        }
        sum += day;

        cout << week[sum%7] << endl;
    }
    return 0;
}
