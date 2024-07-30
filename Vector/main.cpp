#include <iostream>
#include "Vector.h"
using namespace std;

int main() {
    Vector a(5,6);
    a.PushBack(1);
    a.PushBack(2);
    a.PushBack(3);
    a.PushBack(4);
    a.PushBack(5);
    a.Resize(15);
    a.print();
    return 0;
}
