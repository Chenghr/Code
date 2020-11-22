#include <iostream>

using namespace std;

const int Max = 101;
int n;
int height[Max] = {0};
int dp[Max] = {0};
int ldp[Max] = {0};//以结点为尾结点的从左到右最长上升子序列
int rdp[Max] = {0};//以结点为尾结点的从右到左最长上升子序列

void dp_left()
{
    for(int i=0; i<n; i++)
    {
        ldp[i] = 1;
        for(int j=0; j<i; j++)
        {
            if(height[i] > height[j] && ldp[i] < ldp[j]+1)
            {
                ldp[i] = ldp[j]+1;
            }
        }
    }
}

void dp_right()
{
    for(int i=n-1; i>=0; i--)
    {
        rdp[i] = 1;
        for(int j=n-1; j>i; j--)
        {
            if(height[i] > height[j] && rdp[i] < rdp[j]+1)
            {
                rdp[i] = rdp[j]+1;
            }
        }
    }
}
int main()
{
    while (cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> height[i];
        }

        dp_left();
        dp_right();

        int result = 0;
        for(int i=0; i<n; i++)
        {
            if(i == 0 || i == n-1)
            {
                dp[i] = (ldp[i] > rdp[i]) ? ldp[i] : rdp[i];
            }
            else
            {
                dp[i] = ldp[i]+rdp[i]-1;i
            }
            if(result < dp[i])
            {
                result = dp[i];
            }
        }

        cout << n-result << endl;
    }
    return 0;
}
