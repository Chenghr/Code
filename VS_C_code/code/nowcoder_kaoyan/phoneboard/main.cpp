#include <iostream>
#include <string>

using namespace std;

int keytab[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,
                    1,2,3,4,1,2,3,1,2,3,4};
//如果两个字符同属于一个按键，那么字母本身的间距等于它们按键次数的差；
//反之，如果不等，那么这两个字母必属于不同的按键

int main()
{
    string s;
    while(cin >> s)
    {
        int time = 0;
        for(int i=0; i<s.size(); i++)
        {
            time += keytab[s[i]-'a'];//输入时间

            if(i != 0 && s[i]-s[i-1] == keytab[s[i]-'a']-keytab[s[i-1]-'a'])//判断是否需要等待
            {
                time += 2;
            }
        }
        cout << time << endl;
    }
    return 0;
}
