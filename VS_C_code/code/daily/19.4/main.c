#include <stdio.h>
#include <stdlib.h>

//����ɸ��,�ҳ�1~100000�е���������
int prime[10001];//�洢�ѻ�õ�����
int primesize;//��¼��������
int mark[10001] = {0};//�������

void init()//����ɸ��
{
    int i = 0,j = 0;
    for(i=2; i<=10000; i++)//��ʼ���������,0��1����������
    {
        mark[i] =1;//��ʼ��Ĭ��2��10000��������
    }
    primesize = 0;

    for(i=2; i<=10000; i++)//���α���2��100000
    {
        if(mark[i] == 0) continue;//�������ѱ���ǣ�����
        prime[primesize++] = i;//���򣬴洢��õ�����
        for(j = i*i; j<=10000 ; j+=i)//����õ������ı������Ϊ������
        {
            mark[j] = 0;
        }
    }
}


int main()
{
    int m,n;
    int i = 0,j=0;
    init();//��ʼ������ɸ��

    scanf("%d%d",&m,&n);
    if(prime[0] > m) i=0;//�ҵ�����m�ĵ�һ������
    else
    {
        for(i=1; i<100000; i++)
        {
            if(prime[i] > m && prime[i-1] < m) break;
        }
    }
    for(j=0; j<n; i++,j++)//�������n������
    {
        printf("%d\n",prime[i]);
    }
    return 0;
}
