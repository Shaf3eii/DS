#include <iostream>
#include "Deque.h"
using namespace std;

int main() {
    Deque dq;
    dq.push_front(5);
    dq.push_front(1);
    dq.push_front(6);
    dq.push_front(4);
    dq.push_front(2);
    dq.push_back(7);
    dq.push_back(8);
    cout << dq.size() << '\n';
    dq.display();
    return 0;
}
