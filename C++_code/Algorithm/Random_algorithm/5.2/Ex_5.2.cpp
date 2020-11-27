/**
 * 打印一万以内的素数
 * 与确定性算法相比较，并给出100-10000以内的错误的比例
 **/

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

default_random_engine e;

const int max_n = 100000;

bool isPrime[max_n]; // 确定算法下求解的素数
vector<int> randomPrime; // 概率算法下求解的素数

// 得到 a~b 之间的随机数
int GetRandom(int a, int b) {
    uniform_int_distribution<unsigned> u(a, b);
    return u(e);
}

// 使用确定性算法（素数表），得到 1 ~ max_n 之间的所有素数
void InitialPrime() 
{
    // 初始化标记数组
    for(int i = 0; i < max_n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;

    for(int i = 2; i < max_n; i++)
    {
        // i不是素数
        if(isPrime[i] == false) 
        {
            continue;
        }

        // i为素数，但是i的倍数均不是素数
        if (i < sqrt(max_n)) // 避免i*i越界
        {
            for (int j = i * i; j < max_n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int mod(int a, int b) // 计算a mod b
{
    int result = ((a % b) + b) % b;
    return result;
}

// 计算a^n mod p；基础版本，该溢出还是会溢出
int PowerMod_basic(int a, int n, int b) 
{
    int temp = mod(a, b);
    int result = 1;
    for(int i = 1; i <= n; i++)
    {
        result = mod(result*temp, b); // 就是这里溢出的
    }
    return result;
}

// 快速幂取模, 计算a^n mod p
long long Powermod(long long a, long long n, long long b)
{
    long long ans=1;
    a = a % b;
    while(n)
    {
        if(n & 1) // 判断n是否为奇数，是的话将多出来的数先乘上ans做mod运算
        {
            ans = (ans*a) % b;
        }
        n /= 2;
        a = (a*a) % b; // 不断的两两合并，减小 a和n 的规模
    }
    return ans;
}

// 简单概率算法--一次随机判定
bool prime(int n)
{
    int d = GetRandom(2, (int)sqrt(n));
    if(mod(n, d) == 0) 
    {
        return false;
    }
    return true;
}

/**
 * 费马小定理：
 * 若 a 为素数，则任意 a 在 [1, n-1] 之间，有 a^(n-1) mod n == 1
 * Fermat函数使用的是费马小定理的逆命题，未必正确（逆否命题才是等价命题），因此算法偏假
 **/

bool Fermat(int n)
{
    int a = GetRandom(1, n-1);
    if(mod((int)pow(a, n-1), n) == 1)
    {
        return true;
    }
    return false;
}

/**
 * Fermat改进：
 * n为大于4的奇整数，s、t满足 n-1 == t*(2^s)，其中t为奇数
 * a 属于集合 B(n) 当地且仅当 a 属于[2, n-2] 且：
 *  a^t mod n == 1
 *  或者 存在整数i属于[0, s) 满足 a^(2^i * t) mod n == n-1
 * 
 * n为素数时，任意a在[2, n-2]，均有a属于B(n)
 * n为合数时，如果有a在[2, n-2]，且属于B(n)，则称n为以a为底的强伪素数
 **/

// n为奇数，且大于4(偶数一定不是素数)，a属于[2, n-2]
bool TestOnce(int a, int n)
{
    // t初始为偶数
    int s = 0, t = n-1;

    // n-1 == t*(2^s)，其中t为奇数
    while(mod(t, 2) != 1)
    {
        s ++;
        t /= 2;
    }

    // int x = mod((int)pow(a, t), n); 这里不能这么写，会溢出，需要用mod运算的分配律
    int x = Powermod(a, t, n);

    // 满足条件1 或者条件2的初始情况则返回真
    if(x == 1 || x == n-1)
    {
        return true;
    }

    // 判断是否满足条件2
    for(int i = 1; i <= s-1; i++)
    {
        x = Powermod(x, 2, n);
        if(x == n-1)
        {
            return true;
        }
    }

    return false;
}

// n为大于4的奇数，返回真则表示n为强伪素数，假表示合数
bool MillRabin(int n) 
{
    int a = GetRandom(2, n-2);
    return TestOnce(a, n); 
}

// 多次重复MillRabin测试算法，返回结果均为真时，则认为n为素数(可接受错误率范围内)
bool RepeatMillRabin(int n, int repeatTime)
{
    for(int i = 1; i < repeatTime; i++)
    {
        if(MillRabin(n) == false)
        {
            return false;
        }
    }
    return true;
}

void GetPrimeRandom(int upperBound)
{
    randomPrime.clear();
    randomPrime.push_back(2);
    randomPrime.push_back(3);
    int repeatTime;

    cout << endl
         << "Please enter the repeatTime :";
    cin >> repeatTime;

    for (int i = 5; i <= upperBound; i += 2)
    {
        // repeatTime = (int)sqrt(i);
        if(RepeatMillRabin(i, repeatTime))
        {
            randomPrime.push_back(i);
        }
    }
}

void Output(int upperBound)
{
    vector<int> wrongPrime;

    int realprime = 0;
    for(int i = 1; i < upperBound; i ++)
    {
        if(isPrime[i] == true)
        {
            // cout << i << " ";
            realprime ++;
        }
    }
    cout << endl
         << "The number of realPrime is : " << realprime
         << endl << endl;

    cout << "The number of randomPrime is : " << randomPrime.size();
    
    for(int i = 0; i < randomPrime.size(); i ++)
    {
        // cout << randomPrime[i] << " ";
        if(randomPrime[i] > 100 && isPrime[randomPrime[i]] == false) 
        {
            wrongPrime.push_back(randomPrime[i]);
        }
    }

    cout << endl << endl;

    cout << "The number of wrong prime between 100 and " << upperBound
         << " is : " << wrongPrime.size() << endl;

    if (wrongPrime.size() > 0)
    {
        cout << endl
             << "Wrong prime is : " << endl;
        for (int i = 0; i < wrongPrime.size(); i++)
        {
            cout << wrongPrime[i] << " ";
        }
    }

    cout << endl << endl;
}

int main()
{
    e.seed(time(0));
    InitialPrime();
    
    int upperBound = 5;

    while(upperBound > 4)
    {
        cout << "Please enter the upper bound of the prime number :";
        cin >> upperBound;

        GetPrimeRandom(upperBound);

        Output(upperBound);
    }
    
    return 0;
}