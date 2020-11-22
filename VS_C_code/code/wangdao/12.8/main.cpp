#include <iostream>
using namespace std;

int main()
{
    int dp[1000001] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=1000000; i++)
    {
        if(i%2 == 0)
        {
            dp[i] = (dp[i-1]+dp[i/2]) % 1000000000;
        }
        else
        {
            dp[i] = dp[i-1] % 1000000000;
        }
    }
    int n;
    while (cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}
/*
代码越界了，TMD还不知道为啥，吐了

//视为完全背包问题，每件物品可以重复选取；
//物品的花费依次为1,2,4,8... ，最大n为1000000，故20件物品够用了
//dp[i][j]表示前i种物品恰装满容量大小为j的背包的方案总数；
//dp[i][j] = dp[i-1][j]+dp[i-1][j-a[i]],可进一步简化为dp[j]
//给定n 输出对应的dp[n]即可

#include <iostream>
using namespace std;

int main()
{
    long long dp[1000001];
    long long value[21];
    value[0] = 1;
    for(int i=1; i<=20; i++)//初始化
    {
        value[i] = value[i-1]*2;
    }
    for(int i=0; i<=1000000; i++)
    {
        dp[i] = 1;
    }

    for(int i=1; i<=20; i++)
    {
        for( long long j=value[i]; j<=1000000; j++)
        {
            dp[j] = dp[j]+dp[j-value[i]];
            if(dp[j] >= 1000000000) dp[i] = dp[i]%1000000000;
        }
    }

    int n;
    while(cin >> n)
    {
        cout << dp[n] << endl;
    }
    return 0;
}
*/
