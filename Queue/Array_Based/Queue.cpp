//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#include "Queue.h"

Queue::Queue() : capacity(100) { // O(1) time - O(1) memory
    front = 0;
    rear = 0;
    added_elements = 0;
    arr = new int[capacity];
}

Queue::Queue(int size) : capacity(size) { // O(1) time - O(n) memory
    arr = new int[capacity];
    front = 0;
    rear = 0;
    added_elements = 0;
}

Queue::~Queue() { // O(1) time - O(1) memory
    delete[]arr;
    arr = nullptr;
    capacity = 0;
    front = 0;
    added_elements = 0;
    rear = 0;
}

bool Queue::is_Empty() const { // O(1) time - O(1) memory
    return !added_elements;
}

bool Queue::is_Full() const {  // O(1) time - O(1) memory
    return added_elements == capacity;
}

int Queue::get_next(int pos) const {  // O(1) time - O(1) memory
    // return (pos + 1) % capacity
    if (pos == capacity - 1)
        return 0;
    return ++pos;
}

void Queue::enqueue(int val) {  // O(1) time - O(1) memory
    if (is_Full())
        throw out_of_range("The Queue is Full.\n");
    arr[rear] = val;
    rear = get_next(rear);
    added_elements++;
}

void Queue::dequeue() {  // O(1) time - O(1) memory
    if (is_Empty())
        throw out_of_range("The Queue is Empty.\n");
    front = get_next(front);
    added_elements--;
}

void Queue::clear() {  // O(1) time - O(1) memory
    front = 0;
    rear = 0;
    capacity = 0;
    delete[]arr;
    arr = nullptr;
}

void Queue::print() const {  // O(n) time - O(1) memory
    if (is_Empty()) {
        cout << "The Queue is Empty.\n";
        return;
    }
    int size = 0;
    for (int i = front; size != added_elements; i = get_next(i), ++size)
        cout << arr[i] << " \n"[size == added_elements - 1];
}

int Queue::get_front() const {  // O(1) time - O(1) memory
    if (is_Empty())
        throw out_of_range("The Queue is Empty.\n");
    return arr[front];
}


