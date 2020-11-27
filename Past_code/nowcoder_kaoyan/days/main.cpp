#include <iostream>

using namespace std;

int daytab[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},
                    {0,31,29,31,30,31,30,31,31,30,31,30,31}};

bool IsLeapYear(int year)
{
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
    {
        return true;
    }
    return false;
}
int main()
{
    int y,m,d;
    while(cin >> y >> m >> d)
    {
        int sum = d;
        m--;//最后一个月不满
        int tag = IsLeapYear(y);
        while(m > 0)
        {
            sum += daytab[tag][m];
            m--;
        }
        cout << sum << endl;
    }
    return 0;
}
