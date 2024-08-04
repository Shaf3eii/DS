//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#include "Deque.h"

void Deque::push_front(int val) {
    list.insert_front(val);
}

void Deque::push_back(int val) {
    list.insert_end(val);
}

void Deque::pop_front() {
    list.remove_front();
}

void Deque::pop_back() {
    list.remove_last();
}

int Deque::size() const {
    return list.size();
}

void Deque::display() const {
    list.print();
}

