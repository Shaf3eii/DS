//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include "Queue.h"

class Stack {
    Queue q;
    int added_elements {0};
    void insert(int val);
public:
    void push(int);
    void pop();
    int peek() const;
    bool is_Empty()const;
};


#endif //STACK_STACK_H
