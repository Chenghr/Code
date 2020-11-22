#include <stdio.h>
#include <stdlib.h>
#include <math.h>//指数函数需要用

double s_tan(double x,double y,double z)//计算三角形面积
{
    double p = (x+y+z)/2;
    return pow(p*(p-x)*(p-y)*(p-z),0.5);//0.5次幂等于开根号
}

int main()
{
    int n;
    double x,y,z;//存三角形三边
    int i;
    double s;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lf%lf%lf",&x,&y,&z);//输入三角形三边

        if(x+y>z && x+z>y && y+z>x)
        {
            s = s_tan(x,y,z);
            printf("%.2lf\n",s);//.2 说明小数点后输出两位
        }
        else printf("NaN\n");
    }
    return 0;
}
