#include<iostream>
#include<cstdlib>
#include<random>
#include<ctime>

using namespace std;

double function(double x)
{
    return 1-x*x;
}

//传递函数指针func，指向函数function
double HitOrMiss(long long n, double (*func)(double))
{
    default_random_engine e(time(0));//生成种子
    uniform_real_distribution<double>u(0,1);//生成0~1之间的浮点数
    double k=0;
    for(int i=0; i<n; i++)
    {
        double x = u(e);
        double y = u(e);
        if(y*y <= (func)(x))//通过函数指针调用函数，且避免开根号
        {
            k++;
        }
    }
    return 4*k/n;
}

int main()
{ 
    long long n = 1;
    while(n != 0)
    {
        cout << "Please enter n: ";
        cin >> n;
        //函数名就是指针，直接传入函数名
        double result = HitOrMiss(n,function);
        cout << "The result is: " << result << endl;
    }
    
    system("pause"); //系统命令程序暂停，避免直接退出
    return 0;
}