#include "MinHeap.h"

int main() {
    MinHeap heap;
    heap.push(7);
    heap.push(2);
    heap.push(5);
    heap.push(4);
    heap.push(3);
    heap.push(9);
    heap.push(1);
    heap.push(8);
    heap.push(11);
    heap.push(12);
    heap.pop();
    heap.print();
    heap.pop();
    heap.print_less_than(10);
    return 0;
}
