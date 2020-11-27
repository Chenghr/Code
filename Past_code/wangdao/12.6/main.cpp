//解法2：动态规划做，dp[]下标表示价值，存储数据表示当前选用的邮票数

#include <iostream>
using namespace std;

int main()
{
    int target,n;
    const int maxn = 0x7fffffff;//int型变量的最大值
    int dp[100] = {0};
    int value[20] = {0};

    while(cin >> target >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> value[i];
        }

        for(int i=0; i<=target; i++)//初始化dp数组,一定要初始化到下标为target
        {
            dp[i] = maxn;
        }
        dp[0] = 0;

        for(int i=0; i<n; i++)//依次判断是否装入第i件物品
        {
            for(int j=target; j>=value[i]; j--)//依次从后向前更新，避免使用本次更新过的dp[j-value[i]]
            {
                if(j-value[i] >= 0 && dp[j-value[i]] != maxn)//保证下标不越界
                {
                    dp[j] = min(dp[j],dp[j-value[i]]+1);
                }
            }
        }

        if(dp[target] == maxn) cout << 0 << endl;
        else cout << dp[target] << endl;
    }

    return 0;
}
/*
//解法1：基于递归＋回溯的思想

int target,n;
int value[20] = {0};
int tag[20] = {0}; // 标记是否选取
int flag = 0;//标志是否有解
int curvalue = 0;
int minnum;//最少选取邮票数
int num;//当前选取邮票数

void choose(int n)//判断是否选取当前邮票,从后向前选取
{
    if(n == -1)//搜索结束
    {
        if(curvalue == target)
        {
            flag = 1;//有解
            if(minnum > num) minnum = num;
            return ;
        }
        else return ;
    }

    if(target-curvalue >= value[n])
    {
        curvalue += value[n];
        num ++;
        tag[n] = 1;
        choose(n-1);

        curvalue -= value[n];//回溯
        num --;
    }
    tag[n] = 0;
    choose(n-1);

    return ;
}

int main()
{
    while (cin >> target >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> value[i];
            tag[i] = 0;//初始化标记数组
        }
        flag = 0;
        curvalue = 0;
        minnum = n;
        num = 0;

        choose(n-1);

        if(flag == 0) cout << 0 << endl;
        else cout << minnum << endl;
    }
    return 0;
}
*/
