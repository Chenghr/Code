#include <stdio.h>
#include <stdlib.h>

int daytab[2][13] = {
    {
        0,31,28,31,30,31,30,31,31,30,31,30,31
    },//平年
    {
         0,31,29,31,30,31,30,31,31,30,31,30,31
    }//闰年
};//存储每月的天数

int IsLeapYear (int year)//判断是否是闰年
{
    if ( (year%4 == 0 && year%100 != 0 ) || (year%400 == 0)) return 1;
    return 0;//闰年返回1，平年返回0，与上面的daytab对应
}

int main()
{
    int y1,m1,d1,y2,m2,d2,num;
    int n;
    int i,j,tag;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d%d",&y1,&m1,&d1);
        scanf("%d%d%d",&y2,&m2,&d2);//后一天日期晚于前一天

        num = 0;//相差天数，注意相邻日期视为相距2天
        tag = IsLeapYear(y1);//标志是否为闰年

        for(j=m1; j<m2; j++)
        {
            num += daytab[tag][j];//从m1月1号开始计算
        }
        num = num-d1+d2;//m1月多算了d1天，m2月少算了d2天；

        printf("%d\n",num+1);//注意相邻日期视为相距2天,故需要加1
    }
    return 0;
}
