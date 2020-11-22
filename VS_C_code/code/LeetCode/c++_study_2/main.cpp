#include <iostream>
#include <string>
#include <cstring>//为了使用strlen函数，调用c语言的string函数

using namespace std;

int main()
{
    //数组
    int month[12];
    int a[3] = {1,2,3};
    int b[] = {1,2,3,4};//系统自动计算数组元素为4个
    int c[5] = {0};//数组元素初始化为0；
    int c1[5] = {};//效果同上
    int c2[5] {};//初始化数组可省略等号
    int d[5] = {1};//第一个元素为1，其余元素为0

    //字符串
    char s1[3] = {'a','b','c'};
    char s2[3] = {'a','b','\0'};//仅s2为字符串，s1不是字符串，缺少空字符'\0'
    char s3[] = "apple";//字符串常量（使用双引号），字符常量（使用单引号），默认在单词后面嵌入空字符

    const int size = 15;//size 一定要用const修饰，否则不能用来定义数组长度
    char name1[size];//空数组
    char name2[size] = "chr";
    cout << "name2 的元素个数为 " << strlen(name2) << endl;//strlen()不计算空字符，仅返回可见的字符长度；
    cout << "name2 的数组长度为 " << sizeof(name2) << endl;//sizeof()返回数组长度
    /*
    cin >> name1;//cin使用空白来确定字符串的结束位置，即获取字符数组输入时制度去一个单词，在这个单词末尾添加空字符
    cin.getline(name2,15);
    //cin.getline( , )一次读入一行字符串，以回车确定结尾，且用空白符代替回车 t
    //第二个参数用于确定读取的最大数目，这个最大只能读取14个字符

    cin.get(name1,size);//类似cin.getline(),区别在于不吃掉回车符，回车符任存在于缓冲区；
    cin.get();//不带任何参数的cin.get()可读取下一个字符，吃掉缓冲区的回车符；
    cout << "Hello world!" << endl;
    */
    string str1;
    string str2 = "apple";
    cin >> str1;//str1的声明创建了一个长度为0的string对象，输入时自动调整长度
    str1 = str2;//string对象可以相互赋值，c语言中strcpy(,)的功能
    string str3;
    str3 = str1+str2;// + 将两个字符串合并，C语言的中的strcat(,)的功能
    cin.get();//吃掉cin留下的空格
    getline(cin,str1);
    cout << str1 << endl << str2 << endl << str3 << endl;
    str1 += str2;//将str2加到str1的末尾
    int len = str1.size();


    return 0;
}
