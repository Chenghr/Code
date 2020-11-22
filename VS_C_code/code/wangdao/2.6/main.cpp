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
};//第一个元素为0是为了便于访问

bool IsLeapYear (int year)//判断是否是闰年
{
    if ( (year%4 == 0 && year%100 != 0 ) || (year%400 == 0)) return true;
    return false;
}

int main()
{
    int num1,num2;
    while (scanf("%d%d",&num1,&num2) != EOF )
    {
        int year1,month1,day1;
        int year2,month2,day2;
        int sum = 0;

        year1 = num1/10000;
        year2 = num2/10000;
        month1 = (num1%10000)/100;
        month2 = (num2%10000)/100;
        day1 = num1%100;
        day2 = num2%100;

        for (int i=year1; i<year2; i++)
        {
            if(IsLeapYear(i)) sum += 366;
            else sum += 365;
        }

        int tag = IsLeapYear(year1);
        for (int i=0; i<month1; i++)
        {
            sum -= daytab[tag][i];
        }
        sum -= day1;

        tag = IsLeapYear(year2);
        for (int i=0; i<month2; i++)
        {
            sum += daytab[tag][i];
        }
        sum += day2;
        printf("%d\n",sum+1);//相邻日期视为相差两天
    }
    return 0;
}
