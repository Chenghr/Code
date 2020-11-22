#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,string> student;//将学号作为key，信息作为value

int main()
{
    int n;
    cin >> n;
    cin.get();//吃掉回车

    for(int i=0; i<n; i++)
    {
        string s;
        getline(cin,s);//注意本题的输入格式，可以用一行字符串读入所有信息；

        int pos = 0;
        for(pos=0; pos<s.size(); pos++)//找到第一个空格
        {
            if(s[pos] == ' ') break;
        }
        string num = s.substr(0,pos);//获取学号
        student[num] = s;//学号作为key，存储value
    }

    int m;
    cin >> m;

    for(int i=0; i<m; i++)
    {
        string num;
        cin >> num;
        string s = student[num];
        if(s == "")//查找失败
        {
            cout << "No Answer!" << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}
