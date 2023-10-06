#include <vector>
#include <iostream>
#include<functional>
#include "sorts.h"
using namespace std;

int main() {
    std::vector<unsigned> numbers = {30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "starts as: " << numbers << endl;
    quick_sort(numbers);
    cout << "ends as : " << numbers << endl;

    std::vector<unsigned> numbers3 = {81,94,11,96,12,35,17,95,28,58,41,75,15};
    cout << "starts as: " << numbers3 << endl;
    insertion_sort(numbers3);
    cout << "ends as : " << numbers3 << endl;

    // TODO(student): write tests
     std::vector<unsigned> numbers2 = {8,1,9,4,1,1,9,6,1,2,3,5,1,7,9,5,2,8,5,8,4,1,7,5,1,5};
     cout << "starts as: " << numbers2 << endl;
    bucket_sort(numbers2);
    cout << "ends as : " << numbers2 << endl;

    std::vector<unsigned> numbers4 = {81,94,11,96,12,35,17,95,28,58,41,75,15};
    cout << "starts as: " << numbers4 << endl;
    shell_sort(numbers4);
    cout << "ends as : " << numbers4 << endl;

    std::vector<unsigned> numbers5 = {81,94,11,96,12,35,17,95,28,58,41,75,15};
    cout << "starts as: " << numbers5 << endl;
    merge_sort(numbers5);
    cout << "ends as : " << numbers5 << endl;
    return 0;
}
