#include <iostream>

using namespace std;

const int Max = 101;
int n;
int height[Max] = {0};
int dp[Max] = {0};
int ldp[Max] = {0};//�Խ��Ϊβ���Ĵ����������������
int rdp[Max] = {0};//�Խ��Ϊβ���Ĵ��ҵ��������������

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
