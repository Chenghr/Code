#include <iostream>
#include <string>

using namespace std;

int main()
{
    string x,y;
    int dp[101][101] = {0};
    while (cin >> x >> y)
    {
        for(int i=0; i<x.size()+1; i++)
        {
            for(int j=0; j<y.size()+1; j++)
            {
                if(i == 0 || j == 0) //±ß½ç´¦Àí
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if(x[i-1] == y[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else
                    {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }

        cout << dp[x.size()][y.size()] << endl;

    }
    return 0;
}
