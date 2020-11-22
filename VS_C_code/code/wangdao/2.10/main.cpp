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
        getchar();//�Ե�����

        string *path = new string [n];
        for(int i=0; i<n; i++)//��ʼ��
        {
            path[i] = "";
        }

        for (int i=0; i<n; i++)//����·��+��׼���ṹ
        {
            getline(cin,path[i]);//��������
            if(path[i][path[i].size()-1] != '\\') //ÿ���ַ�����ĩβ����\�������жϵ�ǰ�ļ����Ľ���
            {
                path[i] += '\\';//��ĩβ����ַ������������ַ�����path[i][path[i].size()] = '\\'��д
            }
        }

        for(int i=0; i<n; i++)//·������
        {
            for(int j=i+1; j<n; j++)
            {
                if(path[i] > path[j])
                {
                    swap(path[i],path[j]);
                }
            }
        }

        int deep = 0;//��·����������Ŀ
        int length = 0;//��ǰ�ļ����ĳ���
        string name;//�ļ����ַ���

        for(int j=0; j<path[0].size(); j++)//��һ��·��ֱ�����
        {
            if(path[0][j] == '\\')
            {
                name = path[0].substr(j-length,length);//���±�Ϊi-length����ȡlength���ַ���Ϊ�Ӵ�
                for(int k=0; k<deep; k++)
                {
                    printf("  ");
                }
                cout << name << endl;//����ļ�����ע�⻻��

                length = 0;//������һ���ļ����ĳ���
                deep++;
            }
            else
            {
                length++;//�ļ������ȣ�1
            }
        }

        for(int i=1; i<n; i++)
        {
            deep = 0;
            length = 0;
            int j = 0;

            while(path[i-1][j] == path[i][j]) //��������һ��·�����ص�����
            {
                if(path[i][j] == '\\')
                {
                    deep++;//�ص���һ���ļ���
                }
                j++;
            }

            for(; j<path[i].size(); j++)
            {
                if(path[i][j] == '\\')
                {
                    name = path[i].substr(j-length,length);//���±�Ϊj-length����ȡlength���ַ���Ϊ�Ӵ�
                    for(int k=0; k<deep; k++)
                    {
                        cout << "  ";
                    }
                    cout << name << endl;//����ļ�����ע�⻻��

                    length = 0;//������һ���ļ����ĳ���
                    deep++;
                }
                else
                {
                    length++;//�ļ������ȣ�1
                }
            }
        }
        cout << endl;//�����������и���
    }
    return 0;
}

