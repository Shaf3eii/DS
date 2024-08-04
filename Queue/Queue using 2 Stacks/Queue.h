//
// Created by Mahmoud Elshafei on 8/4/2024.
//

#ifndef QUEUE_USING_2_STACKS_QUEUE_H
#define QUEUE_USING_2_STACKS_QUEUE_H
#include "Stack.h"

class Queue {
    int added_elements { };
    int size { };
    Stack s1;
    Stack s2;
public:
    Queue();
    Queue(int);
    void enqueue(int);
    int dequeue();
    bool is_Empty() const;
};


#endif //QUEUE_USING_2_STACKS_QUEUE_H
