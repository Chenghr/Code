#include <iostream>
#include <string>
using namespace std;

struct student
{
    char name[20];
    int age;
    int number;
};
//c++�п�����ȥstructֱ����student�������������c�����в��У����c��������typedef�����ʡȥstruct��

struct teacher
{
    string name;
    int age;
    int number;
}chinese;//����teacher����ṹ���ͬʱ������chinese����

//������,����Ϊ����Ա�ĳ���
union price
{
    int int_val;
    float float_val;
};

//�����峣�����������
struct widget
{
    char band[20];
    int type;//��ǹ�����
    union id
    {
        int id_num;//typeΪ1ʱʹ��
        char id_char[20];//typeΪ����ֵʱʹ��
    } id_val;//����id����ṹ���ͬʱ������id_val����ṹ�����
};

//ö��
enum color {red,orange,yellow};
//red,orange����Ϊ���ų�����Ĭ�϶�Ӧ0~2����Ȼ��ӦֵҲ������ʾ����

enum bits
{
    one = 1,//����Ϊ�ֺţ�
    four = 4,
    nine = 9,
};

int main()
{
    student a;//����ʱ��ʡ��struct

    cin >> a.name >> a.age >> a.number;

    cin >> chinese.name >> chinese.age >> chinese.number;//chinese��������ֱ��ʹ��

    teacher b[10];
    b[1] = {"math", 18, 001};//��ʼ��
    b[2] = b[1];//��ֵ

    widget price;
    price.type = 1;
    if(price.type == 1)
        cin >> price.id_val.id_num;
    else
        cin >> price.id_val.id_char;
    //�ṹ��ʶ���ǽṹ��ʱ��ʹ�þ����������ṹ��ʶ����ָ��ṹ��ָ��ʱ��ʹ�ü�ͷ��ʶ��

    color band;
    band = color(1);
    cout << band << endl;
    return 0;
}
