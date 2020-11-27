/**
����������Ϊ1e9������ֻ����100000���������������ɣ�
��Ϊn����ֻ����һ������sqrt(n)��������������������˽�������n��
**/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 10000;
bool IsPrime[MAXN];
vector<int> prime;

void initial()
{
    for(int i=0; i<MAXN; i++)//��ʼ��
    {
        IsPrime[i] = true;
    }
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(int i=2; i<MAXN; i++)
    {
        if(IsPrime[i] == false) continue;//i��������

        prime.push_back(i);//iΪ����

        for(int j = i*i; j<MAXN; j+=i)//i�ı�������������
        {
            IsPrime[j] = false;
        }
    }
}

int getprimenum(int n)
{
    int num = 0;
    for(int i=0; i<prime.size(); i++)
    {
        int temp = prime[i];
        while(n % temp == 0)
        {
            n /= temp;
            num++;
        }
        if(n == 1) break;
    }
    if(n != 1) return num+1;//������һ������sqrt(n)��������
    else return num;
}

int main()
{
    initial();
    int n;
    while(cin >> n)
    {
        cout << getprimenum(n) << endl;
    }
    return 0;
}
