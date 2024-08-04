#include <iostream>
#include "Priority_Queue.h"
using namespace std;

int main() {
    Priority_Queue pq;
    pq.enqueue(1131,1);
    pq.enqueue(3111,3);
    pq.enqueue(2211,2);
    pq.enqueue(3161,3);
    pq.display();
    return 0;
}
