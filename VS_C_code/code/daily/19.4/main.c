#include <stdio.h>
#include <stdlib.h>

//素数筛法,找出1~100000中的所有素数
int prime[10001];//存储已获得的素数
int primesize;//记录素数个数
int mark[10001] = {0};//标记数组

void init()//素数筛法
{
    int i = 0,j = 0;
    for(i=2; i<=10000; i++)//初始化标记数组,0和1均不是素数
    {
        mark[i] =1;//初始化默认2到10000均是素数
    }
    primesize = 0;

    for(i=2; i<=10000; i++)//依次遍历2到100000
    {
        if(mark[i] == 0) continue;//该数字已被标记，跳过
        prime[primesize++] = i;//否则，存储获得的素数
        for(j = i*i; j<=10000 ; j+=i)//将获得的素数的倍数标记为非素数
        {
            mark[j] = 0;
        }
    }
}


int main()
{
    int m,n;
    int i = 0,j=0;
    init();//初始化素数筛法

    scanf("%d%d",&m,&n);
    if(prime[0] > m) i=0;//找到大于m的第一个质数
    else
    {
        for(i=1; i<100000; i++)
        {
            if(prime[i] > m && prime[i-1] < m) break;
        }
    }
    for(j=0; j<n; i++,j++)//依次输出n个质数
    {
        printf("%d\n",prime[i]);
    }
    return 0;
}
