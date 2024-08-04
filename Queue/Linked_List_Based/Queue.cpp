//
// Created by Mahmoud Elshafei on 8/3/2024.
//

#include "Queue.h"

Queue::~Queue() { // O(n) time - O(1) memory
    Node *cur = head;
    while(cur)
    {
        Node* deleted = cur;
        cur = cur->next;
        delete deleted;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void Queue::enqueue(int val) {
    Node* new_node = new Node(val);
    if(!length)
    {
        head = tail = new_node;
        length++;
        return;
    }
    tail->next = new_node;
    tail = new_node;
    tail->next = nullptr;
    length++;
}

void Queue::dequeue() {
    if(is_Empty())
        throw out_of_range("The Queue is Empty.\n");
    Node* deleted = head;
    head = head->next;
    length--;
    delete deleted;
}

bool Queue::is_Empty() const {
    return !length;
}

int Queue::size() const {
    return length;
}

void Queue::print() const {
    for(Node* cur = head ; cur ; cur = cur->next)
        cout << cur->data << ' ';
    cout << '\n';
}

int Queue::get_front() const {
    if(is_Empty())
        throw out_of_range("The Queue is Empty.\n");
    return head->data;
}

