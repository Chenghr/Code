#include <iostream>
#include <random>
#include <cmath>
#include <ctime>

using namespace std;

int searchCount = 0;
default_random_engine e;

// 从位置i开始查找target，假设target >= val[i]，且存在于表中
int Search(int val[], int ptr[], int n, int i, int target)
{
    int temp = i;
    while (target > val[temp])
    {
        temp = ptr[temp];
        searchCount++;
    }
    return temp;
}

// O(n)的确定算法
int Search_A(int val[], int ptr[], int n, int head, int target)
{
    return Search(val, ptr, n, head, target);
}

// O(n)的概率算法
int Search_B(int val[], int ptr[], int n, int head, int target)
{
    uniform_int_distribution<int> u(1, n);

    int i = u(e); // 随机生成一个中间节点，在进一步查找
    int y = val[i];

    if (target < y)
    {
        return Search(val, ptr, n, head, target);
    }    
    else if (target > y)
    {
        return Search(val, ptr, n, ptr[i], target);
    }
    else
    {
        return i;
    }
}

// O(sqrt(n))的确定算法
int Search_C(int val[], int ptr[], int n, int head, int target)
{
    int i = head;
    int max = val[i];
    int k = (int)sqrt(n);

    // 先在前sqrt(n)个数中找出 不大于target 的最大的数，再从这个数开始搜索
    for (int j = 0; j < k; j++)
    {
        int y = val[j];
        if (y <= target && max < y)
        {
            i = j;
            max = y;
        }
        searchCount++;
    }

    return Search(val, ptr, n, i, target);
}

// O(sqrt(n))的概率算法
int Search_D(int val[], int ptr[], int n, int head, int target)
{
    int sqrt_n = (int)sqrt(n);
    int beginIndex = head;
    int curMaxVal = val[head];

    uniform_int_distribution<int> u(1, sqrt_n);

    // 随机选取sqrt(n)个数，选出其中 不大于target 的最大的数，再从这个数开始搜索
    for (int j = 0; j < sqrt_n; j++)
    {
        int randomIndex = u(e);
        if (val[randomIndex] <= target && curMaxVal < val[randomIndex])
        {
            beginIndex = randomIndex;
            curMaxVal = val[randomIndex];
        }
        searchCount++;
    }

    return Search(val, ptr, n, beginIndex, target);
}

void AlgorithmTest(int val[], int ptr[], int n, int head)
{
    cout << endl;
         
    int target = 1;
    while (target != -1)
    {
        cout << "Please input target: ";
        cin >> target;

        // Algorithm A
        int result = Search_A(val, ptr, n, head, target);
        cout << "The Result is : " << result << endl;
        cout << "The SearchCount of Algorithm A is : " << searchCount << endl
             << endl;
        searchCount = 0;

        // Algorithm B
        int cycle;
        cout << "Please input cycle time of Algorithm B: ";
        cin >> cycle;

        int sumSearchCount = 0;
        int maxSearchCount = 0;
        int minSearchCount = n;
        for (int i = 0; i < cycle; i++)
        {
            result = Search_B(val, ptr, n, head, target);

            sumSearchCount += searchCount;
            if (maxSearchCount < searchCount)
            {
                maxSearchCount = searchCount;
            }
            if(minSearchCount > searchCount)
            {
                minSearchCount = searchCount;
            }
            searchCount = 0;
        }
        int avgSearchCount = sumSearchCount / cycle;

        cout << "The Result is : " << result << endl;
        cout << "The MinSearchCount of Algorithm B is : " << minSearchCount << endl;
        cout << "The AverageSearchCount of Algorithm B is : " << avgSearchCount << endl;
        cout << "The MaxSearchCount of Algorithm B is : " << maxSearchCount << endl
             << endl;

        // Algorithm C
        result = Search_C(val, ptr, n, head, target);
        cout << "The Result is : " << result << endl;
        cout << "The SearchCount of Algorithm C is : " << searchCount << endl
             << endl;
        searchCount = 0;

        // Algorithm D
        cout << "Please input cycle time of Algorithm D: ";
        cin >> cycle;

        minSearchCount = n;
        sumSearchCount = 0;
        maxSearchCount = 0;
        for (int i = 0; i < cycle; i++)
        {
            result = Search_D(val, ptr, n, head, target);

            sumSearchCount += searchCount;
            if (maxSearchCount < searchCount)
            {
                maxSearchCount = searchCount;
            }
            if (minSearchCount > searchCount)
            {
                minSearchCount = searchCount;
            }
            searchCount = 0;
        }
        avgSearchCount = sumSearchCount / cycle;

        cout << "The Result is : " << result << endl;
        cout << "The MinSearchCount of Algorithm D is : " << minSearchCount << endl;
        cout << "The AverageSearchCount of Algorithm D is : " << avgSearchCount << endl;
        cout << "The MaxSearchCount of Algorithm D is : " << maxSearchCount << endl
             << endl;
    }
}

int main()
{
    int n = 1;

    while (n != 0)
    {
        // initial
        e.seed(time(0));

        cout << "Please input length of list : ";
        cin >> n;

        int head;
        cout << "Please input head: ";
        cin >> head;

        int *val = new int[n+1];
        int *ptr = new int[n+1];
        cout << "Please input val: ";
        for (int i = 0; i < n; i++) 
        {
            cin >> val[i] ;
        }
        cout << "Please input ptr: ";
        for (int i = 0; i < n; i++) 
        {
            cin >> ptr[i] ;
        }
        AlgorithmTest(val,ptr,n,head);
    }

    return 0;
}