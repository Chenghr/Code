#include <iostream>
using namespace std;

void ten_two(int n)//ʮ����ת��Ϊ������
{
    int a[20];//�洢ת����Ķ�������
    int pos = 0,num = -1;

    while(n)//ת��Ϊ�����ƣ�ע��������洢
    {
        a[pos] = n%2;
        if(a[pos] == 1)
        {
            num++;//�ж϶��ٸ���Чλ�����ں�������Ӻ�
        }
        pos++;
        n /= 2;
    }

    for (int i=pos-1; i>=0; i--)
    {
        if(i>1 && a[i]==1)//����2
        {
            cout << "2(";
            ten_two(i);
            cout << ")";
        }
        else if (i == 1 && a[i] == 1)//����2
        {
            cout << "2";
        }
        else if (i == 0 && a[i] == 1)//����1
        {
            cout << "2(0)";
        }
        if(a[i] == 1 && num > 0)//�м�λ����Ӻ�
        {
            cout << "+";
            num --;
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        ten_two(n);
        cout << endl;
    }
    return 0;
}

