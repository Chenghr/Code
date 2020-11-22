#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int sum = 0;
        int i=s.size()-1;
        int j=1;
        for (; i>=0; i--,j++)
        {
            sum += (s[i]-'0') * ((int)pow(2,j)-1);
        }
        cout << sum << endl;
    }
    return 0;
}
