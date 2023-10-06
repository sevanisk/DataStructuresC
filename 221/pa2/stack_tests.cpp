#include <iostream>
#include "stack.h"

int main() {
    // TODO(student): test your code
    Stack<int>* s = new Stack<int>{};
    Stack<int>* s2 = new Stack<int>{};
    int i = 0;
    int j = 1;
    //int k = 2;

    s->push(i);
    cout << "MADE IT 1" << endl;
    s->push(j);
    s2->push(j);
    cout << "MADE IT 2" << endl;
    s->pop();
    cout << "MADE IT 3" << endl;
    s->pop();
    cout << "MADE IT 4" << endl;
    try{
        s->pop();
        cout << s->top() << endl;
    }
    catch(...){}

    cout << s2->top() << endl;
}
