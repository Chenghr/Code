#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    stack <int> s;
    int n;
    string temp;

    while (cin >> n)
    {
        if(n == 0) break;

        cin.get();
        for(int i=0; i<n; i++)
        {
            getline(cin,temp);
            if(temp[0] == 'P')
            {
                int a = 0;
                for(int j=2; j<=temp.size()-1; j++)//字符后面有个空格
                {
                    a = a*10+temp[j]-'0';
                }
                s.push(a);
            }
            else if(temp[0] == 'O' && !s.empty())
            {
                s.pop();
            }
            else if(temp[0] == 'A')
            {
                if(!s.empty()) cout << s.top() << endl;
                else cout << "E" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
