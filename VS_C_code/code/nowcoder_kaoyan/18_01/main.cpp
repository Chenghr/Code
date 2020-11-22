#include <iostream>
#include <string>

using namespace std;

int daytab[2][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

string week[7] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};

bool IsLeapYear(int year)
{
    if((year%4 ==0 && year%100 != 0) || (year%400 == 0)) return true;
    return false;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int d = n%7;//����ܼ�
        int y = 2000;
        int m = 1;
        int tag = IsLeapYear(y);
        n = n+1;//nΪ����1��1�ն�����

        while(n-daytab[tag][m] > 0)//ȷ������
        {
            n = n-daytab[tag][m];
            m++;//������
            if(m > 12)//�������Լ�������
            {
                m -= 12;
                y += 1;
                tag = IsLeapYear(y);
            }
        }

        cout << y << "-" << m << "-" << n << " " << week[d] << endl;;

    }
    return 0;
}
