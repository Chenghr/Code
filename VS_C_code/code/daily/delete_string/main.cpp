#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getnext(int next[],string pattern)
{
    int i=0,k=-1;
    next[0] = -1;

    while(i < pattern.size())
    {
        if(k == -1 || pattern[i] == pattern[k])
        {
            i ++;
            k ++;
            next[i] = k;
        }
        else
        {
            k = next[k];
        }
    }

}

string KMP(string text,string pattern)
{
    int *next = new int [pattern.size()];
    getnext(next,pattern);
/*
    for(int i=0; i<pattern.size(); i++)
    {
        cout << next[i] << " ";
    }
    cout << endl;
*/
    int i=0,j=0;//均初始化为0
    while(i < text.size())
    {
        if(j == -1 || text[i] == pattern[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];
        }

        if(j == pattern.size())
        {
            text.erase(i-j,j);//从i-j开始，删除j个字符
//            cout << text << endl;
            i = i-j;
            j = 0;
        }
    }

    return text;
}

int main()
{
    string text,pattern;
    while(cin >> text >> pattern)
    {
        string result = KMP(text,pattern);
        cout << result << endl;
    }
    return 0;
}
