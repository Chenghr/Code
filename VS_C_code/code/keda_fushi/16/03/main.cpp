//�����������浽*a�����Ƚϸ�������*b�е����Ƿ����
//��ȷ��س˻������򷵻ض���֮��
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int* func(int &a, int *b, int*c)
{
    c = (int *)malloc(sizeof(int));
    if(c == NULL) exit(1);

    cin >> a;
    if(a == *b)
    {
        *c = (a)*(*b);
    }
    else
    {
        *c = (a)+(*b);
    }
    return c;
}

int main()
{
    int a, b = 5, *c;
    c = func(a,&b,c);
    cout << *c << endl;
    return 0;
}
