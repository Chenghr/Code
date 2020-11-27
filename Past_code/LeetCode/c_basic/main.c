#include <stdio.h>
#include <stdlib.h>


//素数筛法
int prime[10000];//存储已获得的素数
int primesize;//记录素数个数
bool mark[10001];//标记数组
void init()//素数筛法
{
    int i = 1,j = 0;
    for(i=1; i<=10000; i++)//初始化标记数组
    {
        mark[i] = false;
    }
    primesize = 0;
    for(i=2; i<=10000; i++)//依次遍历2到10000
    {
        if(mark[i] == false) continue;//该数字已被标记，跳过
        prime[primesize++] = i;//否则，存储获得的素数
        for(j = i*i; j<=10000; j+=i)//将获得的素数的倍数标记为非素数
        {
            mark[j] = true;
        }
    }
}


//二分求幂
int pow(int a,int b)
{
    int ans = 1;//存储结果变量
    if(a == 0 && b == 0) return 0;
    else if(b == 0) return 1;
    while(b != 0)//对b进行二进制转化，同时计算a的2^k次
    {
        if(b%2 == 1)//当前二进制位为1
        {
            ans = ans*a;
        }
        b = b/2;//当前二进制位处理完毕，舍弃；
        a = a*a;//求下一位二进制位的权重，a求其平方
    }
    return ans;
}

int main()
{
    int a;
    a = pow(3,3);
    printf("%d" ,a);
    return 0;
}
