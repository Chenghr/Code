#include <stdio.h>
#include <stdlib.h>
#include <math.h>//ָ��������Ҫ��

double s_tan(double x,double y,double z)//�������������
{
    double p = (x+y+z)/2;
    return pow(p*(p-x)*(p-y)*(p-z),0.5);//0.5���ݵ��ڿ�����
}

int main()
{
    int n;
    double x,y,z;//������������
    int i;
    double s;

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%lf%lf%lf",&x,&y,&z);//��������������

        if(x+y>z && x+z>y && y+z>x)
        {
            s = s_tan(x,y,z);
            printf("%.2lf\n",s);//.2 ˵��С����������λ
        }
        else printf("NaN\n");
    }
    return 0;
}
