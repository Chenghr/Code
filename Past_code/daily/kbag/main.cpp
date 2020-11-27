#include <iostream>

using namespace std;

const int MAXN = 10000;

int dp[MAXN];
int w[MAXN];//物品重量
int v[MAXN];//物品价值
int k[MAXN];//物品数量

int weight[MAXN];//拆分后物品重量
int value[MAXN];//拆分后物品价值

int main()
{
    int n,m;//n种物品，背包容量为m

    while(cin >> n >> m)
    {
        int number = 0;//分解后物品数量

        for(int i=0; i<n; i++)//输入且拆分
        {
            cin >> w[i] >> v[i] >> k[i];

            for(int j=1; j<=k[i]; j<<=1)//仿照二进制拆分，<<1等价于乘以2，不过移位操作更快
            {
                weight[number] = j*w[i];
                value[number] = j*v[i];
                number ++;
                k[i] -= j;//更新剩余数量
            }
            if(k[i] > 0)//第i种物品仍然有剩余的未分组
            {
                weight[number] = k[i]*w[i];
                value[number] = k[i]*v[i];
                number ++;
            }
        }

        for(int i=0; i<=m; i++)//dp数组初始化
        {
            dp[i] = 0;
        }

        for(int i=0; i<number; i++)//0-1背包求解
        {
            for(int j=m; j>=weight[i]; j--)
            {
                dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
            }
        }

        cout << dp[m] << endl;
    }
    return 0;
}
