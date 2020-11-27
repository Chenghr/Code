#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int gettime(string s1,string s2)
{
    int h1,m1;
    h1 = (s1[0]-'0')*10+(s1[1]-'0');
    m1 = (s1[3]-'0')*10+(s1[4]-'0');

    int h2,m2;
    h2 = (s2[0]-'0')*10+(s2[1]-'0');
    m2 = (s2[3]-'0')*10+(s2[4]-'0');

    int t;
    if(s1 < s2)
    {
        t = (h2-h1)*60+m2-m1;
    }
    else
    {
        t = (24-h1-1)*60+(60-m1)+(h2-1)*60+m2;
    }
    return t;
}

int main()
{
    ifstream in("test.txt", ios::out);

    map<string,int> time;

    string s;
    in >> s;
    int m = s[0]-'0';
    for(int i=0; i<m; i++)
    {
        string name;
        string intime;
        string outtime;
        in >> name >> intime >> outtime;
        //cout << name << " " << intime << " " << outtime << endl;
        int temptime = gettime(intime,outtime);
        //cout << temptime << endl;;
        time[name] += temptime;
    }

    map<string,int> ::iterator temp = time.begin();
    map<string,int> ::iterator it = time.begin();
    while(it != time.end())
    {
        if(temp->second < it->second)
        {
            temp = it;
        }
        it ++;
    }
    cout << temp->first << " " << temp->second << endl;
    return 0;
}
