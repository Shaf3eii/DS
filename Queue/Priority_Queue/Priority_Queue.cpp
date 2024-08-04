//
// Created by Mahmoud Elshafei on 8/4/2024.
//

#include "Priority_Queue.h"

void Priority_Queue::enqueue(int val, int id) { // O(1) time - O(1) memory
    switch (id) {
        case 1:
            q1.enqueue(val);
            break;
        case 2:
            q2.enqueue(val);
            break;
        default:
            q3.enqueue(val);
    }
    added_elements++;
}

int Priority_Queue::dequeue() { // O(1) time - O(1) memory
    int ele = 0;
    if(!q3.is_Empty())
    {
        ele = q3.get_front();
        q3.dequeue();
    }
    else if(!q2.is_Empty())
    {
        ele = q2.get_front();
        q2.dequeue();
    }
    else if(!q1.is_Empty())
    {
        ele = q1.get_front();
        q1.dequeue();
    }
    added_elements--;
    return ele;
}

bool Priority_Queue::is_Empty() const { // O(1) time - O(1) memory
    return (q3.is_Empty() && q2.is_Empty() && q1.is_Empty());
}

void Priority_Queue::display() const { // o(n) time - O(1) memory
    if(!q3.is_Empty())
    {
        cout << "Priority #3 tasks: ";
        q3.print();
    }
    if(!q2.is_Empty())
    {
        cout << "Priority #2 tasks: ";
        q2.print();
    }
    if(!q1.is_Empty())
    {
        cout << "Priority #1 tasks: ";
        q1.print();
    }
    cout << "-----------------\n";
}

