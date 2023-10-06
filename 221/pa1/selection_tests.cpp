#include <stdexcept>
#include <cstddef>
#include <iostream>
#include "selection.h"
using namespace std;

int main(){
    int* a = new int[7] {8, 6, 7, 5, 3, 0, 9};
    cout << "SHOULD PRINT 9, PRINTS ";
    cout << select(1, a, 7) << endl;
    cout << "SHOULD PRINT 7, PRINTS ";
    cout << select(3, a, 7) << endl;
    cout << "SHOULD PRINT 6, PRINTS ";
    cout << select(4, a, 7) << endl;
    cout << "SHOULD PRINT 5, PRINTS ";
    cout << select(5, a, 7) << endl;
    cout << "SHOULD PRINT 0, PRINTS ";
    cout << select(7, a, 7) << endl;

    int* b = nullptr;
    try{
        cout << "SHOULD PRINT ERROR, PRINTS ";
        cout << select(1, b, 0) << endl;
    }
    catch(...){
        cout << "ERROR CAUGHT" << endl;
     }

    int* c = new int[3] {-2, -1, -4};
    cout << "SHOULD PRINT -1, PRINTS ";
    cout << select(1, c, 3) << endl;

    int* d = new int[3] {-2, 1, -4};
    cout << "SHOULD PRINT 1, PRINTS ";
    cout << select(1, d, 3) << endl;

    int* e = new int[3] {1, 1, 3};
    cout << "SHOULD PRINT 1, PRINTS ";
    cout << select(2, e, 3) << endl;

    try{
        cout << "SHOULD PRINT ERROR, PRINTS ";
        cout << select(0, a, 7) << endl;
    }
    catch(...){
        cout << "ERROR CAUGHT" << endl;
    }

    return 0;
}
