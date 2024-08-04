#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    q.dequeue();
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(6);
    cout << q.get_front() << '\n';
    cout << q.size() << '\n';
    q.print();
    return 0;
}
