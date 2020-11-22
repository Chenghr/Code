#include <iostream>

using namespace std;

int n;
int weight[20];
int tag[20] = {0};
int curweight;
int result = 0;

void dfs(int i)//探索第i个结点
{
    if(i == n)
    {
        if(curweight == 40)
        {
            result ++;
        }
        return ;
    }

    if(curweight + weight[i] <= 40)
    {
        curweight += weight[i];
        tag[i] = 1;
        dfs(i+1);

        curweight -=weight[i];//回溯
    }
    tag[i] = 0;
    dfs(i+1);
    return ;
}

int main()
{
    while (cin >> n)
    {
        for (int i=0; i<n; i++)
        {
            cin >> weight[i];
            tag[i] = 0;
        }

        result = 0;
        dfs(0);

        cout << result << endl;

    }
    return 0;
}
