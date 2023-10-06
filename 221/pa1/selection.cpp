#include <stdexcept>
#include <cstddef>
#include <iostream>
#include "selection.h"
using namespace std;

int select(size_t k, const int* list, size_t N) {
    // TODO(student): solve the selection problem
    
    if(N <= 0 || list == nullptr){
        throw invalid_argument("");
    }

    //cout << "LOOKING FOR " << k << " PLACE" << endl;
    if(k < 1 || k > N){
        throw invalid_argument("");
    }

    // new list to be sorted
    int* sorted_list = new int[N];

    // copy from old list
    for(size_t i=0; i < N; i++){
        sorted_list[i] = list[i];
    }

    int max_index = INT32_MIN;
    int temp = 0;
    // sort new list with selection sort
    for(size_t i = 0; i < N; i++){
        max_index = i;
        for(size_t j = i+1; j < N; j++){
            //find minimum 
            if(sorted_list[j] >= sorted_list[max_index]){
                max_index = j;
            }
        }

        //switch i index with min index
        temp = sorted_list[i];
        sorted_list[i] = sorted_list[max_index];
        sorted_list[max_index] = temp;

    }

    int selected = sorted_list[k-1];
    delete[] sorted_list;
    return selected;
}






//if repeated numbers try counting them up, then accelerating k by the number of occurrences
// i.e. if there's three 8's count them and then add three to k
// not necessarily a problem but its annoying to set up
