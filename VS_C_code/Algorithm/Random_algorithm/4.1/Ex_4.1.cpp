#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;

default_random_engine e;

// 评判标准的结构体
struct Evaluation
{
    double p;
    double s;
    double e;
    double t;

    Evaluation() : p(0), s(0), e(0), t(0) {}
    Evaluation(double p_num, double s_num, double e_num, double t_num) : 
            p(p_num), s(s_num), e(e_num), t(t_num) {}

    Evaluation operator + (const Evaluation &eva)
    {
        Evaluation result;
        result.p = this->p + eva.p;
        result.s = this->s + eva.s;
        result.e = this->e + eva.e;
        result.t = this->t + eva.t;
        return result;
    }

    Evaluation operator / (const int &num)
    {
        Evaluation result;
        result.p = this->p / (double) num;
        result.s = this->s / (double) num;
        result.e = this->e / (double) num;
        result.t = this->t / (double) num; 
        return result;
    }
};

int queen[30] = {0}; 
int g_stepCount = 0; // 记录放下皇后个数

// 得到 1~n 之间的随机数
int GetRandom(int n) {
    uniform_int_distribution<unsigned> u(1, n);
    return u(e);
}

// 判断位置是否合法
bool Check(int row, int col) 
{
    for (int i = 1; i < row; i++)
    {
        if (queen[i] == col || abs(row - i) == abs(col - queen[i]))
        {
            return false;
        }
    }
    return true;
}

// 回溯法求解，从第row个皇后开始求解
bool BackTrackQueen(int n, int row)
{
    if (row == n + 1)
    {
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (Check(row, i))
        {
            // 放下一个皇后，结点＋1
            g_stepCount ++; 
            queen[row] = i;

            if (BackTrackQueen(n, row + 1))
            {
                return true;
            }
            else
            {
                queen[row] = 0;
                continue;
            }
        }
    }
    return false;
}

// 随机求解
bool QueenLv_StepVegas(int n, int randomQueen)
{
    int row = 1;
    int numOfSafe = n;

    while(row <= randomQueen && numOfSafe > 0)
    {
        numOfSafe = 0;
        int col = 0;

        for (int i = 1; i <= n; i++)
        {
            if (Check(row, i))
            {
                numOfSafe ++;

                if (GetRandom(numOfSafe) == 1)
                {
                    col = i;
                }
            }
        }

        if (numOfSafe > 0)
        {
            g_stepCount ++; // 放下一个皇后
            queen[row] = col;
            row ++;
        }
    }

    if (numOfSafe > 0)
    { // 回溯求解剩下的皇后位置
        return BackTrackQueen(n, row);
    }
    else
    { // numOfSafe 为 0，说明某个皇后没有找到可行解，此次求解失败
        return false;
    }
}

// 一次求解，直到找到一个可行解为止
Evaluation QueenObstinate(int n, int randomQueen)
{
    Evaluation eva;
    g_stepCount = 1; 

    if(randomQueen == 0) // 纯回溯算法，从第1个皇后找起
    {
        memset(queen, 0, sizeof(queen));
        BackTrackQueen(n, 1); 
        eva = Evaluation(1, g_stepCount, 0, g_stepCount);
    }
    else
    {
        int round = 0;
        bool flag = false; // 标记是否找到可行解

        while (!flag)
        {
            memset(queen, 0, sizeof(queen));
            g_stepCount = 1; // 每轮重新尝试都重置一次
            flag = QueenLv_StepVegas(n, randomQueen);
            eva.t += g_stepCount; 
            round ++;
        }

        eva.s = g_stepCount;
        if(round == 1)
        {
            eva.e = 0;
            eva.p = 1; // p 为一次成功的概率
        }
        else
        {
            eva.e = (eva.t - eva.s) / (double) (round - 1);
        }
    }

    return eva;
}

Evaluation QueenRepeat(int n, int randomQueen)
{
    Evaluation eva_sum;
    int repeatTime = 1000;
    int false_time = 0;

    if(randomQueen == 0)
    {
        eva_sum = QueenObstinate(n, randomQueen);
    }
    else
    {
        for(int i = 0; i < repeatTime; i++)
        {
            Evaluation eva = QueenObstinate(n, randomQueen);

            if(eva.p != 1)
            {
                // eva.p == 1时，在这次重复过程中，没有失败的次数，不能算作 eva_avg.e 的分母
                false_time ++;
            }
            
            eva_sum = eva_sum + eva;
        }

        eva_sum = eva_sum / repeatTime;

        if(false_time == 0)
        {
            eva_sum.e = 0;
        }
        else
        {   
            // e 的真正的计算公式
            eva_sum.e = eva_sum.e * repeatTime / false_time ;
        }
        
    }

    return eva_sum;
}

void OutPut(int randomQueen, Evaluation eva)
{
    
    if(eva.e != 0)
    {
        cout << setw(16) << setiosflags(ios::left) << randomQueen
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.p
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.s
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.e
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.t
             << endl;
    }
    else
    {
        cout << setw(16) << setiosflags(ios::left) << randomQueen
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.p
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.s
             << setw(12) << setiosflags(ios::left) << "--"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << eva.t
             << endl;
    }
}

void test(int n)
{
    cout << setw(16) << setiosflags(ios::left) << "randomQueen"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "p"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "s"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "e"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "t"
             << endl;

    for (int  randomQueen = 0; randomQueen <= n; randomQueen++)
    {
        Evaluation eva_avg = QueenRepeat(n, randomQueen);
        OutPut(randomQueen, eva_avg);
    }
}

int main()
{
    e.seed(time(0));

    int n;
    cout << "Please input N :";
    cin >> n;

    while(n >= 4) 
    {
        test(n);
        cout << "Please input N :";
        cin >> n;
    }
    
    cout << "The result does not exist " << endl;
    return 0;
}