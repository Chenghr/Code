#include <iostream>
#include <cstdio>

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

int main()
{
    int m;
    cin >> m;
    while (m>0)
    {
        m--;
        int year,month,day;
        cin >> year >> month >> day;

        int tag = IsLeapYear(year);
        if(day+1 > daytab[tag][month])
        {
            day = day+1-daytab[tag][month];
            month++;
            if(month > 12)
            {
                month = month-12;
                year++;
            }
        }
        else
        {
            day++;
        }

        printf("%04d-%02d-%02d\n",year,month,day);
    }

    return 0;
}
