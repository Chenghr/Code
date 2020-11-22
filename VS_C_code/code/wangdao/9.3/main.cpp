#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string result[100];//存储八皇后的所有解
int q[9] = {0};//存储当前解
int num = 0;

bool IsOk(int t,int k)//第t个位置放置k是否合适
{
    for(int i=1; i<t; i++)
    {
        if(q[i] == k || abs(t-i) == abs(k-q[i]))
        {
            return false;
        }
    }
    return true;
}

void dfs(int t)//选取第t个位置
{
    if(t == 9)//搜索终点
    {
        string temp;
        for(int i=1; i<9; i++)
        {
            temp += q[i]+'0';
        }
        result[num++] = temp;
        return ;
    }

    for(int k=1; k<=8; k++)
    {
        if(IsOk(t,k))
        {
            q[t] = k;
            dfs(t+1);

            q[t] = 0;//回溯
        }
    }
    return ;
}


int main()
{
    int n;
    dfs(1);
    while(cin >> n)
    {
        cout << result[n-1] << endl;
    }
    return 0;
}
