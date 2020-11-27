#include <stdio.h>
#include <stdlib.h>

int daytab[2][13] = {
    {
        0,31,28,31,30,31,30,31,31,30,31,30,31
    },//ƽ��
    {
         0,31,29,31,30,31,30,31,31,30,31,30,31
    }//����
};//�洢ÿ�µ�����

int IsLeapYear (int year)//�ж��Ƿ�������
{
    if ( (year%4 == 0 && year%100 != 0 ) || (year%400 == 0)) return 1;
    return 0;//���귵��1��ƽ�귵��0���������daytab��Ӧ
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
        scanf("%d%d%d",&y2,&m2,&d2);//��һ����������ǰһ��

        num = 0;//���������ע������������Ϊ���2��
        tag = IsLeapYear(y1);//��־�Ƿ�Ϊ����

        for(j=m1; j<m2; j++)
        {
            num += daytab[tag][j];//��m1��1�ſ�ʼ����
        }
        num = num-d1+d2;//m1�¶�����d1�죬m2��������d2�죻

        printf("%d\n",num+1);//ע������������Ϊ���2��,����Ҫ��1
    }
    return 0;
}
