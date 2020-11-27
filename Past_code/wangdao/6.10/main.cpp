#include <iostream>

using namespace std;

struct Martix
{
    int martix[10][10];
    int row,col;
    Martix(int r,int c) : row(r),col(c) {}
};

Martix MartixAdd(Martix a,Martix b)
{
    Martix result = Martix(a.row,a.col);
    for(int i=0; i<result.row; i++)
    {
        for(int j=0; j<result.col; j++)
        {
            result.martix[i][j] = a.martix[i][j]+b.martix[i][j];
        }
    }
    return result;
}

int getnum(Martix a)
{
    int num = 0;
    for(int i=0; i<a.row; i++)//0行的个数
    {
        int tag = 1;
        for(int j=0; j<a.col; j++)
        {
            if(a.martix[i][j] != 0)
            {
                tag = 0;
                continue;
            }
        }
        if(tag == 1) num++;
    }

    for(int i=0; i<a.col; i++)//0列的个数
    {
        int tag = 1;
        for(int j=0; j<a.row; j++)
        {
            if(a.martix[j][i] != 0)
            {
                tag = 0;
                continue;
            }
        }
        if(tag == 1) num++;
    }

    return num;
}

int main()
{
    int r,c;
    while(cin >> r)
    {
        if(r == 0) break;

        cin >> c;
        Martix a = Martix(r,c);
        Martix b = Martix(r,c);
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin >> a.martix[i][j];
            }
        }
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin >> b.martix[i][j];
            }
        }

        a = MartixAdd(a,b);
        int num = getnum(a);

        cout << num << endl;
    }
    return 0;
}
