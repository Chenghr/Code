#include <iostream>

//创建别名
#define BYTE CHAR//使用CHAR代替BYTE
typedef char byte;//使用byte代替char
//define 不能声明一系列变量，但是typedef不会有这样的问题；
//例如：
/*
#define float_point float *;
float_point pa,pb 等价于 float * pa,pb;pb只是一个float型变量
*/

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
