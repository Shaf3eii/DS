//
// Created by Mahmoud Elshafei on 8/4/2024.
//

#ifndef PRIORITY_QUEUE_PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_PRIORITY_QUEUE_H

#include "Queue.h"
class Priority_Queue {
    Queue q1,q2,q3;
    int added_elements {0};
public:
    void enqueue(int ,int);
    int dequeue();
    bool is_Empty()const;
    void display()const;
};


#endif //PRIORITY_QUEUE_PRIORITY_QUEUE_H
