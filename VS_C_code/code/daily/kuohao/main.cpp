#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        stack<char> p;

        int tag = 1;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                p.push(s[i]);
            }
            else if(s[i] == '}')
            {
                if(p.top() == '{')
                {
                    p.pop();
                }
                else
                {
                    tag = 0;
                    break;
                }
            }
            else if(s[i] == ')')
            {
                if(p.top() == '(')
                {
                    p.pop();
                }
                else
                {
                    tag = 0;
                    break;
                }
            }
            else if(s[i] == ']')
            {
                if(p.top() == '[')
                {
                    p.pop();
                }
                else
                {
                    tag = 0;
                    break;
                }
            }
        }

        if(tag == 0 || p.size() != 0)
        {
            cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
    return 0;
}
