#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if(n == 0) break;

        map <int,int> score;
        for(int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            score[x] ++;
        }

        int num;
        cin >> num;
        cout << score[num] << endl;
    }
    return 0;
}
