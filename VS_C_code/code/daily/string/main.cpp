#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int alpnum = 0;
int wordnum = 0;
int a[26] = {0};

void divide_s(string s)
{
    for(int i=0; i<s.size()-1; i++)
    {
        if(isalpha(s[i]))
        {
            alpnum ++;
            char c = tolower(s[i]);
            a[c-'a'] ++;

            if(s[i+1] == ' ') wordnum ++;
        }
    }
    if(isalpha(s[s.size()-1])) wordnum ++;
    return ;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        alpnum = 0;
        wordnum = 0;
        fill(a,a+26,0);

        divide_s(s);

        int tag = 0;
        for(int i=0; i<26; i++)
        {
            if(a[i] > a[tag]) tag = i;
        }
        char c = 'A'+tag;

        cout << "英文字母个数：" << alpnum << endl;
        cout << "单词个数： " << wordnum << endl;
        cout << "出现次数最多的字母为： " << c << " " << a[tag] << endl;
    }
    return 0;
}
