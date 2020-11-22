#include <iostream>
#include <vector>

using namespace std;

vector<int> perfect_num;
vector<int> over_num;

void candle_num(int n)
{
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        if(n % i == 0) sum += i;
    }

    if(sum == n) perfect_num.push_back(n);
    else if(sum > n) over_num.push_back(n);

    return ;
}

int main()
{
    for(int i=2; i<=1000; i++)
    {
        candle_num(i);
    }

    cout << "perfect_num:";
    for(int i=0; i<perfect_num.size(); i++)
    {
        cout << " " << perfect_num[i];
    }

    cout << endl << "over_num:";
    for(int i=0; i<over_num.size(); i++)
    {
        cout << " " << over_num[i];
    }
    cout << endl;
    return 0;
}
