#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;
int tag[MAXN];
vector<int> prime;

void initial()
{
    fill(tag,tag+MAXN,1);
    tag[0] = 0;
    tag[1] = 0;
    for(int i=2; i<MAXN; i++)
    {
        if(tag[i] == 0)
            continue;//i不为素数

        prime.push_back(i);//i为素数

        if(i <= 1000)//放置i*i越界
        {
            for(int j = i*i; j<MAXN; j += i)//i的倍数不为素数
            {
                tag[j] = 0;
            }
        }

    }
    return ;
}

int main()
{
    initial();
    int n;
    while(cin >> n)
    {
        cout << prime[n-1] << endl;
    }
    return 0;
}
