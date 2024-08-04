//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#ifndef LINKED_LIST_BASED_QUEUE_H
#define LINKED_LIST_BASED_QUEUE_H

#include <iostream>
using namespace std;

struct Node{
    int data { };
    Node* next = nullptr;
    Node() = default;
    Node(int data) : data(data) {};
};

class Queue {
    Node* head{ };
    Node* tail{ };
    int length { };
public:
    ~Queue();
    void enqueue(int);
    void dequeue();
    bool is_Empty()const;
    int size()const;
    void print()const;
    int get_front()const;
};


#endif //LINKED_LIST_BASED_QUEUE_H
