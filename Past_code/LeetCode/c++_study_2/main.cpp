#include <iostream>
#include <string>
#include <cstring>//Ϊ��ʹ��strlen����������c���Ե�string����

using namespace std;

int main()
{
    //����
    int month[12];
    int a[3] = {1,2,3};
    int b[] = {1,2,3,4};//ϵͳ�Զ���������Ԫ��Ϊ4��
    int c[5] = {0};//����Ԫ�س�ʼ��Ϊ0��
    int c1[5] = {};//Ч��ͬ��
    int c2[5] {};//��ʼ�������ʡ�ԵȺ�
    int d[5] = {1};//��һ��Ԫ��Ϊ1������Ԫ��Ϊ0

    //�ַ���
    char s1[3] = {'a','b','c'};
    char s2[3] = {'a','b','\0'};//��s2Ϊ�ַ�����s1�����ַ�����ȱ�ٿ��ַ�'\0'
    char s3[] = "apple";//�ַ���������ʹ��˫���ţ����ַ�������ʹ�õ����ţ���Ĭ���ڵ��ʺ���Ƕ����ַ�

    const int size = 15;//size һ��Ҫ��const���Σ������������������鳤��
    char name1[size];//������
    char name2[size] = "chr";
    cout << "name2 ��Ԫ�ظ���Ϊ " << strlen(name2) << endl;//strlen()��������ַ��������ؿɼ����ַ����ȣ�
    cout << "name2 �����鳤��Ϊ " << sizeof(name2) << endl;//sizeof()�������鳤��
    /*
    cin >> name1;//cinʹ�ÿհ���ȷ���ַ����Ľ���λ�ã�����ȡ�ַ���������ʱ�ƶ�ȥһ�����ʣ����������ĩβ��ӿ��ַ�
    cin.getline(name2,15);
    //cin.getline( , )һ�ζ���һ���ַ������Իس�ȷ����β�����ÿհ׷�����س� t
    //�ڶ�����������ȷ����ȡ�������Ŀ��������ֻ�ܶ�ȡ14���ַ�

    cin.get(name1,size);//����cin.getline(),�������ڲ��Ե��س������س����δ����ڻ�������
    cin.get();//�����κβ�����cin.get()�ɶ�ȡ��һ���ַ����Ե��������Ļس�����
    cout << "Hello world!" << endl;
    */
    string str1;
    string str2 = "apple";
    cin >> str1;//str1������������һ������Ϊ0��string��������ʱ�Զ���������
    str1 = str2;//string��������໥��ֵ��c������strcpy(,)�Ĺ���
    string str3;
    str3 = str1+str2;// + �������ַ����ϲ���C���Ե��е�strcat(,)�Ĺ���
    cin.get();//�Ե�cin���µĿո�
    getline(cin,str1);
    cout << str1 << endl << str2 << endl << str3 << endl;
    str1 += str2;//��str2�ӵ�str1��ĩβ
    int len = str1.size();


    return 0;
}
