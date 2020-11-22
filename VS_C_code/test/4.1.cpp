#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

default_random_engine e;

int queen[100] = {0}; 

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
bool BackTrackQueen(int n, int row, int *nodeCount)
{
    if (row == n + 1)
    {
        return true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (Check(row, i))
        {
            (*nodeCount)++; // 放下一个皇后，结点＋1
            queen[row] = i;

            if (BackTrackQueen(n, row + 1, nodeCount))
            {
                return true;
            }
            else
            {
                queen[row] = 0;
            }
        }
    }
    return false;
}

bool QueenLv(int n, int randomQueen, int *nodeCount)
{
    int row = 1;
    int numOfSafe = n;

    while (row <= randomQueen && numOfSafe > 0)
    {
        numOfSafe = 0;
        int col = 0;

        for (int i = 1; i <= n; i++)
        {
            if (Check(row, i))
            {
                numOfSafe++;
                uniform_real_distribution<double> u(0,1);
                int random = (numOfSafe-1)*u(e)+1; 
                if (random == 1)
                {
                    col = i;
                }
            }
        }

        if (numOfSafe > 0)
        {
            (*nodeCount)++;
            queen[row] = col;
            row++;
        }
    }

    if (numOfSafe > 0)
    { // 回溯求解剩下的皇后位置
        return BackTrackQueen(n, row, nodeCount);
    }
    else
    { // numOfSafe 为 0，说明某个皇后没有找到可行解，此次求解失败
        return false;
    }
}

void OutPut(int randomQueen, double p_avg, double s_avg, double e_avg, double t_avg)
{
    
    if(e_avg != 0)
    {
        cout << setw(16) << setiosflags(ios::left) << randomQueen
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << p_avg
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << s_avg
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << e_avg
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << t_avg
             << endl;
    }
    else
    {
        cout << setw(16) << setiosflags(ios::left) << randomQueen
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << p_avg
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << s_avg
             << setw(12) << setiosflags(ios::left) << "--"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << t_avg
             << endl;
    }
}

void Test(int n)
{
    int randomQueen = 0;
    int repeatTime = 100;
    
    cout << setw(16) << setiosflags(ios::left) << "randomQueen"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "p"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "s"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "e"
             << setw(12) << setiosflags(ios::left) << fixed << setprecision(2) << "t"
             << endl;

    for(randomQueen = 0; randomQueen <= n; randomQueen++)
    {
        double p_sum = 0, s_sum = 0, e_sum = 0, t_sum = 0;
        int successTime = 0; // 成功找到解的次数，多次求解，取均值

        while(successTime < repeatTime) 
        {   
            // 一遍成功求解
            bool flag = false; // 标记是否求出一个可行解
            int round = 0; // 记录直到成功的次数
            int nodeCount = 0; // 总共遍历过的节点数
            double p = 0, s = 0, e = 0, t = 0;
            memset(queen, 0, sizeof(queen)); // 初始化棋盘

            while(!flag)
            {
                s = nodeCount;
                flag = QueenLv(n, randomQueen, &nodeCount);
                s = nodeCount - s; // 如果此次成功，那么本次增加的nodeCOunt数即为遍历的节点数
                round ++; // 记录找到解的伦次
            }
            
            p = 1 / (double) round; // 一次成功的概率
            e = (nodeCount - s) / (double) round; // 记录总节点数减去最后一次成功的节点数即为失败节点数

            p_sum += p;
            s_sum += s;
            e_sum += e;
            
            successTime ++;
        }

        double p_avg = p_sum / repeatTime;
        double s_avg = s_sum / repeatTime;
        double e_avg = e_sum / repeatTime;
        double t_avg = s_avg + (1-p_avg)*e_avg/p_avg;

        OutPut(randomQueen, p_avg, s_avg, e_avg, t_avg);
    }
    
}

int main()
{

    int n;
    cout << "Please input N :";
    cin >> n;

    while(n >= 4)
    {
        e.seed(time(0));
        
        Test(n);
        cout << "Please input N :";
        cin >> n;
    }
    
    cout << "The result does not exist " << endl;
    system("pause");

    return 0;
}