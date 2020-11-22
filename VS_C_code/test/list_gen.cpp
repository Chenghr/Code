




#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>
#include <vector>
#include <fstream>


#define USER_LONG_MAX 2147483647

using namespace std;


// 随机数引擎，需要 C++ 11 标准支持
static std::default_random_engine e;


// 统计操作数组的次数，用于性能分析
static long global_step_count = 0;


// get the random number among 1~n
// random (0, 1) -> (1, n)
long GetRandom(long n) {
    static std::uniform_real_distribution<double> r(0, 1);
    return (n - 1) * r(e) + 1;
}


// Class for ordered list
class OrderedList {
public:

    // Constructor: build a random ordered list
    OrderedList(long range_n, long list_length):
    _val_vector(list_length + 1),
    _ptr_vector(list_length + 1),
    _rank_vector(list_length + 1)
    {
        this->range_n = range_n;
        this->list_length = list_length;
        this->head_index = initList(range_n, _val_vector, _ptr_vector, _rank_vector);
    }

    void printListInfo() {
        printList(head_index, _val_vector, _ptr_vector, _rank_vector);
        return;
    }

    std::vector<long>& getValVector() {
        global_step_count++;
        return this->_val_vector;
    }

    std::vector<long>& getPtrVector() {
        return this->_ptr_vector;
    }

    std::vector<long>& getRankVector() {
        return this->_rank_vector;
    }

    long getHeadIndex() {
        return this->head_index;
    }

    long getRangeN() {
        return this->range_n;
    }

    long getListLength() {
        return this->list_length;
    }

private:

    std::vector<long> _val_vector;
    std::vector<long> _ptr_vector;
    std::vector<long> _rank_vector;

    long head_index;
    long list_length;
    long range_n;

    // create a random value list
    // range_n: the values are in the range of 1~n
    void createRandomList(long range_n, std::vector<long> &val_vector) {

        for (std::vector<long>::iterator iter = val_vector.begin();
             iter != val_vector.end(); iter++) {
            *iter = GetRandom(range_n);
        }

        return;
    }

    // create a random ordered list
    // range_n: the values are in the range of 1~n
    long createList(long range_n,
                    std::vector<long> &val_vector,
                    std::vector<long> &ptr_vector,
                    std::vector<long> &rank_vector) {

        const long vector_length = val_vector.size();

        createRandomList(range_n, val_vector);

        std::vector<long> front_ptr_vector(vector_length, 0);

        long cur_min_num = 0;
        long cur_min_index = 0;

        long max_index = 0;

        for (long cur_index = 1; cur_index < vector_length; cur_index++) {

            cur_min_index = cur_index;
            cur_min_num = 2147483647;

            for (long sel_index = 1; sel_index < vector_length; sel_index++) {
                if (val_vector[cur_index] == val_vector[sel_index] &&
                    sel_index > cur_index) {
                    cur_min_index = sel_index;
                    cur_min_num = val_vector[sel_index];
                    front_ptr_vector[cur_min_index] = cur_index;
                    break;
                }
                if (val_vector[cur_index] < val_vector[sel_index] &&
                    val_vector[sel_index] < cur_min_num &&
                    sel_index != cur_index) {
                    cur_min_index = sel_index;
                    cur_min_num = val_vector[sel_index];
                }
            }

            if (cur_min_index == cur_index) {
                ptr_vector[cur_index] = 0;
                max_index = cur_index;
            }
            else {
                ptr_vector[cur_index] = cur_min_index;
                front_ptr_vector[cur_min_index] = cur_index;
            }
        }

        long cur_rank = vector_length - 1;
        long cur_max_index = max_index;

        long head_ptr = 0;

        do {
            rank_vector[cur_max_index] = cur_rank--;
            head_ptr = cur_max_index;
            cur_max_index = front_ptr_vector[cur_max_index];
        } while (cur_rank != 0);

        return head_ptr;
    }


    // print three list
    void printList(long head_index,
                   std::vector<long> &val_vector,
                   std::vector<long> &ptr_vector,
                   std::vector<long> &rank_vector) {

        std::cout << std::endl;
        std::cout << "=========== print list ==============" << std::endl;

        std::cout << "head index: " << head_index << std::endl;
        std::cout << "id:" << '\t';

        for (long id = 1; id < val_vector.size(); id++) {
            std::cout << id << '\t';
        }

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "val:" << '\t';

        for (std::vector<long>::iterator iter = val_vector.begin() + 1;
             iter != val_vector.end(); iter++) {
            std::cout << *iter << '\t';
        }

        std::cout << std::endl;

        std::cout << "ptr:" << '\t';

        for (std::vector<long>::iterator iter = ptr_vector.begin() + 1;
             iter != ptr_vector.end(); iter++) {
            std::cout << *iter << '\t';
        }

        std::cout << std::endl;

        std::cout << "rank:" << '\t';

        for (std::vector<long>::iterator iter = rank_vector.begin() + 1;
             iter != rank_vector.end(); iter++) {
            std::cout << *iter << '\t';
        }

        std::cout << std::endl;
        std::cout << "=========== print end. ==============" << std::endl << std::endl;

        return;

    }


    // init the list for random value and ordered pointer
    // and print three lists.
    long initList(long range_n,
                    std::vector<long> &val_vector,
                    std::vector<long> &ptr_vector,
                    std::vector<long> &rank_vector) {

        long head_index = createList(range_n, val_vector, ptr_vector, rank_vector);

        // printList(head_index, val_vector, ptr_vector, rank_vector);

        return head_index;
    }



};
// class end





// search the value from the fixed index
long searchValue(long find_value, long start_index, OrderedList *ordered_list) {

    long cur_index = start_index;

    while (find_value > ordered_list->getValVector()[cur_index]) {
        cur_index = ordered_list->getPtrVector()[cur_index];
    }

    return cur_index;
}


// algorithm A
long algorithm_A(long find_value, OrderedList *ordered_list) {
    return searchValue(find_value, ordered_list->getHeadIndex(), ordered_list);
}


// algorithm B
long algorithm_B(long find_value, OrderedList *ordered_list) {

    long start_index = ordered_list->getHeadIndex();
    long cur_index = start_index;
    long cur_value = ordered_list->getValVector()[cur_index];
    long cur_max = cur_value;

    long range_n = ordered_list->getRangeN();

    long sqrt_n = sqrt(range_n);

    for (cur_index = 1; cur_index <= sqrt_n; cur_index++) {
        cur_value = ordered_list->getValVector()[cur_index];
        if (cur_max < cur_value && cur_value <= find_value) {
            start_index = cur_index;
            cur_max = cur_value;
        }
    }

    return searchValue(find_value, start_index, ordered_list);

}

// algorithm C
long algorithm_C(long find_value, OrderedList *ordered_list) {

    long start_index = ordered_list->getHeadIndex();
    long cur_index = start_index;
    long cur_value = ordered_list->getValVector()[cur_index];
    long cur_max = cur_value;

    long list_length = ordered_list->getListLength();
    long range_n = ordered_list->getRangeN();

    long sqrt_n = sqrt(range_n);

    for (int i = 0; i < sqrt_n; i++) {
        cur_index = GetRandom(list_length);
        cur_value = ordered_list->getValVector()[cur_index];
        if (cur_max < cur_value && cur_value <= find_value) {
            start_index = cur_index;
            cur_max = cur_value;
        }
    }

    return searchValue(find_value, start_index, ordered_list);

}

// algorithm D
long algorithm_D(long find_value, OrderedList *ordered_list) {

    long cur_index = GetRandom(ordered_list->getListLength());
    long cur_value = ordered_list->getValVector()[cur_index];

    long result_index = 0;

    if (find_value < cur_value) {
        result_index = searchValue(find_value, ordered_list->getHeadIndex(), ordered_list);
    }
    else if (find_value > cur_index) {
        result_index = searchValue(find_value, ordered_list->getPtrVector()[cur_index], ordered_list);
    }
    else {
        result_index = cur_index;
    }

    return result_index;
}



void algo_analysis(long range_n, long list_length, int repeat_time) {

    std::cout << "\nAnalysis Begin. Generate the list..." << std::endl;

    OrderedList ordered_list(range_n, list_length);

    std::cout << "List generated. Test start." << std::endl;

    long worst = 0;
    long average = 0;

    std::cout << "\nStart testing Algorithm A..." << std::endl;
    worst = 0;
    average = 0;
    for (int i = 0; i < repeat_time; i++) {
        long find_index = GetRandom(list_length);
        long find_value = ordered_list.getValVector()[find_index];
        global_step_count = 0;
        algorithm_A(find_value, &ordered_list);
        average += global_step_count;
        worst = (worst < global_step_count) ? global_step_count : worst;
    }
    std::cout << "Test End. Average: " << average / repeat_time
              << ", Worst: " << worst << std::endl << std::endl;


    std::cout << "Start testing Algorithm B..." << std::endl;
    worst = 0;
    average = 0;
    for (int i = 0; i < repeat_time; i++) {
        long find_index = GetRandom(list_length);
        long find_value = ordered_list.getValVector()[find_index];
        global_step_count = 0;
        algorithm_B(find_value, &ordered_list);
        average += global_step_count;
        worst = (worst < global_step_count) ? global_step_count : worst;
    }
    std::cout << "Test End. Average: " << average / repeat_time
              << ", Worst: " << worst << std::endl << std::endl;


    std::cout << "Start testing Algorithm C..." << std::endl;
    worst = 0;
    average = 0;
    for (int i = 0; i < repeat_time; i++) {
        long find_index = GetRandom(list_length);
        long find_value = ordered_list.getValVector()[find_index];
        global_step_count = 0;
        algorithm_C(find_value, &ordered_list);
        average += global_step_count;
        worst = (worst < global_step_count) ? global_step_count : worst;
    }
    std::cout << "Test End. Average: " << average / repeat_time
              << ", Worst: " << worst << std::endl << std::endl;


    std::cout << "Start testing Algorithm D..." << std::endl;
    worst = 0;
    average = 0;
    for (int i = 0; i < repeat_time; i++) {
        long find_index = GetRandom(list_length);
        long find_value = ordered_list.getValVector()[find_index];
        global_step_count = 0;
        algorithm_D(find_value, &ordered_list);
        average += global_step_count;
        worst = (worst < global_step_count) ? global_step_count : worst;
    }
    std::cout << "Test End. Average: " << average / repeat_time
              << ", Worst: " << worst << std::endl << std::endl;


    return;

}



int main() {

    // seed
    e.seed(time(0));

    ofstream outfile;

    outfile.open("orderedlist.csv");


    long list_length = 0;
    long range_n = 0;


    // input the parameter
    std::cout << "Please enter the length of the list: ";
    std::cin >> list_length;

    if (list_length <= 0) {
        std::cout << "Illegal Input!" << std::endl;
        return 0;
    }

    std::cout << "Please enter the range of the number: ";
    std::cin >> range_n;

    if (range_n <= 0) {
        std::cout << "Illegal Input!" << std::endl;
        return 0;
    }
    // input parameter end

    OrderedList orderlist(range_n, list_length);

    outfile << 1;

    for (int i = 2; i <= list_length; i++) {
        outfile << ',' << i;
    }
    outfile << std::endl;

    outfile << orderlist.getValVector()[1];

    for (int i = 2; i <= list_length; i++) {
        outfile << ',' << orderlist.getValVector()[i];
    }

    outfile << std::endl;

    outfile << orderlist.getPtrVector()[1];

    for (int i = 2; i <= list_length; i++) {
        outfile << ',' << orderlist.getPtrVector()[i];
    }
    outfile << std::endl;

    outfile << orderlist.getRankVector()[1];

    for (int i = 2; i <= list_length; i++) {
        outfile << ',' << orderlist.getRankVector()[i];
    }
    outfile << std::endl;

    outfile.close();

    return 0;


    /*

    int mode_flag = 0;

    std::cout << "Welcome~ There are two modes:" << std::endl;
    std::cout << "1. User customized mode: You can select the element you want to find." << std::endl;
    std::cout << "2. Algorithm analysis mode: System will repeat many times to analyse the performance."
              << std::endl << std::endl;
    std::cout << "Please select the mode (1/2): ";
    std::cin >> mode_flag;

    std::cout << std::endl;

    if (mode_flag != 1 && mode_flag != 2) {
        std::cout << "Illegal Input!" << std::endl;
        return 0;
    }

    if (mode_flag == 2) {

        long list_length = 0;
        long range_n = 0;
        int repeat_times = 0;

        // input the parameter
        std::cout << "Please enter the length of the list: ";
        std::cin >> list_length;

        if (list_length <= 0) {
            std::cout << "Illegal Input!" << std::endl;
            return 0;
        }

        std::cout << "Please enter the range of the number: ";
        std::cin >> range_n;

        if (range_n <= 0) {
            std::cout << "Illegal Input!" << std::endl;
            return 0;
        }

        std::cout << "Please enter the repeat times: ";
        std::cin >> repeat_times;

        if (repeat_times <= 0) {
            std::cout << "Illegal Input!" << std::endl;
            return 0;
        }

        algo_analysis(range_n, list_length, repeat_times);

        return 0;

    }


    long list_length = 0;
    long range_n = 0;

    // input the parameter
    std::cout << "Please enter the length of the list: ";
    std::cin >> list_length;

    if (list_length <= 0) {
        std::cout << "Illegal Input!" << std::endl;
        return 0;
    }

    std::cout << "Please enter the range of the number: ";
    std::cin >> range_n;

    if (range_n <= 0) {
        std::cout << "Illegal Input!" << std::endl;
        return 0;
    }
    // input parameter end


    OrderedList ordered_list(range_n, list_length);

    ordered_list.printListInfo();


    char algo_select = 'A';
    std::cout << "Please select the algorithm (A/B/C/D): ";
    std::cin >> algo_select;

    if (!(algo_select == 'A' || algo_select == 'B' ||
          algo_select == 'C' || algo_select == 'D')) {
        std::cout << "Illegal Input!" << std::endl;
        return 0;
    }

    long (*algos[])(long, OrderedList*) = {algorithm_A, algorithm_B, algorithm_C, algorithm_D};

    // find the element
    long find_value = 0;
    std::cout << "Please enter the number you want find (0 to exit): ";
    std::cin >> find_value;

    long result_index = 0;

    while(find_value > 0) {

        global_step_count = 0;

        // result_index = algorithm_A(find_value, &ordered_list);
        // result_index = algorithm_B(find_value, &ordered_list);
        // result_index = algorithm_C(find_value, &ordered_list);
        // result_index = algorithm_D(find_value, &ordered_list);

        result_index = algos[algo_select-'A'](find_value, &ordered_list);

        if (find_value == ordered_list.getValVector()[result_index]) {
            std::cout << "The index to the first element in the list: " << result_index << std::endl
                      << "The number of list access: " << global_step_count << std::endl
                      << std::endl;
        }
        else {
            std::cout << "The number is not in the list." << std::endl << std::endl;
        }

        std::cout << "Please enter the number you want find (0 to exit): ";
        std::cin >> find_value;

    }

    std::cout << "exit! Goodbye~" << std::endl;

    return 0;
    */
}



