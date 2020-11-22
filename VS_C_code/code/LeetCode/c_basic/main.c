#include <stdio.h>
#include <stdlib.h>


//����ɸ��
int prime[10000];//�洢�ѻ�õ�����
int primesize;//��¼��������
bool mark[10001];//�������
void init()//����ɸ��
{
    int i = 1,j = 0;
    for(i=1; i<=10000; i++)//��ʼ���������
    {
        mark[i] = false;
    }
    primesize = 0;
    for(i=2; i<=10000; i++)//���α���2��10000
    {
        if(mark[i] == false) continue;//�������ѱ���ǣ�����
        prime[primesize++] = i;//���򣬴洢��õ�����
        for(j = i*i; j<=10000; j+=i)//����õ������ı������Ϊ������
        {
            mark[j] = true;
        }
    }
}


//��������
int pow(int a,int b)
{
    int ans = 1;//�洢�������
    if(a == 0 && b == 0) return 0;
    else if(b == 0) return 1;
    while(b != 0)//��b���ж�����ת����ͬʱ����a��2^k��
    {
        if(b%2 == 1)//��ǰ������λΪ1
        {
            ans = ans*a;
        }
        b = b/2;//��ǰ������λ������ϣ�������
        a = a*a;//����һλ������λ��Ȩ�أ�a����ƽ��
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
