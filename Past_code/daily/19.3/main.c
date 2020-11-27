#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_ok(char ip[],int low,int high)//从low到high-1的字符转化为数字
{
    int num = 0;
    int i = low;
    for(i=low; i<high; i++)//转化
    {
        num = num*10;
        num += ip[i]-'0';
    }
    if(0 <= num && num <= 255) return 1;//合法返回1
    return 0; //不合法返回0
}

int main()
{
    char ip[20];//最大只有16个字符
    int n;
    int i,j,k;
    int length;
    int tag;

    scanf("%d",&n);
    for(i=0; i<n; i++)//n组数据
    {
        scanf("%s",ip);//输入字符串，这个ip代表的是字符数组的首地址，因此不用加取地址符&
        length = strlen(ip);//确定字符串长度；
        ip[length] = '.';//给字符串末尾加上'.'，便于后续处理

        tag = 1;
        j = 0;
        for(k=0; k<=length;k++)
        {
            if(ip[k] == '.')//j到k之间为一个ip地址
            {
                if(is_ok(ip,j,k)) //合法的话搜索下一个地址
                {
                    j = k+1;
                }
                else
                {
                    printf("No\n");
                    tag = 0;//标记不合法
                    break;//有一个不合法就不用再向下检查了
                }
            }
        }
        if(tag == 1) printf("Yes\n");//出循环是tag=1，说明不是不合法break出来的
    }
    return 0;
}
