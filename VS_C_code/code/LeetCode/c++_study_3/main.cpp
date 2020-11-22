#include <iostream>
#include <string>
using namespace std;

struct student
{
    char name[20];
    int age;
    int number;
};
//c++中可以免去struct直接用student定义变量，而在c语言中不行，因此c语言中用typedef，借此省去struct；

struct teacher
{
    string name;
    int age;
    int number;
}chinese;//声明teacher这个结构体的同时创建了chinese变量

//共用体,长度为最大成员的长度
union price
{
    int int_val;
    float float_val;
};

//共用体常用于如下情况
struct widget
{
    char band[20];
    int type;//标记共用体
    union id
    {
        int id_num;//type为1时使用
        char id_char[20];//type为其他值时使用
    } id_val;//声明id这个结构体的同时创建了id_val这个结构体变量
};

//枚举
enum color {red,orange,yellow};
//red,orange等作为符号常量，默认对应0~2；当然对应值也可以显示定义

enum bits
{
    one = 1,//不能为分号；
    four = 4,
    nine = 9,
};

int main()
{
    student a;//声明时可省略struct

    cin >> a.name >> a.age >> a.number;

    cin >> chinese.name >> chinese.age >> chinese.number;//chinese变量可以直接使用

    teacher b[10];
    b[1] = {"math", 18, 001};//初始化
    b[2] = b[1];//赋值

    widget price;
    price.type = 1;
    if(price.type == 1)
        cin >> price.id_val.id_num;
    else
        cin >> price.id_val.id_char;
    //结构标识符是结构名时，使用句点运算符；结构标识符是指向结构的指针时，使用箭头标识符

    color band;
    band = color(1);
    cout << band << endl;
    return 0;
}
