#include <iostream>//ʹ��cin,cout��������ĳ�����������ͷ�ļ�
#include <climits>//�����˷��ų�������ʾ���͵�����

/*
ʹ��iostream.hʱ��ʡ�ԣ�ʹ��iostreamʱ����ʡ��
ʹ���к������ܷ������ƿռ�std
*/
using namespace std;


int main()
{
    cout << "�ַ���";
    cout << endl;//endl��ʾ����һ�У�����c�����е�\n��
    cout << "\n";
    cout << "Hello world!" << endl;

    int a ;//������ʹ��ǰ��������
    int b ;
    int c;
    a = b = c = 1;//����������ֵ
    cout << a << endl;
    cin >> a;
    cout << "Now a = " << a << endl;

    int n_int = INT_MAX;
    short n_short = SHRT_MIN;
    cout << "The max int is " << n_int << endl;
    cout << "The min short is " << n_short << endl;

    const int month = 12;//�̶�month����Ϊ12�������޸�,����c���������#define
    return 0;
}
