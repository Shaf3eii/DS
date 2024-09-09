//
// Created by Mahmoud Elshafei on 9/9/2024.
//

#include "MinHeap.h"

void MinHeap::expand_capacity() { // o(n) time - o(n) memory
    capacity *= 2;
    int *arr2 = new int[capacity];
    copy(arr + 1, arr + size + 1, arr2 + 1);
    swap(arr, arr2);
    delete[]arr2;
}

void MinHeap::black_box_debugging(int idx) const { // o(n) time - o(n) memory -> recursive function
    // base case
    if(idx > size)
        return;
    // transition
    int left = leftchild(idx);
    int right = rightchild(idx);
    if(right <= size && arr[idx] > arr[right])
        throw runtime_error("Parent is bigger than right child.\n");
    if(left <= size && arr[idx] > arr[left])
        throw runtime_error("Parent is bigger than left child.\n");
    black_box_debugging(idx+1);
}

// utility functions
int MinHeap::get_size() const { // o(1) time - o(1) memory
    return size;
}

int MinHeap::rightchild(int idx) const { // o(1) time - o(1) memory
    int p = idx*2+1;
    return (p <= size ? p : -1);
}

int MinHeap::leftchild(int idx) const { // o(1) time - o(1) memory
    int p = idx * 2;
    return (p <= size ? p : -1);
}

int MinHeap::parent(int idx) const {
    return (idx != 1 ? idx / 2 : -1);
}

bool MinHeap::isempty() const { // o(1) time - o(1) memory
    return size == 0;
}

// rearrange the heap after every push
void MinHeap::heapify_up(int idx) { // best case -> o(1) time    worst case -> o(log(n)) time     o(1) memory
    while (idx > 1 && arr[idx] < arr[parent(idx)])
        swap(arr[idx],arr[parent(idx)]) , idx = parent(idx);
    black_box_debugging();
}

void MinHeap::heapify_down() { // o(log(n)) time - o(1) memory
    int idx = 1;
    while (leftchild(idx) <= size) {
        int left = leftchild(idx);
        int right = rightchild(idx);
        int smallerChild = left; // Assume left child is smaller

        if (right <= size && arr[right] < arr[left])
            smallerChild = right;

        if (arr[idx] > arr[smallerChild]) {
            swap(arr[idx], arr[smallerChild]);
            idx = smallerChild;
        } else
            break;
    }
    black_box_debugging();
}

MinHeap::MinHeap() = default; // o(1) time - o(1) memory

MinHeap::MinHeap(int val) { // o(1) time - o(1) memory
    size = capacity = 1;
    arr = new int[capacity];
    arr[size] = val;
}

MinHeap::~MinHeap() { // o(n) time - o(1) memory
    delete []arr;
    arr = nullptr;
}

void MinHeap::push(int val) { // best case -> o(1) time    worst case -> o(log(n)) time     o(1) memory
    if(size == capacity - 1)
        expand_capacity();
    arr[++size] = val;
    heapify_up(size);
}

void MinHeap::pop() { // o(log(n)) time - o(1) memory
    if(size > 0) {
        arr[1] = arr[size--];
        heapify_down();
    }
    else
        throw runtime_error("Heap is empty");
}

int MinHeap::top() const { // o(1) time - o(1) memory
    if(size > 0)
        return arr[1];
    else
       throw runtime_error("Heap is empty");
}

void MinHeap::print() const { // o(n) time - o(1) memory
    for(int i = 1 ; i <= size ; ++i)
        cout << arr[i] << " \n"[i == size];
}

void MinHeap::clear() { // o(n) time - o(1) memory
    size = 0;
    capacity = 1;
    delete []arr;
    arr = nullptr;
}

void MinHeap::print_less_than(int val) const { // best case -> o(1) time    worst case -> o(n) time     o(1) memory
    for(int i = 1 ; i <= size ; ++i) {
        if(arr[i] >= val)
            break;
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
