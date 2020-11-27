#include <iostream>
#include <algorithm>

using namespace std;

struct document
{
    string num;
    string intime;
    string outtime;
};

bool comp_in(document x,document y)
{
    return x.intime < y.intime;
}

bool comp_out(document x,document y)
{
    return x.outtime > y.outtime;
}

int main()
{
    int n;
    while (cin >> n)
    {
        document* d = new document [n];
        for(int i=0; i<n; i++)
        {
            cin >> d[i].num >> d[i].intime >> d[i].outtime;
        }

        sort(d,d+n,comp_in);
        cout << d[0].num << " ";

        sort(d,d+n,comp_out);
        cout << d[0].num << endl;

    }
    return 0;
}

/*


//取巧使用map的字典序和映射特性
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  std::map<string, string> open;
  std::map<string, string> close;
  string tmp1,tmp2,tmp3;
  int n,i;
  while (cin>>n) {

        for ( i = 0; i < n; i++) {

          cin>>tmp1>>tmp2>>tmp3;
          open.insert(pair<string,string>(tmp2,tmp1));
          close.insert(pair<string,string>(tmp3,tmp1));
        }
        cout<<open.begin()->second;
        cout<<' ';
        cout<<close.rbegin()->second;
  }
  return 0;
}
*/
