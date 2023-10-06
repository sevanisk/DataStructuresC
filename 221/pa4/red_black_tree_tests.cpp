#include "red_black_tree.h"
using std::max, std::min, std::cout, std::endl, std::invalid_argument;
int main() {  
    RedBlackTree<int>* tree = new RedBlackTree<int>{};
    int a = 6;
    int b = 4;
    int c = 2;
    int c2 = 1;
    int c3 = 3;
    int d = 8;
    int e = 10;
    tree->insert(a);
    tree->print_tree();
    cout << endl;
    tree->insert(b);
    tree->insert(c);
    tree->print_tree();
    cout << endl;
    tree->insert(d);
    tree->insert(e);
    tree->print_tree();
    tree->insert(c2);
    tree->insert(c3);
    cout << endl;

    RedBlackTree<int>* tree2 = tree;
    tree2->remove(14);

    cout << "contains 4? " << tree->contains(b) << endl;
    cout << "contains 7? " << tree->contains(7) << endl;

    tree->print_tree();

    tree->remove(a);
    tree->print_tree();
    tree->remove(e);
    tree->print_tree();
    tree->remove(b);
    tree->print_tree();


    cout << "contains 4? " << tree->contains(b) << endl;
    cout << "contains 7? " << tree->contains(7) << endl;


    try{
        cout << "find min" <<tree->find_min() << endl;
    }
    catch(...){}

    try{
        cout << "find max" <<tree->find_max() << endl;
    }
    catch(...){}

    tree->print_tree();
    delete tree;
    return 0;
    return 0;
}