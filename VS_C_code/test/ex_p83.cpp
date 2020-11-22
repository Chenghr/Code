/*
 *
 *  算法设计与分析
 *  课程作业 83-EX
 *  写一算法，求n=12~20时最优的StepVegas值。
 *
 *  姓名：张钧洋
 *  学号：SA20011089
 *
 */


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <set>
#include <locale>

using namespace std;


// 用于记录落子次数
long global_step_count = 0;


// 随机数引擎，需要 C++ 11 标准支持
static default_random_engine e;


// get the random number among 1~n
// random (0, 1) -> (1, n)
int GetRandom(int n) {
    static uniform_real_distribution<double> r(0, 1);
    return (n - 1) * r(e) + 1;
}


// 评判标准类
class Evaluation {

public:
    double p;
    double s;
    double e;
    double t;

    Evaluation() {
        p = 0;
        s = 0;
        e = 0;
        t = 0;
    }

    // 通过其他数值计算T
    double CaculateT() {
        t = s + (1 - p) / p * e;
        return t;
    }

    void operator += (const Evaluation &eva) {
        p += eva.p;
        s += eva.s;
        e += eva.e;
        t += eva.t;
    }

    void operator /= (int n) {
        p /= n;
        s /= n;
        e /= n;
        t /= n;
    }
};


// 棋盘类
class ChessBoard {

public:

    // 棋盘摆放情况
    vector<vector<bool>> chess_board;

    // 行、列、45度对角线、135度对角线集合
    set<int> board_row;
    set<int> board_col;
    set<int> board_diag45;
    set<int> board_diag135;

    // 棋盘的大小
    int board_size;


    ChessBoard(int board_size):
    board_size(board_size),
    chess_board(board_size + 1, vector<bool>(board_size + 1, 0)),
    chess_board_reset(board_size + 1, vector<bool>(board_size + 1, 0))
    {
        // 大家好我是构造函数
    }

    // 打印棋盘所有信息
    void printInfo() {
        printBoardInfo();
    }

    // 清空棋盘到初始状态
    void clearBoard() {

        // 其实可以用assign函数重置vector
        chess_board = chess_board_reset;

        board_row.clear();
        board_col.clear();
        board_diag45.clear();
        board_diag135.clear();
    }


private:

    // 用于重置棋盘，保存一份原始棋盘
    const vector<vector<bool>> chess_board_reset;

    // 打印棋盘信息
    void printBoardInfo() {
        cout << "============== Print ===================" << endl << endl;
        cout << "chess_board: " << endl;
        for (int i = 1; i <= board_size; i++) {
            for (int j = 1; j <= board_size; j++) {
                cout << chess_board[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;

        cout << "board_row    : ";
        for (set<int>::iterator itr = board_row.begin();
             itr != board_row.end(); itr++) {
            cout << *itr << ' ';
        }
        cout << endl;

        cout << "board_col    : ";
        for (set<int>::iterator itr = board_col.begin();
             itr != board_col.end(); itr++) {
            cout << *itr << ' ';
        }
        cout << endl;

        cout << "board_diag45 : ";
        for (set<int>::iterator itr = board_diag45.begin();
             itr != board_diag45.end(); itr++) {
            cout << *itr << ' ';
        }
        cout << endl;

        cout << "board_diag135: ";
        for (set<int>::iterator itr = board_diag135.begin();
             itr != board_diag135.end(); itr++) {
            cout << *itr << ' ';
        }
        cout << endl << endl;
        cout << "=============== End ====================" << endl;
    }

};


// 查看将皇后放在(x, y)这个位置是否安全
// true - 安全； false - 不安全
bool CheckQueen(const ChessBoard &chess_board, int x, int y) {

    // 判断列
    if (chess_board.board_col.find(y) !=
        chess_board.board_col.end()) {
        return false;
    }
    // 判断45度对角线
    else if (chess_board.board_diag45.find(y - x) !=
             chess_board.board_diag45.end()) {
        return false;
    }
    // 判读135度对角线
    else if (chess_board.board_diag135.find(y + x) !=
             chess_board.board_diag135.end()) {
        return false;
    }

    return true;
}


// 将皇后放在(x, y)这个位置上
void PutQueen(ChessBoard &chess_board, int x, int y) {

    chess_board.board_row.insert(x);
    chess_board.board_col.insert(y);
    chess_board.board_diag45.insert(y - x);
    chess_board.board_diag135.insert(y + x);
    chess_board.chess_board[x][y] = true;

    // 落子，记录次数
    global_step_count++;

    return;
}


// 将皇后从(x, y)这个位置移除
void RemoveQueenByLocation(ChessBoard &chess_board, int x, int y) {
    chess_board.board_row.erase(x);
    chess_board.board_col.erase(y);
    chess_board.board_diag45.erase(y - x);
    chess_board.board_diag135.erase(y + x);
    chess_board.chess_board[x][y] = false;

    return;
}


// 将x行上的皇后移除
// 此程序中没有调用
void RemoveQueenByRow(ChessBoard &chess_board, int x) {

    // 查找到x行上皇后的精确位置
    int col_index = 1;
    for (col_index = 1; col_index <= chess_board.board_size; col_index++) {
        if (chess_board.chess_board[x][col_index] == true) {
            break;
        }
    }

    RemoveQueenByLocation(chess_board, x, col_index);

    return;
}


// 使用递归函数来实现回溯法
bool BackTraceRecursion(ChessBoard &chess_board, int row_index) {

    // 结束条件
    if (row_index == chess_board.board_size + 1)
        return true;

    // 循环遍历这一行的每个格子
    for (int col_index = 1;
         col_index <= chess_board.board_size;
         col_index++) {

        // 如果这个格子可以用，就放置棋子，然后递归判断下一行
        if (CheckQueen(chess_board, row_index, col_index)) {
            PutQueen(chess_board, row_index, col_index);
            if (BackTraceRecursion(chess_board, row_index + 1)) {
                return true;
            }
            else {
                // 目前情况下往后摆放不可行，则移除这个棋子回溯
                RemoveQueenByLocation(chess_board, row_index, col_index);
                continue;
            }
        }
    }

    return false;
}


// 纯LV算法的皇后摆放问题
// 在此程序中不调用
bool QueensLv(ChessBoard &chess_board) {

    int row_index = 0;
    int nb = 0;
    int col_selected = 0;
    do {
        nb = 0;
        for (int col_index = 1;
             col_index <= chess_board.board_size;
             col_index++) {
            if (CheckQueen(chess_board, row_index + 1, col_index)) {
                nb++;
                if (GetRandom(nb) == 1) {
                    col_selected = col_index;
                }
            }
        }
        if (nb > 0) {
            row_index++;
            PutQueen(chess_board, row_index, col_selected);
        }
    } while (!(nb == 0 || row_index == 8));

    return (nb > 0);
}


// 加上stepVegas的LV算法
bool QueensLvForSteps(ChessBoard &chess_board, int step_vegas) {
    int row_index = 0;
    int nb = 0;
    int col_selected = 0;
    do {
        nb = 0;
        for (int col_index = 1;
             col_index <= chess_board.board_size;
             col_index++) {
            if (CheckQueen(chess_board, row_index + 1, col_index)) {
                nb++;
                if (GetRandom(nb) == 1) {
                    col_selected = col_index;
                }
            }
        }
        if (nb > 0) {
            row_index++;
            PutQueen(chess_board, row_index, col_selected);
        }
    } while (!(nb == 0 || row_index == step_vegas));

    // 如果到stepVegas这步可行，则使用确定性算法
    if (nb > 0) {
        return BackTraceRecursion(chess_board, row_index + 1);
    }

    return false;
}


// 带有stepVegas的LV算法的皇后摆放问题的Obstinate
Evaluation ObstinateForSteps(ChessBoard &chess_board, int step_vegas) {

    global_step_count = 0;

    Evaluation eva;

    if (step_vegas == 0) {
        // 步数为0说明纯回溯算法

        chess_board.clearBoard();
        BackTraceRecursion(chess_board, 1);
        eva.e = 0;
        eva.p = 1;
        eva.s = global_step_count;
        // eva.t = global_step_count;
    }
    else {
        bool flag = false;
        int repeat_count = 0;
        do {
            eva.s = global_step_count;
            chess_board.clearBoard();
            flag = QueensLvForSteps(chess_board, step_vegas);
            eva.s = global_step_count - eva.s;
            repeat_count++;
        } while (!flag);
        eva.e = (global_step_count - eva.s) / double(repeat_count);
        eva.p = 1 / repeat_count;
        // eva.t = global_step_count / double(repeat_count);
    }

    return eva;
}


// 纯LV算法的皇后摆放问题的Obstinate
// 此程序中不调用
void Obstinate(ChessBoard &chess_board) {

    bool flag = false;
    do {
        chess_board.clearBoard();
        flag = QueensLv(chess_board);
    } while (!flag);

    return;
}


// 多次重复一个算法
Evaluation RepeatOneCase(int board_size, int repeat_time, int step_vegas) {

    ChessBoard chess_board(board_size);

    Evaluation eva_sum;

    if (step_vegas == 0) {
        eva_sum += ObstinateForSteps(chess_board, step_vegas);
    }
    else {

        for (int repeat_index = 0; repeat_index < repeat_time; repeat_index++) {
            eva_sum += ObstinateForSteps(chess_board, step_vegas);
        }

        eva_sum /= repeat_time;
    }

    return eva_sum;

}


// 打印输出所有的结果
void solve(int board_size, int repeat_time) {

    cout << "step\tp\ts\te\tt" << endl;

    int best_step = 0;
    double best_t = numeric_limits<double>::max();

    for (int step = 0; step <= board_size; step++) {

        // Evaluation eva = ObstinateForSteps(chess_board, step);
        Evaluation eva = RepeatOneCase(board_size, repeat_time, step);
        eva.CaculateT();
        cout << step << '\t' << eva.p << '\t'
             << eva.s << '\t' << eva.e << '\t'
             << eva.t << endl;

        if (eva.t < best_t) {
            best_step = step;
            best_t = eva.t;
        }
    }

    cout << "\n\n";

    cout << "The best step:\t" << best_step << endl;
    cout << "The best t:\t" << best_t << endl;

    return;
}


int main() {

    // seed
    e.seed(time(0));

    int board_size = 8;
    int repeat_time = 100;

    int model_select = 0;

    cout << "Welcome~ There are two models:" << endl;
    cout << "1. Analysis Model: System will analyse the result of different steps." << endl;
    cout << "2. Solution Model: You can get a solution for specified board size." << endl << endl;
    cout << "Please select the model (1/2): ";
    cin >> model_select;

    cout << endl << endl;

    if (model_select != 1 && model_select != 2) {
        cout << "Illegal Input!" << endl;
        return 0;
    }

    if (model_select == 1) {

        cout << "Please enter the board size: ";
        cin >> board_size;

        if (board_size < 4) {
            cout << "Illegal Input!" << endl;
            return 0;
        }

        cout << "Please enter repeat times: ";
        cin >> repeat_time;

        if (board_size < 1) {
            cout << "Illegal Input!" << endl;
            return 0;
        }

        solve(board_size, repeat_time);

    }
    else {
        cout << "Please enter the board size: ";
        cin >> board_size;

        if (board_size < 4) {
            cout << "Illegal Input!" << endl;
            return 0;
        }

        int steps;

        cout << "Please enter the steps: ";
        cin >> steps;

        if (steps > board_size || steps < 0) {
            cout << "Illegal Input!" << endl;
            return 0;
        }

        ChessBoard chess_board(board_size);

        ObstinateForSteps(chess_board, steps);

        cout << endl;

        chess_board.printInfo();
    }

    system("pause");
    return 0;
}

