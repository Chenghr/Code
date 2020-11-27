#include <iostream>
#include <string>

using namespace std;

int special_mul(string x,string y)
{
    int num = 0;
    for(int i=0; i<x.size(); i++)
    {
        for(int j=0; j<y.size(); j++)
        {
            num += (x[i]-'0')*(y[j]-'0');
        }
    }
    return num;
}

int main()
{
    string x,y;
    while(cin >> x >> y)
    {
        cout << special_mul(x,y) << endl;
    }
    return 0;
}
