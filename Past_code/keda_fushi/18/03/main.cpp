//相当于完全背包问题的变式

#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int dp[MAXN];//下标表示价值，存储所用邮票数
int w[MAXN];//物品重量
int v[MAXN];//物品价值

int main()
{
    int n,m;//m表示目标价值，n表示邮票数目
    while(cin >> m >> n)
    {
        for(int i=0; i<=m; i++)
        {
            dp[i] = 0x7fffffff-10000;//初始化dp数组为一个不可达状态
        }

        for(int i=0; i<n; i++)
        {
            cin >> v[i];
            dp[v[i]] = 1;//初始化可达状态结点
        }

        for(int i=0; i<n; i++)
        {
            for(int j=v[i]; j<=m; j++)
            {
                dp[j] = min(dp[j],dp[j-v[i]]+1);//要求最小的邮票数
            }
        }

        if(dp[m] == 0x7fffffff-10000) cout << 0 << endl;
        else cout << dp[m] << endl;
    }
    return 0;
}
