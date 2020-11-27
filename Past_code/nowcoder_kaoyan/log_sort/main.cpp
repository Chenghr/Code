#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

struct Log
{
    string s;//完整记录
    string name;
    string date;
    string begintime;
    int sumtime_zheng;
    int sumtime_xiao;
};

const int MAXN = 10001;

bool comp(Log x, Log y)
{
    if(x.sumtime_zheng != y.sumtime_zheng)
    {
        return x.sumtime_zheng < y.sumtime_zheng;
    }
    else if(x.sumtime_xiao != y.sumtime_xiao)
    {
        return x.sumtime_xiao < y.sumtime_xiao;
    }
    else
    {
        return x.begintime < y.begintime;
    }
}

int main()
{
    Log log[MAXN];
    string s;
    int n = 0;//日志数目
    while(getline(cin,s))
    {
        log[n].s = s;
        int pos1 = 0;
        while(s[pos1] == ' ')
            pos1 ++;
        int pos2 = pos1;
        while(s[pos2] != ' ')
            pos2 ++;
        log[n].name = s.substr(pos1,pos2);//名字
        //cout << log[n].name << endl;

        pos1 = pos2;
        while(s[pos1] == ' ')
            pos1 ++;
        pos2 = pos1;
        while(s[pos2] != ' ')
            pos2 ++;
        log[n].date = s.substr(pos1,pos2-pos1);//日期
        //cout << log[n].date << endl;

        pos1 = pos2;
        while(s[pos1] == ' ')
            pos1 ++;
        pos2 = pos1;
        while(s[pos2] != ' ')
            pos2 ++;
        log[n].begintime = s.substr(pos1,pos2-pos1);//开始时间
        //cout << log[n].begintime << endl;

        pos1 = pos2;
        while(s[pos1] == ' ')
            pos1 ++;
        pos2 = pos1;
        int temp = 0;
        while(s[pos2] != '.')
        {
            temp = temp*10+s[pos2]-'0';
            pos2++;
        }
        log[n].sumtime_zheng = temp;
        //cout << log[n].sumtime_zheng << endl;

        pos1 = pos2+1;
        temp = 0;
        while(isdigit(s[pos1]))
        {
            temp = temp*10+s[pos1]-'0';
            pos1++;
        }
        log[n].sumtime_xiao = temp;
        //cout << log[n].sumtime_xiao << endl;

        n++;
    }

    sort(log,log+n,comp);

    for(int i=0; i<n; i++)
    {
        cout << log[i].s << endl;
    }

    return 0;
}
