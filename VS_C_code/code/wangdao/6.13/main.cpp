#include <iostream>
#include <vector>
#include <string>

using namespace std;

int strdiv(string x,int y)//x能整除y则返回1，否则返回0
{
    int remain = 0;
    for(int i=0; i < x.size(); i++)
    {
        int cur = x[i]-'0'+remain*10;
        remain = cur%y;
    }
    if(remain == 0) return 1;
    return 0;
}

int main()
{
    string x;
    while(cin >> x)
    {
        if(x == "-1") break;

        vector<int> ans;

        for(int i=2; i<=9; i++)
        {
            if(strdiv(x,i) == 1)
            {
                ans.push_back(i);
            }
        }

        if(ans.size() == 0) cout << "none" << endl;
        else
        {
            for(int i=0; i<ans.size()-1; i++)
            {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size()-1] << endl;
        }

    }
    return 0;
}
