/**
最大测试数据为1e9，我们只用在100000内找其质因数即可；
因为n至多只存在一个大于sqrt(n)的质因数（否则两个相乘结果会大于n）
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
    for(int i=0; i<MAXN; i++)//初始化
    {
        IsPrime[i] = true;
    }
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(int i=2; i<MAXN; i++)
    {
        if(IsPrime[i] == false) continue;//i不是素数

        prime.push_back(i);//i为素数

        for(int j = i*i; j<MAXN; j+=i)//i的倍数均不是素数
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
    if(n != 1) return num+1;//还存在一个大于sqrt(n)的质因数
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
