#include <iostream>
#include <string>
#include <vector>
//#include <array>//这里好像没有这个头文件

using namespace std;

struct good
{
    string name;
    int price;
};

int main()
{
    //指针
    int* p1,p2;
    //创建了一个指针型变量p1,和一个int型变量p2；
    //int * 和 int* 两种格式均可，前者常用于c编程者，后者常用于C++编程者

    int a = 110;
    p1 = &a;
    p2 = *p1;// * 表示解除引用
    cout << "a = " << a << "  *p1 = " << *p1 << "  p2 = " << p2 << endl;

    //动态分配内存
    //动态指针
    int *pt = new int;//分配一个int的空间
    //new分配的空间均是从栈的内存区域内分配的,类似c的malloc
    *pt = 1001;
    cout << *pt << endl;
    delete pt;//释放pt指向的内存,但是不会删除指针pt本身;
    //delete只能用来删除由new分配来的内存，对空指针使用也是安全的，但是不能对正常指针使用；

    //动态数组
    int n;
    cin >> n;
    int *s = new int [n];//申请一个大小为n的动态数组
    s[1] = 1;
    cout << "s[1] = " << s[1] << endl;
    cout << "*(s+1) = " << *(s+1) << endl;
    //*(s+i) 等价于 s[i]
    //指针变量加1后，其增加的值等于指向的类型占用的字节数
    delete []s;//释放整个数组，使用new [] 分配的内存要用 delete [] 删除

    int b[3] = {1,2,3};
    int *b1 = b;//数组名视为数组的第一个元素的地址
    b1 = &b[0];//和上述表达式等价，赋予地址的另一种方式
    cout << "length of b = " << sizeof(b) << endl;
    cout << "length of b1 = " << sizeof(b1) << endl;
    //对数组应用sizeof得到数组长度，对指针应用sizeof得到指针的长度，即使指针指向的是一个数组；

    //指针＋结构体
    good food = {"apple",360};
    good * pr = new good;
    pr = &food;
    cout << "food.name : " << food.name << "  food.price : " << food.price << endl;
    cout << "pr->name : " << pr->name << "  pr->price :" << pr->price << endl;
    //结构体指针访问结构成员时使用->运算符

    //vector,array,数组
    //使用vector，array之前要声明包含模板类
    //vector 类似动态数组，可以在末尾附加新数据，也可以在末尾附加新数据
    int size;
    cout << "输入size： " << endl;
    cin >> size;
    vector <int> vi;//创建大小为0的int型数组
    vector <int> vd(size);//创建大小为size的int型数组，类似new
    /*
    array <int,5> ai;//创建一个5个int型变量的数组，array不可用于创建动态数组，n必须为常量
    array <int,5> bi = {1,2,3,4,5};
    ai = bi
    //可以将一个array对象赋予给另一个array对象，但是数组不行
    */
    return 0;
}
