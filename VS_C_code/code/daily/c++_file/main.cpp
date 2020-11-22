#include <iostream>
#include <fstream>//文件处理的头文件
#include <string>
#include <cstdlib>//exit()函数

using namespace std;

int main()
{
    ifstream fin;
    fin.open("test.txt");

    if(fin.is_open())//读取文件已有内容
    {
        cout << "Here are current contents of the test.txt file :" << endl;

        char ch;//按字符读取文件并输出
        while(fin.get(ch))
        {
            cout << ch;
        }
        fin.close();//解除与文件的关联
    }

    //向文件末尾追加新的内容
    ofstream fout("test.txt",ios::out | ios::app);
    if(!fout.is_open())
    {
        cout << "Can't open!" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter some words :" << endl;
    string words;
    while(getline(cin,words) && words.size() > 0)
    {
        fout << words << endl;//写入文件
    }
    fout.close();//解除与文件的关联

    fin.clear();//再次打开同名文件，要清空一下缓冲区
    fin.open("test.txt");
    if(fin.is_open())//读取文件已有内容
    {
        cout << "Here are new contents of the test.txt file :" << endl;

        char ch;//按字符读取文件并输出
        while(fin.get(ch))
        {
            cout << ch;
        }
        fin.close();//解除与文件的关联
    }
    cout << "Done" << endl;
    return 0;
}
