#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue q(5);
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(9);
    cout << q.get_front() << " \n";
    q.print();
    return 0;
}
