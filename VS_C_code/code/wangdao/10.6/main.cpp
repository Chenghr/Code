#include <iostream>

using namespace std;

int main()
{
    int n,m;
    while (cin >> n >> m)
    {
        int p[201] = {0};//每个人喜欢的书籍编号
        int tag[201] = {0};//每本书被几个人喜欢

        for(int i=0; i<n; i++)
        {
            cin >> p[i];
            tag[p[i]] ++;
        }

        for(int i=0; i<n; i++)
        {
            if(tag[p[i]] == 1) cout << "BeiJu" << endl;
            else cout << tag[p[i]]-1 << endl;
        }
    }
    return 0;
}
