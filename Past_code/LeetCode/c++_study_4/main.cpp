#include <iostream>
#include <string>
#include <vector>
//#include <array>//�������û�����ͷ�ļ�

using namespace std;

struct good
{
    string name;
    int price;
};

int main()
{
    //ָ��
    int* p1,p2;
    //������һ��ָ���ͱ���p1,��һ��int�ͱ���p2��
    //int * �� int* ���ָ�ʽ���ɣ�ǰ�߳�����c����ߣ����߳�����C++�����

    int a = 110;
    p1 = &a;
    p2 = *p1;// * ��ʾ�������
    cout << "a = " << a << "  *p1 = " << *p1 << "  p2 = " << p2 << endl;

    //��̬�����ڴ�
    //��ָ̬��
    int *pt = new int;//����һ��int�Ŀռ�
    //new����Ŀռ���Ǵ�ջ���ڴ������ڷ����,����c��malloc
    *pt = 1001;
    cout << *pt << endl;
    delete pt;//�ͷ�ptָ����ڴ�,���ǲ���ɾ��ָ��pt����;
    //deleteֻ������ɾ����new���������ڴ棬�Կ�ָ��ʹ��Ҳ�ǰ�ȫ�ģ����ǲ��ܶ�����ָ��ʹ�ã�

    //��̬����
    int n;
    cin >> n;
    int *s = new int [n];//����һ����СΪn�Ķ�̬����
    s[1] = 1;
    cout << "s[1] = " << s[1] << endl;
    cout << "*(s+1) = " << *(s+1) << endl;
    //*(s+i) �ȼ��� s[i]
    //ָ�������1�������ӵ�ֵ����ָ�������ռ�õ��ֽ���
    delete []s;//�ͷ��������飬ʹ��new [] ������ڴ�Ҫ�� delete [] ɾ��

    int b[3] = {1,2,3};
    int *b1 = b;//��������Ϊ����ĵ�һ��Ԫ�صĵ�ַ
    b1 = &b[0];//���������ʽ�ȼۣ������ַ����һ�ַ�ʽ
    cout << "length of b = " << sizeof(b) << endl;
    cout << "length of b1 = " << sizeof(b1) << endl;
    //������Ӧ��sizeof�õ����鳤�ȣ���ָ��Ӧ��sizeof�õ�ָ��ĳ��ȣ���ʹָ��ָ�����һ�����飻

    //ָ�룫�ṹ��
    good food = {"apple",360};
    good * pr = new good;
    pr = &food;
    cout << "food.name : " << food.name << "  food.price : " << food.price << endl;
    cout << "pr->name : " << pr->name << "  pr->price :" << pr->price << endl;
    //�ṹ��ָ����ʽṹ��Աʱʹ��->�����

    //vector,array,����
    //ʹ��vector��array֮ǰҪ��������ģ����
    //vector ���ƶ�̬���飬������ĩβ���������ݣ�Ҳ������ĩβ����������
    int size;
    cout << "����size�� " << endl;
    cin >> size;
    vector <int> vi;//������СΪ0��int������
    vector <int> vd(size);//������СΪsize��int�����飬����new
    /*
    array <int,5> ai;//����һ��5��int�ͱ��������飬array�������ڴ�����̬���飬n����Ϊ����
    array <int,5> bi = {1,2,3,4,5};
    ai = bi
    //���Խ�һ��array���������һ��array���󣬵������鲻��
    */
    return 0;
}
