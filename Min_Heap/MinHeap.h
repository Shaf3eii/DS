//
// Created by Mahmoud Elshafei on 9/9/2024.
//

#ifndef MIN_HEAP_MINHEAP_H
#define MIN_HEAP_MINHEAP_H

#include <iostream>

using namespace std;

class MinHeap {
    int *arr{};
    int size{};
    int capacity{1};

    void expand_capacity();
    void black_box_debugging(int idx = 1) const;
    void heapify_up(int);
    void heapify_down();
    int rightchild(int)const;
    int leftchild(int)const;
    int parent(int)const;
public:
    MinHeap();
    MinHeap(int);
    ~MinHeap();
    void push(int);
    void pop();
    int top() const;
    bool isempty() const;
    void print() const;
    int get_size() const;
    void clear();
    void print_less_than(int) const;
};


#endif //MIN_HEAP_MINHEAP_H
