#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

double Darts(long long n)
{
    srand((unsigned)time(NULL));
    double k = 0;
    for(int i=0; i<n; i++)
    {
        double x = rand()/double(RAND_MAX);
        double y = x;
        if(x*x+y*y <= 1) k++;
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
        double result = Darts(n);
        cout << "The result is: " << result << endl;
    }
    
    system("pause"); //系统命令程序暂停，避免直接退出
    return 0;
}