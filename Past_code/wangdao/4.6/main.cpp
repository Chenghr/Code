#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool isequal(char c1,char c2)
{
    if(tolower(c1) == tolower(c2))//��c1��c2��ת��ΪСд��ĸ��ʽ
    {
        return true;
    }
    return false;
}

bool mulequal(char ch,string p,int& j)
{
    int i = j+1;
    while(i < p.size())
    {
        if(p[i] == ']')
        {
            break;
        }
        else i++;
    }
    int t = j+1;
    j = i;//��jָ��']'

    for(; t<i; t++)
    {
        if(isalpha(p[t]))//��ĸ
        {
            if(isequal(ch,p[t]))
            {
                return true;
            }
        }
        else if(ch == p[t])//��������
        {
            return true;
        }
    }
    return false;
}

bool strcomp(string t,string p)
{
    int i = 0, j = 0;
    while(i < t.size() && j < p.size())
    {
        if(isalpha(p[j]))//��ĸ
        {
            if(isequal(t[i],p[j]))
            {
                i++;
                j++;
                continue;
            }
            else return false;
        }
        else if(p[j] == '[')//��ǰjָ��'['
        {
            if(mulequal(t[i],p,j))
            {
                i ++;
                j ++;//������jָ��']'
                continue;
            }
            else return false;
        }
        else//�����ַ�
        {
            if(t[i] == p[j])
            {
                i++;
                j++;
                continue;
            }
            else return false;
        }
    }
    if(i == t.size() && j == p.size()) return true;//�����ַ���ͬʱƥ�䵽�յ����ɹ�
    return false;
}

int main()
{
    vector<string> test;
    string pattern;
    int n;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        test.push_back(s);
    }
    cin >> pattern;

    for(int i=0; i<n; i++)
    {
        string temp = test[i];
        if(strcomp(temp,pattern))
        {
            cout << i+1 << " " << temp << endl;
        }
    }
    return 0;
}
