#include <iostream>
#include <string>
#include <cstring>

using namespace std;

string s;
int length;
int tag[7] = {0};//标记字符是否已经使用
char result[7] ;

void getresult(int pos)
{
    if(pos == length)//搜索到终点
    {
        for(int i=0; i<length; i++)
        {
            cout << result[i];
        }
        cout << endl;
        return ;
    }
    for (int i=0; i<length; i++)//按照字典序从小到大查找能用的字符
    {
        if(tag[i] == 0)//未被使用过
        {
            result[pos] = s[i];
            tag[i] = 1;
            getresult(pos+1);//找下一个的位置
            tag[i] = 0;//回溯
        }
    }
}

int main()
{
    while (cin >> s)
    {
        sort(s.begin(),s.end());//对字符串进行字典序排序
        length = s.size();
        getresult(0);
        cout << endl;//每组样例输出后输出一个回车
    }
    return 0;
}
