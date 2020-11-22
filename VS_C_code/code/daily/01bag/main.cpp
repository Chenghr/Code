#include <iostream>

using namespace std;
const int MAXN = 1001;

int dp[MAXN];//下标表示容量，内容表示价值；在不同题目中，指代内容可更改，思路最重要
int w[MAXN];//物品重量
int v[MAXN];//物品价值

int main()
{
    int n,m;//n件物品，容量为m
    while(cin >> n >> m)
    {
        for(int i=0; i<n; i++)//输入
        {
            cin >> w[i] >> v[i];
        }

        for(int i=0; i<=m; i++)//初始化dp数组,注意i<=m,要更新到m
        {
            dp[i] = 0;
        }

        for(int i=0; i<n; i++)//依次判断第i件物品
        {
            for(int j=m; j >= w[i]; j--)//逆序更新； j>=w[i]是为了保证 dp[j-w[i]]下标不为负
            {
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);//dp[j]表示不选取第i件物品，dp[j-w[i]]+v[i]表示选取第i件物品
            }
        }

        cout << dp[m] << endl;
    }
    return 0;
}
