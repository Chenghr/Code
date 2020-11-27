#include <iostream>
#include <fstream>//�ļ������ͷ�ļ�
#include <string>
#include <cstdlib>//exit()����

using namespace std;

int main()
{
    ifstream fin;
    fin.open("test.txt");

    if(fin.is_open())//��ȡ�ļ���������
    {
        cout << "Here are current contents of the test.txt file :" << endl;

        char ch;//���ַ���ȡ�ļ������
        while(fin.get(ch))
        {
            cout << ch;
        }
        fin.close();//������ļ��Ĺ���
    }

    //���ļ�ĩβ׷���µ�����
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
        fout << words << endl;//д���ļ�
    }
    fout.close();//������ļ��Ĺ���

    fin.clear();//�ٴδ�ͬ���ļ���Ҫ���һ�»�����
    fin.open("test.txt");
    if(fin.is_open())//��ȡ�ļ���������
    {
        cout << "Here are new contents of the test.txt file :" << endl;

        char ch;//���ַ���ȡ�ļ������
        while(fin.get(ch))
        {
            cout << ch;
        }
        fin.close();//������ļ��Ĺ���
    }
    cout << "Done" << endl;
    return 0;
}
