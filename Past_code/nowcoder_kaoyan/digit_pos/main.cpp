#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        string s;
        cin >> s;
        for(int i=0; i<s.size(); i++)
        {
            if(isdigit(s[i])) cout << i+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
