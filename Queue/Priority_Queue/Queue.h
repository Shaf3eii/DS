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
    int get_next(int) const;
    int get_prev(int) const;
public:
    Queue();
    Queue(int size);
    ~Queue();
    bool is_Empty() const;
    bool is_Full() const;
    void enqueue(int);
    void dequeue();
    int get_front() const;
    int size() const;
    void clear();
    void print() const;
};


#endif //ARRAY_BASED_QUEUE_H
