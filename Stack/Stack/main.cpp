#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack s(5);
    s.push(6);
    s.push(7);
    s.print();
    cout << s.get_middle() << '\n';
    cout << s.pop() << '\n';
    s.print();
    return 0;
}
