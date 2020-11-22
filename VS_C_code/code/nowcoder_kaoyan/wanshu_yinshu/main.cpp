#include <iostream>
#include <vector>

using namespace std;
vector<int> num1;
vector<int> num2;

void getnum(int n)
{
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
        {
            sum += i;
        }
    }
    if(sum == n)
    {
        num1.push_back(n);
    }
    else if(sum > n)
    {
        num2.push_back(n);
    }
    return ;
}

int main()
{
    for(int i=2; i<=60; i++)
    {
        getnum(i);
    }

    cout << "E:";
    for(int i=0; i<num1.size(); i++)
    {
        cout << " " << num1[i];
    }

    cout << endl << "G:";
    for(int i=0; i<num2.size(); i++)
    {
        cout << " " << num2[i];
    }
    cout << endl;
    return 0;
}
