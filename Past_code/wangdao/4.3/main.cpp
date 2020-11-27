#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin,s))
    {
       for(int i=0; i<s.size(); i++)
       {
           if(i==0 || s[i-1] == ' '|| s[i-1] == '\t'|| s[i-1] == '\r'|| s[i-1] == '\n')
           {
               if(s[i] >= 'a' && s[i] <= 'z')//Ð¡Ð´×ÖÄ¸ASCII = ´óÐ´×ÓASCII + 32
               {
                   s[i] -= 32;
               }
           }
       }
       cout << s << endl;
    }
    return 0;
}
