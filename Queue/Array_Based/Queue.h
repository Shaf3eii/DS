//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#ifndef ARRAY_BASED_QUEUE_H
#define ARRAY_BASED_QUEUE_H
#include <iostream>
using namespace std;

class Queue {
    int *arr { };
    int rear {0};
    int front{0};
    int capacity{0};
    int added_elements{0};
public:
    Queue();
    Queue(int size);
    ~Queue();
    bool is_Empty() const;
    bool is_Full() const;
    int get_next(int) const;
    void enqueue(int);
    void dequeue();
    int get_front() const;
    void clear();
    void print() const;
};


#endif //ARRAY_BASED_QUEUE_H
