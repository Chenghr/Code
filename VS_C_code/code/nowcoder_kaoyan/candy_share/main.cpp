#include <iostream>

using namespace std;
const int MAXN = 1000;
int candy[MAXN];//�ǹ���
int n;//С������
int c;//��������

bool IsResult()
{
    int temp = candy[0];
    for(int i=1; i<n; i++)
    {
        if(candy[i] != temp) return false;
    }
    return true;
}

void BlowWhistle()//��ʼΪ����ʱ���ֳ�ȥ���ٵ���һ�룬�Լ����϶����һ��
{
    int share[MAXN];//������Ա�С���ѵ���Ŀ
    for(int i=0; i<n; i++)
    {
        share[i] = candy[i]/2;
    }

    c++;//������
    for(int i=0; i<n-1; i++)
    {
        candy[i] -= share[i];
        candy[i+1] += share[i];
    }
    candy[n-1] -= share[n-1];//��������߽�����
    candy[0] += share[n-1];

    for(int i=0; i<n; i++)//��������
    {
        if(candy[i]%2 == 1) candy[i]++;
    }
    return ;
}

int main()
{
    while(cin >> n)
    {
        if(n == 0) break;

        for(int i=0; i<n; i++)
        {
            cin >> candy[i];
        }
        c = 0;//��ʼ��

        while(!IsResult())
        {
            BlowWhistle();
        }

        cout << c << " " << candy[0] << endl;
    }
    return 0;
}
