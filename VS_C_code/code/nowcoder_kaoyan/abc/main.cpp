#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    for(a=0; a<=9; a++)
    {
        for(b=0; b<=9; b++)
        {
            for(c=0; c<=9; c++)
            {
                if(a*100+b*110+c*12 == 532)
                {
                    cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
    return 0;
}
