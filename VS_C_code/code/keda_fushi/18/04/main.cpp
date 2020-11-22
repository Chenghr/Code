#include <iostream>
#include <string>

using namespace std;

const int MAXN = 101;

int main()
{
    int dp[MAXN][MAXN] = {0};
    string x,y;
    while(cin >> x >> y)
    {
        for(int i=0; i<=x.size(); i++)
        {
            for(int j=0; j<=y.size(); j++)
            {
                if(i == 0 || j == 0)//±ß½ç´¦Àí
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(x[i-1] == y[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        cout << dp[x.size()][y.size()] << endl;
    }
    return 0;
}
