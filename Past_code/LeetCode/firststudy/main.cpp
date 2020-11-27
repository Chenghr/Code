#include <iostream>//使用cin,cout输入输出的程序必须包含的头文件
#include <climits>//定义了符号常量来表示类型的限制

/*
使用iostream.h时可省略，使用iostream时不可省略
使所有函数都能访问名称空间std
*/
using namespace std;


int main()
{
    cout << "字符串";
    cout << endl;//endl表示重启一行，类似c语言中的\n；
    cout << "\n";
    cout << "Hello world!" << endl;

    int a ;//变量在使用前声明即可
    int b ;
    int c;
    a = b = c = 1;//允许连续赋值
    cout << a << endl;
    cin >> a;
    cout << "Now a = " << a << endl;

    int n_int = INT_MAX;
    short n_short = SHRT_MIN;
    cout << "The max int is " << n_int << endl;
    cout << "The min short is " << n_short << endl;

    const int month = 12;//固定month常量为12，不可修改,类似c语言里面的#define
    return 0;
}
