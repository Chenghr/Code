#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    ifstream fin("input1.txt");
    string s;
    getline(fin,s);

    int pos = 0;//消除字符串首部的空格
    while(s[pos] == ' ') pos++;
    s = s.substr(pos);

    string result;
    for(int i=0; i<s.size(); i++)
    {

        if(s[i] == ' ')//处理空格
        {
            int j=0;
            while(s[i+j+1] == ' ')
            {
                j++;
            }
            i += j;
            result += " ";
        }
        else if(i == 0 || s[i-1] == ' ')
        {
            result += toupper(s[i]);
        }
        else result += s[i];
    }

    for(pos=result.size()-1; pos>=0; pos--)//去除末尾空格
    {
        if(result[pos] != ' ') break;
    }
    result = result.substr(0,pos+1);

    cout << result << endl;
    return 0;
}
