//
// Created by Mahmoud Elshafei on 7/26/2024.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H
#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int data { };
    Node* next { };
    Node(int data) : data(data){}
};

class Stack {
    Node* head { };
    int length;
//    int middle;
    //void black_box_debugging()const;
public:
    Stack();
    Stack(int);
    ~Stack();
    void print() const;
    void push(int);
    int pop();
    int top() const;
    int get_middle()const;
    bool isEmpty() const;
};


#endif //STACK_STACK_H
