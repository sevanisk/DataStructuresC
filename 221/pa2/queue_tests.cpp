#include <iostream>
#include "queue.h"

int main() {
    Queue<int>* q = new Queue<int>{};
    int i = 0;
    int j = 1;
    //int k = 2;

    q->enqueue(i);
    q->enqueue(j);
    q->dequeue();
    q->front();
    return 0;
    // TODO(student): test your code
}
