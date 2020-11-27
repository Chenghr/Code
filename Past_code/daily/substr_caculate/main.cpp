//给出一个由01组成的字符串，求其每个子串出现的次数
//map底层使用红黑树实现的，内部仍然会将元素按照关键字排序

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    string str;
    while(cin >> str)
    {
        map<string,int> number;

        for(int i=0; i<=str.size(); i++)//i作为子串结束下标
        {
            for(int j=0; j<i; j++)//j为子串开始下标
            {
                string key = str.substr(j,i-j);//获取子串
                number[key] ++;//子串出现次数+1
            }
        }

        map<string,int> :: iterator it;//定义遍历map的迭代器

        for(it = number.begin(); it != number.end(); it++)
        {
            if(it->second > 1)//利用迭代器访问map中元素
            {
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}
