//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#include "Stack.h"

void Stack::insert(int val) {
    int size = added_elements;
    q.enqueue(val);
    while(size--)
    {
        q.enqueue(q.get_front());
        q.dequeue();
    }
    added_elements++;
}

void Stack::push(int val) {
    insert(val);
}

int Stack::peek() const {
    if(is_Empty())
        throw out_of_range("The Stack is Empty.\n");
    return q.get_front();
}

bool Stack::is_Empty() const {
    return q.is_Empty();
}

void Stack::pop() {
    if(is_Empty())
        throw out_of_range("The Stack is Empty.\n");
    added_elements--;
    q.dequeue();
}


