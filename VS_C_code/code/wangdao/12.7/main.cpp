#include <iostream>

using namespace std;

int main()
{
    int dp[11][11] = {0};//初始化dp数组

    for(int i=0; i<11; i++)
    {
        for(int j=1; j<11; j++)
        {
            if(i == 1 || i== 0 || j == 1) dp[i][j] = 1;
            else if(i < j) dp[i][j] = dp[i][i];
            else  dp[i][j] = dp[i][j-1]+dp[i-j][j];
        }
    }

    int m,n;
    while (cin >> m >> n)
    {
        cout << dp[m][n] << endl;
    }
    return 0;
}
