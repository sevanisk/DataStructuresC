#include <stdexcept>
#include <cstddef>
#include <iostream>
#include "collection.h"
using namespace std;

int main(){
    Collection<int>* c;
    c = new Collection<int>{};

    int a = 1;
    c->insert(a);
    cout << c->size() << "SIZE" << endl;
    cout << "empty? " << c->is_empty() << endl;

    if(c->contains(a)) {
        cout << "CONTAINS 1 " <<  endl;
    }

    c-> remove(a);
    cout << c->size() << "SIZE" << endl;
    cout << "empty?" << c->is_empty() << endl;

    int b = -5;
    cout << endl;
    cout << "MAKE EMPTY" << endl;
    c->insert(b);
    c->insert(a);
    cout << c->size() << "SIZE" << endl;
    c->make_empty();
    cout << c->size() << "SIZE" << endl;
    return 0;

    Collection<int>* c2 = c;
    c2->make_empty();

    delete c;
}
