#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 10001;

int isprime[MAXN];
vector<int> prime;

void initial()
{
    fill(isprime,isprime+MAXN,1);
    isprime[0] = 0;
    isprime[1] = 0;

    for(int i=2; i<MAXN; i++)
    {
        if(!isprime[i]) continue;

        //cout << i << " ";
        prime.push_back(i);
        for(int j=i*i; j<MAXN; j+=i)
        {
            isprime[j] = 0;
        }
    }
}

bool IsSuperPrime(int n)
{
    if(isprime[n] == 0) return false;//本身不是素数

    int i=0, j=0;
    int sum = prime[i];
    int tag = 0;
    while(prime[j] < n)
    {
        if(sum == n)
        {
            tag = 1;
            break;
        }
        else if(sum < n)
        {
            j ++;
            sum += prime[j];
        }
        else
        {
            sum -= prime[i];
            i ++;
        }
    }
    if(tag == 0) return false;
    else
    {
        cout << "Sum Of : ";
        for(; i<=j; i++)
        {
            cout << prime[i] << " ";
        }
        cout << endl;
    }
    return true;
}

int main()
{
    initial();
    int n;
    while(cin >> n)
    {
        if(IsSuperPrime(n))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
