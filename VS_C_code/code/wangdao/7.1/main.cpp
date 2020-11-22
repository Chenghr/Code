#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string ip[1001];
string server[5001];
int n,m;
int tag[5001] = {1};

bool isdone()
{
    for(int i=0; i<m; i++)
    {
        if(tag[i] == 1) return false;
    }
    return true;
}

int getnum(string s)//当前ip能访问的最大连续未访问过得服务器数目
{
    int num = 0;
    int i=0;
    for(; i<m; i++)
    {
        if(tag[i] == 1) break;
    }
    for(; i<m; i++)
    {
        if(s == server[i]) return num;
        else
        {
            num++;
        }
    }
    return num;
}

bool comp(string x,string y)
{
    return getnum(x) > getnum(y);
}

int main()
{
    while (cin >> n)
    {
        cin.get();//吃掉整数后面的回车
        for(int i=0; i<n; i++)//输入IP地址
        {
            getline(cin,ip[i]);
        }

        cin >> m;
        cin.get();//吃掉整数后面的回车
        for(int i=0; i<m; i++)//输入服务器地址
        {
            getline(cin,server[i]);
            tag[i] = 1;//标记数组赋初值
        }

        int flag = 1;//判断是否有解

        if(n == 1)//仅当ip只有一个且在服务器中时才无解
        {
            for(int i=0; i<m; i++)
            {
                if(ip[0] == server[i]) flag = 0;
            }
        }
        int j = 0;
        int num = 0;
        while (!isdone() && flag == 1)
        {
            sort(ip, ip+n, comp);//ip地址可以重复使用
            for(; j<m; j++)
            {
                if(ip[0] == server[j]) break;
                else
                {
                    tag[j] = 0;
                }
            }
            num ++;
        }

        if(flag == 1) cout << num-1 << endl;//第一次使用服务器不算切换
        else cout << -1 << endl;
    }
    return 0;
}
