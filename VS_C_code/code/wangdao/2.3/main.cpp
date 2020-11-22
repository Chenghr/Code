#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int maxprice = 0;
        for(int i=1; i<=9 ;i++)
        {
            for(int j=0; j<=9;j++)
            {
                int price = 10000*i+1000*a+100*b+10*c+j;
                if(price%n == 0 && price > maxprice)
                {
                    maxprice = price;
                }
            }
        }
        if(maxprice == 0) printf("0\n");
        else printf("%d %d %d\n",maxprice/10000,maxprice%10,maxprice/n);
    }
    return 0;
}
