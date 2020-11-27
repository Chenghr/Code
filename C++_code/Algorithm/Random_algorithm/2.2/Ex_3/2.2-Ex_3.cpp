#include<iostream>
#include<cstdlib>
#include<random>
#include<ctime>

using namespace std;

double function(double x)
{
    return x*x*x+x*x;
}

//传递函数指针func，指向函数function
double HitOrMiss(long long n, double (*func)(double), int a, int b, int c, int d)
{
    default_random_engine e(time(0));//生成种子
    uniform_real_distribution<double>ux(a,b);//生成a~b之间的浮点数，x轴坐标
    uniform_real_distribution<double>uy(c,d);//生成c~d之间的浮点数，y轴坐标
    double k=0;
    for(int i=0; i<n; i++)
    {
        double x = ux(e);
        double y = uy(e);
        if(y <= (func)(x)) 
        {
            k++;
        }
    }
    return (b-a)*(d-c)*k/n;
}

int main()
{ 
    long long n = 1,a,b,c,d;
    cout << "Please enter a,b,c,d : ";
    cin >> a >> b >> c >> d;

    while(n != 0)
    {
        cout << "Please enter n : ";
        cin >> n ;
        //函数名就是指针，直接传入函数名
        double result = HitOrMiss(n,function,a,b,c,d);
        cout << "The result is: " << result << endl;
    }
    
    system("pause"); //系统命令程序暂停，避免直接退出
    return 0;
}