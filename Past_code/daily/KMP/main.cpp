#include <iostream>
#include <string>

using namespace std;

const int MAXN = 10000;
int next[MAXN];

void GetNextTable(string pattern)//����next��������ʹ��pattern�Լ����Լ�ƥ�������next����
{
    next[0] = -1;//��ʼ��
    int k = -1, j = 0;

    while(j < pattern.size())//��ÿ���Ӵ�������Ӧ��nextֵ
    {
        if(k == -1 || pattern[j] == pattern[i])
        {
            k ++;
            j ++;
            next[j] = k;
        }
        else
        {
            k = next[k];//next[i]��С��i��
        }
    }
}

int KMP(string test, string pattern)
{
    GetNextTable(pattern);
    int i = 0, j = 0;
    while(i < test.size() && j < pattern.size())
    {
        if(j == -1 || test[i] == pattern[j])
        {
            i ++;
            j ++;
        }
        else
        {
            j = next[j];//��ǰ�ַ���ƥ��ʧ�ܣ��ƶ�ģʽ��ָ��
        }
    }
    if(j == m) //ƥ��ɹ�
    {
        return i-j+1;//���ص�һ��ƥ�䴮�±�
    }
    else return -1;//ƥ��ʧ��
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
