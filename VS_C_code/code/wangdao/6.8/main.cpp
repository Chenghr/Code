#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 10001;
int IsPrime[MAXN];//����Ƿ�������
vector<int> prime;

void initial()
{
    fill(IsPrime,IsPrime+MAXN,1);
    IsPrime[0] = 0;
    IsPrime[1] = 0;
    for(int i=2; i<MAXN; i++)
    {
        if(IsPrime[i] == 0) continue;
        prime.push_back(i);
        for(int j=i*i; j<MAXN; j+=i)
        {
            IsPrime[j] = 0;
        }
    }
}

void getntag(int ntag[],int n)//��n�������������ֽ�
{
    for(int i=0; prime[i]<n; i++)//��ÿ��С��n����������ѭ���������ݣ��ڴ洢����
    {
        int pow = 0;
        int temp = n;

        while(temp != 0)
        {
            pow += temp/prime[i];
            temp /= prime[i];
        }

        ntag[prime[i]] = pow;
    }
    return ;
}

void getatag(int atag[],int a)//��a�����ӷֽ�
{
    int sqr = sqrt(a);
    for(int i=0; prime[i] <= sqr; i++)
    {
        while(a%prime[i] == 0)//prime[i]��a��������
        {
            atag[prime[i]]++;
            a = a/prime[i];
        }
        if(a == 1) break;
    }
    if(a != 1) atag[a]++;//ʣ��һ�����ڸ���a������a��������
    return ;
}

int findk(int ntag[], int atag[], int n, int a)
{
    getatag(atag,a);
    getntag(ntag,n);

    int k = INT_MAX;
    int sqr = sqrt(a);
    for(int i=0; i <= sqr; i++)
    {
        if(atag[prime[i]] > 0)//prime[i]Ϊa��������
        {
            if(ntag[prime[i]] == 0) //prime����n����������
            {
                k = 0;
            }
            else if(k > ntag[prime[i]]/atag[prime[i]])//ȡ��ͬ�����ӵ�ָ���������С��
            {
                k = ntag[prime[i]]/atag[prime[i]];
            }
        }
    }
    return k;
}

int main()
{
    initial();//��ʼ������ɸ

    int n,a;
    while(cin >> n >> a)
    {
        int ntag[MAXN] = {0};//��n������������i�����Ŷ�Ӧָ��
        int atag[MAXN] = {0};//��a����������i�����Ŷ�Ӧָ��
        cout << findk(ntag,atag,n,a) << endl;
    }
    return 0;
}
