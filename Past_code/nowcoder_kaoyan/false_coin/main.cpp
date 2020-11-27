#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x,y;
    while(cin >> x >> y)
    {
        while(x != y)
        {
            x > y ? x /= 2 : y /= 2;
        }
        cout << x << endl;
    }
    return 0;
}
