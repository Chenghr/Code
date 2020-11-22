/*
 *
 *  算法设计与分析
 *  课程作业 Ex
 *  估计整数子集1~n的大小
 *
 *  姓名：张钧洋
 *  学号：SA20011089
 *
 *  注：此程序为了支持较大数的随机生成，使用了random_engine，需要C++ 11标准支持，功能正常。
 *
 */


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <set>
#include <ctime>
#include <random>


// 随机数引擎，需要 C++ 11 标准支持
static std::default_random_engine e;

/*
long GetRandom(long n) {
    return (n - 1) * (e() / double(e.max())) + 1;
}
*/


// get the random number among 1~n
// random (0, 1) -> (1, n)
long GetRandom(long n) {
    static std::uniform_real_distribution<double> r(0, 1);
    return (n - 1) * r(e) + 1;
}


// Calculate the size of the set 1 ~ n.
long SetCount(long n) {

    long hit_count = 0;
    std::set<long> random_set;

    long random_num = GetRandom(n);

    // break when hitting the same value
    do {
        hit_count++;
        random_set.insert(random_num);
        random_num = GetRandom(n);
    } while( random_set.find(random_num) == random_set.end() );
    
    // 2 * k^2 / pi
    // implicit type conversion double -> long
    return 2 * hit_count * hit_count / 3.14159265359;
}


// Repeated calculate and take the average
long ReplayExe(long n, long replay_num) {

    double sum = 0;

    for(long i = 0; i < replay_num; i++) {
        // prevent sum too much
        sum += SetCount(n) / double(replay_num);
    }

    // implicit type conversion double -> long
    return sum;
}


// main
int main() {

    // seed
    e.seed(time(0));

    long n = 1;

    while(n != 0)
    {
        // input n
        std::cout << "Please enter n(1~n): ";
        std::cin >> n;

        // Repeated calculation
        long result = ReplayExe(n, 100);

        std::cout << "The size of the set: " << result << std::endl;
    }
    

    system("pause");
    return 0;
}

