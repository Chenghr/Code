#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> ten_eight;
        while(n != 0)//×ª»¯
        {
            ten_eight.push_back(n%8);
            n = n/8;
        }

        for(int i=ten_eight.size()-1; i>=0; i--)
        {
            cout << ten_eight[i];
        }
        cout << endl;
    }
    return 0;
}
