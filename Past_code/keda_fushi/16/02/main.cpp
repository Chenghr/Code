#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int main()
{
    double money;
    int n;
    while(cin >> money >> n)
    {
        if(money*100 < n)
        {
            cout << "Money is not enough! " << endl;
        }

        double *a = new double[n];
        srand((unsigned int) time(NULL));

        for(int i=0; i<n-1; i++)
        {
            double temp1 = rand() % (int)(money*100);//money取整，生成随机整数
            double temp2 = 0.01*(rand()%10);//生成随机小数

            a[i] = temp1/100+temp2;
            if(a[i] < 0.01)
            {
                a[i] += 0.01;
            }
            money -= a[i];
        }
        a[n-1] = money;

        for(int i=0; i<n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
