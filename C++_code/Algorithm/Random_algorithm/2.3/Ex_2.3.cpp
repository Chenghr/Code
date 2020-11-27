#include<iostream>
#include<cstdlib>
#include<random>
#include<ctime>
#include<cmath>
#include<set>

using namespace std;

default_random_engine e; 

double Count(long long n)
{
    
    uniform_real_distribution<double> u(0,1); // 生成0~1之间的浮点数
    set<long long> tag;

    long long temp = u(e)*(n-1)+1; // 将浮点数转化为 1~n 之间的随机数
    long long hit_count = 0;

    while(tag.find(temp) == tag.end())
    {
        tag.insert(temp);
        hit_count ++;
        temp = u(e)*(n-1)+1;
    }
    return 2*hit_count*hit_count/acos(-1); // arccos(-1)的值为Π
}

int SetCount(long long n) // 多次运行后取平均值
{
    int j = 1000;
    double sum = 0;

    for(int i = 0; i < j; i++)
    {
        sum += Count(n);
    }
    long long avg = sum/j;
    return avg;
}

int main()
{ 
    long long n = 1;

    while(n != 0)
    {
        cout << "Please enter n : ";
        cin >> n ;

        e.seed(time(0));
        long long result = SetCount(n);
        cout << "The result is  : " << result << endl;
    }
    
    return 0;
}