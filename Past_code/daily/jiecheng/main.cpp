#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n_jiecheng(int n)
{
    int result = 1;
    for(int i=1; i<=n; i++)
    {
        result = (result*i)%100000;
    }
    return result;
}

int getresult(int n)
{
    int result = 0;
    for(int i=1; i<=n; i++)
    {
        result += n_jiecheng(i);
        result = result%100000;
    }
    return result;
}

int main()
{
    int n;
    while(cin >> n)
    {
        if(n >= 25) cout << "000000" << endl;
        else
        {
            int result = getresult(n);

            string temp;
            while(result != 0)
            {
                char c = result%10+'0';
                result /= 10;
                temp += c;
            }

            for(int i=temp.size(); i<6; i++)
            {
                temp += '0';
            }

            reverse(temp.begin(),temp.end());
            cout << temp << endl;
        }
    }
    return 0;
}
