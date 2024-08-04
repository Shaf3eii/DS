//
// Created by Mahmoud Elshafei on 8/4/2024.
//

#include "Queue.h"

Queue::Queue() = default;

Queue::Queue(int size) : size(size) { // O(1) time - O(1) memory
    added_elements = 0;
}

void Queue::enqueue(int val) { // O(n) time - O(1) memory
    while(!s1.isEmpty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s2.push(val);
    while(!s2.isEmpty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    added_elements++;
}

int Queue::dequeue() { // O(1) time - O(1) memory
    int ele = s1.top();
    s1.pop();
    return ele;
}

bool Queue::is_Empty() const { // O(1) time - O(1) memory
    return s1.isEmpty();
}




//void Queue::enqueue(int val) { // O(1) time - O(1) memory
//    s1.push(val);
//    added_elements++;
//}
//
//int Queue::dequeue() { // O(n) time - O(1) memory
//    while(!s1.isEmpty())
//    {
//        s2.push(s1.top());
//        s1.pop();
//    }
//    int ele = s2.top();
//    s2.pop();
//    while(!s2.isEmpty())
//    {
//        s1.push(s2.top());
//        s2.pop();
//    }
//    return ele;
//}