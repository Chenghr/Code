#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const int MAXN = 10000;

int a[MAXN];

int findpos(int i,int d)
{
    int pos=0;
    for(pos=i-1; pos>=0; pos--)
    {
        if(a[i]-a[pos] == d) return pos;
    }
    return -1;
}

int getmaxlen(int n)
{
    int maxd = a[n-1]-a[0];

    int **dp = new int*[n];//动态创建二维数组
    for(int i=0; i<n; i++)
    {
        dp[i] = new int[maxd+1];
    }

    for(int i=0; i<n; i++)//初始化
    {
        for(int j=0; j<=maxd; j++)
        {
            dp[i][j] = 1;//dp[i][j]表示第i个元素结尾的公差j的等差序列长度
        }
    }

    int maxlen = 0;
    for(int d=1; d<=maxd; d++)
    {
        for(int j=1; j<n; j++)//从数组的第二个元素开始找
        {
           int pos = findpos(j,d);
           if(pos != -1)
           {
               dp[j][d] = dp[pos][d]+1;
               maxlen = max(maxlen,dp[j][d]);
           }
        }
    }
    return maxlen;
}

int main()
{
    string s;
    while(getline(cin,s))
    {
        int n = 0;
        for(int i=0; i<s.size(); i++)
        {
            int temp = 0;
            while(s[i] != ' ')
            {
                temp = temp*10+s[i]-'0';
                i++;
            }
            a[n++] = temp;
        }

        int maxlen = getmaxlen(n);
        cout << maxlen << endl;
    }
    return 0;
}
