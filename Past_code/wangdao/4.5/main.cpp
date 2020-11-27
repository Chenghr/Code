#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        vector <string> sub;
        for(int i=0; i<s.size(); i++)//»ñÈ¡×Ó´®
        {
            sub.push_back(s.substr(i,s.size()-i));
        }

        for(int i=0; i<sub.size()-1; i++)
        {
            for(int j=i+1; j<sub.size(); j++)
            {
                if(sub[i] > sub[j])
                {
                    string temp = sub[i];
                    sub[i] = sub[j];
                    sub[j] = temp;
                }
            }
        }

        for(int i=0; i<sub.size(); i++)
        {
            cout << sub[i] << endl;
        }
    }
    return 0;
}
