//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#ifndef DEQUE_DEQUE_H
#define DEQUE_DEQUE_H
#include "Single_List.h"

class Deque {
    Single_List list;
public:
    void push_front(int val);
    void push_back(int val);
    void pop_front();
    void pop_back();
    int size() const;
    void display()const;

};


#endif //DEQUE_DEQUE_H
