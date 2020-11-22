#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int tag[100] = {0};//标记数组

        for(int i=0; i<s.size()-2; i++)
        {
            if(tag[i] == 0)//第一次遇到这个字符，向后查找是否有重复字符
            {
                tag[i] = -1;
                for(int j=i+1; j<s.size();j++)
                {
                    if(s[i] == s[j])
                    {
                        if(tag[i] == -1)//第一次找到重复字符
                        {
                            cout << s[i] << ":" << i ;
                            cout << "," << s[i] << ":" << j ;
                            tag[i] = 1;
                            tag[j] = 1;
                        }
                        else//不是第一次找到重复字符
                        {
                            cout << "," << s[i] << ":" << j ;
                            tag[j] = 1;
                        }
                    }
                }
                if(tag[i] == 1)//tag从-1变为1，说明至少找到了一个重复字符
                {
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
