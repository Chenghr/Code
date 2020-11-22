//本质为N阶上楼梯问题
#include <iostream>
using namespace std;

int result = 0;
void getresult(int n)//递归方法
{
    if(n == 0)
    {
        result ++;
        return ;
    }
    if(n >= 2)
    {
        getresult(n-1);//吃一块
        getresult(n-2);//吃两块
    }
    else//只剩一块巧克力了
    {
        getresult(n-1);
    }
    return ;
}

int main()
{
    int n;
    int dp[20] = {0};//初始化递推数组
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<20; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];//第n阶要么从n-2阶跨两步上来，要么从n-1阶跨一步上来
    }

    while (cin >> n)
    {
        cout << dp[n] << endl;

        /* 递归求解
        result = 0;
        getresult(n);
        cout << result << endl;
        */
    }
    return 0;
}
