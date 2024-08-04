#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    while(!q.is_Empty())
        cout << q.dequeue() << " ";
    cout << '\n';
    return 0;
}
