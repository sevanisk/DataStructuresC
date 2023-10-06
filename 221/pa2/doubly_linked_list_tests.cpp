#include <iostream>
#include "doubly_linked_list.h"

int main() {
    // TODO(student): test your code
    DoublyLinkedList<int>* l = new DoublyLinkedList<int>{};
    DoublyLinkedList<int>* m = new DoublyLinkedList<int>{};
    int h = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    l->insert(0, i);
    m = l;
    DoublyLinkedList<int>* n = l;
    l->insert(1, j);
    l->insert(2, k);
    l->insert(2, h);
    n->insert(1, j);
    m->insert(0, j);
    cout << "SIZE" << l->size() << endl;
    try{
        l->remove(0);
        l->remove(3);
        l->remove(l->size());
        l->remove(5);
    }
    catch(...){}
    //l->remove(1);
    //l->remove(0);
    return 0;
}