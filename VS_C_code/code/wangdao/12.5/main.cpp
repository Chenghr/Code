#include <iostream>

using namespace std;

int main()
{
    int t,m;
    int w[101] = {0};
    int v[101] = {0};
    int dp[1001] = {0};//dp[]下标表示容量，dp[]内存储当前容量下的最大价值

    while(cin >> t >> m)
    {
        for(int i=0; i<m; i++)
        {
            cin >> w[i] >> v[i];
        }

        for(int i=0; i<t+1; i++)//初始化dp[]数组
        {
            dp[i] = {0};
        }

        for(int i=0; i<m; i++)
        {
            for(int j=t; j >= w[i]; j--)//避免更新过程中修改到dp[j-w[i]]，故从后向前更新
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }

        cout << dp[t] << endl;
    }
    return 0;
}
/*
//这个在数据比较大的时候会超时
int t,m;
int wtime[101] = {0};
int value[101] = {0};
int tag[101] = {0};//标记物品是否选取

int maxvalue = 0;
int curvalue = 0;
int curtime = 0;
void search(int n)//考虑第n个物品
{
    if(n == m)
    {
        if(maxvalue < curvalue)
        {
            maxvalue = curvalue;
        }
        return ;
    }

    if(t-curtime >= wtime[n])//选第n件物品必须保证不超重
    {
        curtime += wtime[n];
        curvalue += value[n];
        tag[n] = 1;
        search(n+1);

        curtime -= wtime[n];//回溯
        curvalue -= value[n];
        //这里写tag[n] = 0 就得不出来正确结果

    }

    tag[n] = 0;//不选取第n个物品
    search(n+1);
    return ;
}

int main()
{

    while(cin >> t >> m)
    {
        for(int i=0; i<m; i++)
        {
            cin >> wtime[i] >> value[i];
        }

        maxvalue = 0;//每组数据都要初始化
        curtime = 0;
        curvalue = 0;
        tag[101] = {0};

        search(0);

        cout << maxvalue << endl;
    }
    return 0;
}
*/
