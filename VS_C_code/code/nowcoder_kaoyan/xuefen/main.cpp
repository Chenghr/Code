#include <iostream>
#include <cstdio>

using namespace std;

double getnum(int grade)
{
    if(grade >= 90)
        return 4.0;
    else if(grade >= 85)
        return 3.7;
    else if(grade >= 82)
        return 3.3;
    else if(grade >= 78)
        return 3.0;
    else if(grade >= 75)
        return 2.7;
    else if(grade >= 72)
        return 2.3;
    else if(grade >= 68)
        return 2.0;
    else if(grade >= 64)
        return 1.5;
    else if(grade >= 60)
        return 1.0;
    else
        return 0.0;
}

int main()
{
    int n;
    int a[10] = {0};

    while(cin >> n)
    {
        int sumgrade = 0;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            sumgrade += a[i];
        }

        double gpa = 0;
        for(int i=0; i<n; i++)
        {
            int grade;
            cin >> grade;
            gpa += getnum(grade)*a[i];
        }

        printf("%.2lf\n",gpa/sumgrade);
    }



    return 0;
}
