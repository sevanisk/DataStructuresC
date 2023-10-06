#include <iostream>
#include "array_list.h"

int main() {
    // constructor
    ArrayList<int>* a = new ArrayList<int>{};

    ArrayList<int>* b = new ArrayList<int>{};

    // copy assignment operator
    a = b;

    // insert 
    int i = 1;
    int j = 2;
    int k = 3;
    a->insert(0, i);
    a->insert(1, j);

    // out of bounds insert
    try{
        a->insert(4, k);
    }
    catch(...){

    }
   
   // size
    cout << a->size() << " SIZE" << endl;

    // remove
    a->remove(0);

    // out of bounds remove
    try{
        a->remove(5);
    }
    catch(...){

    }

    // destructor
    delete a;
    return 0;
}
