#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

const int MAXN = 10001;
int IsPrime[MAXN];//标记是否是素数
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

void getntag(int ntag[],int n)//对n！进行质因数分解
{
    for(int i=0; prime[i]<n; i++)//对每个小于n的素数进行循环除，求幂，在存储起来
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

void getatag(int atag[],int a)//对a质因子分解
{
    int sqr = sqrt(a);
    for(int i=0; prime[i] <= sqr; i++)
    {
        while(a%prime[i] == 0)//prime[i]是a的质因子
        {
            atag[prime[i]]++;
            a = a/prime[i];
        }
        if(a == 1) break;
    }
    if(a != 1) atag[a]++;//剩下一个大于根号a的数是a的质因子
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
        if(atag[prime[i]] > 0)//prime[i]为a的质因子
        {
            if(ntag[prime[i]] == 0) //prime不是n！的质因子
            {
                k = 0;
            }
            else if(k > ntag[prime[i]]/atag[prime[i]])//取相同质因子的指数相除的最小的
            {
                k = ntag[prime[i]]/atag[prime[i]];
            }
        }
    }
    return k;
}

int main()
{
    initial();//初始化素数筛

    int n,a;
    while(cin >> n >> a)
    {
        int ntag[MAXN] = {0};//若n！存在质因数i，则存放对应指数
        int atag[MAXN] = {0};//若a存在质因数i，则存放对应指数
        cout << findk(ntag,atag,n,a) << endl;
    }
    return 0;
}
