#include <iostream>
#include <algorithm>

using namespace std;

struct Country
{
    int goldmental;
    int mental;
    int people;
};

int n,m;

bool comp(int x,int y)
{
    return x > y;
}

bool comp_1(double x,double y)
{
    return x>y;
}

int findorder(int a[],int x)
{
    for (int i=0; i<n; i++)
    {
        if(a[i] == x) return i+1;
    }
    return 0;
}

int findorder_1(double a[],double x)
{
    for (int i=0; i<n; i++)
    {
        if(a[i] == x) return i+1;
    }
    return 0;
}

int main()
{
    while (cin >> n >> m)
    {
        Country *a = new Country [n];//存储国家信息
        int *x1 = new int [n];
        int *x2 = new int [n];
        double *x3 = new double [n];
        double *x4 = new double [n];

        for (int i=0; i<n; i++)
        {
            cin >> a[i].goldmental >> a[i].mental >> a[i].people;
            x1[i] = a[i].goldmental;
            x2[i] = a[i].mental;
            if(a[i].people == 0)
            {
                if(a[i].goldmental == 0) x3[i] = 0;
                else x3[i] = 1000000;
                if(a[i].mental == 0) x4[i] = 0;
                else x4[i] = 1000000;
            }
            else
            {
                if(a[i].goldmental == 0) x3[i] = 0;
                else x3[i] = a[i].goldmental*1.0/a[i].people;
                if(a[i].mental == 0) x4[i] = 0;
                else x4[i] = a[i].mental*1.0/a[i].people;
            }
        }

        Country *b = new Country [m];//存储需要排名的国家
        for(int i=0; i<m; i++)
        {
            int t;
            cin >> t;
            b[i] = a[t];
        }

        sort (x1,x1+n,comp);
        sort (x2,x2+n,comp);
        sort (x3,x3+n,comp_1);
        sort (x4,x4+n,comp_1);

        for(int i=0; i<m; i++)
        {
            int minorder = n;
            int order;
            int tag = 0;
            double x;

            order = findorder(x1,b[i].goldmental);
            if(minorder > order)
            {
                minorder = order;
                tag = 1;
            }
            if(minorder == 1)
            {
                cout << minorder << ":" << tag << endl;
                continue;
            }

            order = findorder(x2,b[i].mental);
            if(minorder > order)
            {
                minorder = order;
                tag = 2;
            }
            if(minorder == 1)
            {
                cout << minorder << ":" << tag << endl;
                continue;
            }

            if(b[i].people == 0)
            {
                if(b[i].goldmental == 0) x = 0;
                else x = 1000000;
            }
            else
            {
                if(b[i].goldmental == 0) x = 0;
                else x = b[i].goldmental*1.0/b[i].people;
            }
            order = findorder_1(x3,x);
            if(minorder > order)
            {
                minorder = order;
                tag = 3;
            }
            if(minorder == 1)
            {
                cout << minorder << ":" << tag << endl;
                continue;
            }

            if(b[i].people == 0)
            {
                if(b[i].mental == 0) x = 0;
                else x = 1000000;
            }
            else
            {
                if(b[i].mental == 0) x = 0;
                else x = b[i].mental*1.0/b[i].people;
            }
            order = findorder_1(x4,x);
            if(minorder > order)
            {
                minorder = order;
                tag = 4;
            }

            cout << minorder << ":" << tag << endl;
        }
        cout << endl;
    }
    return 0;
}
