#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int temp;
        vector<char> result;

        while(n != 0)
        {
            temp = n%16;
            if(temp <= 9)
            {
                result.push_back(temp+'0');
            }
            else
            {
                temp -= 10;
                result.push_back(temp+'A');
            }

            n = n/16;
        }

        for(int i=result.size()-1; i>=0; i--)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}
