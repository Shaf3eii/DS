//
// Created by Mahmoud Elshafei on 7/26/2024.
//

#include "Stack.h"

Stack::Stack() = default; // O(1) time - O(1) memory

Stack::Stack(int val) { // O(1) time - O(1) memory
    Node *new_node = new Node(val);
    head = new_node;
    length++;
}

Stack::~Stack() { // O(n) time - O(1) memory
    while(head)
    {
        Node* deleted = head;
        head = head->next;
        delete deleted;
    }
}

void Stack::print() const { // O(n) time - O(1) memory
    for (Node *cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << '\n';
}

void Stack::push(int val) { // O(1) time - O(1) memory
    Node *new_node = new Node(val);
    new_node->next = head;
    head = new_node;
    length++;
}

int Stack::pop() { // O(1) time - O(1) memory
    if (isEmpty())
        throw runtime_error("Stack is empty. Cannot pop.");

    int data = head->data;
    Node *deleted = head;
    head = head->next;
    length--;
    delete deleted;
    return data;
}

int Stack::top() const{ // O(1) time - O(1) memory
    if (isEmpty())
        throw runtime_error("Stack is empty. Cannot peak.");

    return head->data;
}

bool Stack::isEmpty() const { // O(1) time - O(1) memory
    return !head;
}

int Stack::get_middle() const {
    if(length & 1)
        return ceil(length / 2);
    else
        return (length / 2) + 1;
    return 0;
}






