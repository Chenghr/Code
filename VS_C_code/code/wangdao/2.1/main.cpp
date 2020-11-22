#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a[101] = {0};
    for(int i=1; i<101; i++)//预处理,先找出0~100中与7有关的数
    {
        if(i%7 == 0) a[i] = 1;//与7有关
        int t = i,j = 0;
        while(t != 0)
        {
            j = t%10;
            if(j == 7)
            {
                a[i] = 1;//与7有关
                break;
            }
            t = t/10;
        }
    }
    int n;
    while (scanf("%d",&n) != EOF)
    {
        int sum = 0;
        for(int i=0; i<=n ;i++)
        {
            if(a[i] == 0)//i为与7无关的数
            {
                sum += i*i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
