#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a[101] = {0};
    for(int i=1; i<101; i++)//Ԥ����,���ҳ�0~100����7�йص���
    {
        if(i%7 == 0) a[i] = 1;//��7�й�
        int t = i,j = 0;
        while(t != 0)
        {
            j = t%10;
            if(j == 7)
            {
                a[i] = 1;//��7�й�
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
            if(a[i] == 0)//iΪ��7�޹ص���
            {
                sum += i*i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
