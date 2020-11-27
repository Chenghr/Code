#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int n ;
    while (cin >> n)
    {
        if (n == 0) break;
        getchar();//吃掉换行

        string *path = new string [n];
        for(int i=0; i<n; i++)//初始化
        {
            path[i] = "";
        }

        for (int i=0; i<n; i++)//输入路径+标准化结构
        {
            getline(cin,path[i]);//按行输入
            if(path[i][path[i].size()-1] != '\\') //每个字符串的末尾加上\，便于判断当前文件名的结束
            {
                path[i] += '\\';//在末尾添加字符串，不能用字符数组path[i][path[i].size()] = '\\'来写
            }
        }

        for(int i=0; i<n; i++)//路径排序
        {
            for(int j=i+1; j<n; j++)
            {
                if(path[i] > path[j])
                {
                    swap(path[i],path[j]);
                }
            }
        }

        int deep = 0;//子路径的缩进数目
        int length = 0;//当前文件名的长度
        string name;//文件名字符串

        for(int j=0; j<path[0].size(); j++)//第一个路径直接输出
        {
            if(path[0][j] == '\\')
            {
                name = path[0].substr(j-length,length);//从下标为i-length处截取length个字符作为子串
                for(int k=0; k<deep; k++)
                {
                    printf("  ");
                }
                cout << name << endl;//输出文件名，注意换行

                length = 0;//重置下一个文件名的长度
                deep++;
            }
            else
            {
                length++;//文件名长度＋1
            }
        }

        for(int i=1; i<n; i++)
        {
            deep = 0;
            length = 0;
            int j = 0;

            while(path[i-1][j] == path[i][j]) //计算与上一个路径的重叠部分
            {
                if(path[i][j] == '\\')
                {
                    deep++;//重叠了一个文件名
                }
                j++;
            }

            for(; j<path[i].size(); j++)
            {
                if(path[i][j] == '\\')
                {
                    name = path[i].substr(j-length,length);//从下标为j-length处截取length个字符作为子串
                    for(int k=0; k<deep; k++)
                    {
                        cout << "  ";
                    }
                    cout << name << endl;//输出文件名，注意换行

                    length = 0;//重置下一个文件名的长度
                    deep++;
                }
                else
                {
                    length++;//文件名长度＋1
                }
            }
        }
        cout << endl;//相邻用例换行隔开
    }
    return 0;
}

