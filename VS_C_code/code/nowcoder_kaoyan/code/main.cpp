#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        for(int i=0; i<s.size(); i++)
        {
            if(isalpha(s[i]))//对字母进行变换
            {
                if((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && s[i] <= 'Y'))
                {
                    s[i] ++;
                }
                else if(s[i] == 'z')
                {
                    s[i] = 'a';
                }
                else
                {
                    s[i] = 'A';
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
