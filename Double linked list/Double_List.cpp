//
// Created by Mahmoud Elshafei on 7/17/2024.
//

#include "Double_List.h"

// Debugging tool
void Double_List::black_box_debugging() {
    if (!length) {
        if (head != nullptr || tail != nullptr)
            throw out_of_range("Length is zero, but head and/or tail are not null.\n");
    } else {
        if (head == nullptr)
            throw out_of_range("Length is greater than zero, but head is null.\n");
        if (head->prev != nullptr)
            throw out_of_range("Head's prev pointer should be null.\n");
        if (tail == nullptr)
            throw out_of_range("Length is greater than zero, but tail is null.\n");
        if (tail->next != nullptr)
            throw out_of_range("Tail's next pointer should be null.\n");
    }
}


void Double_List::link(Node *first, Node *second) const { // O(1) time - O(1) memory
    if (first)
        first->next = second;
    if (second)
        second->prev = first;
}

void Double_List::print() const { // O(n) time - O(1) memory
    for (Node *cur = head; cur; cur = cur->next)
        cout << cur->data << " \n"[cur == tail];
}

void Double_List::print_reversed() const { // O(n) time - O(1) memory
    for (Node *cur = tail; cur; cur = cur->prev)
        cout << cur->data << " \n"[cur == head];
}

void Double_List::print_address() const {
    for(Node* cur = head ; cur ; cur = cur->next)
        cout << cur << " ";
    cout << '\n';
}

int Double_List::search(int val) const { // O(n) time - O(1) memory
    int idx = 0;
    for (Node *cur = head; cur; idx++, cur = cur->next) {
        if (cur->data == val)
            return idx;
    }
    return -1;
}

void Double_List::insert_sorted(int val) { // O(n) time - O(1) memory
    if (!length || head->data >= val)
        insert_front(val);

    else if (tail->data <= val)
        insert_end(val);

    else {
        for (Node *cur = head; cur; cur = cur->next) {
            if (val <= cur->data) {
                Node *new_node = new Node(val);
                link(cur->prev, new_node);
                link(new_node, cur->next);
                length++;
            }
        }
    }
    black_box_debugging();
}

void Double_List::insert_front(int val) { // O(1) time - O(1) memory
    Node *new_node = new Node(val);
    if (!length)
        head = tail = new_node;
    else {
        link(new_node, head);
        head = new_node;
    }
    length++;
    black_box_debugging();
}

void Double_List::insert_end(int val) { // O(1) time - O(1) memory
    Node *new_node = new Node(val);
    if (!length)
        head = tail = new_node;
    else {
        link(tail, new_node);
        tail = new_node;
    }
    length++;
    black_box_debugging();
}

Double_List::~Double_List() { // O(n) time - O(1) memory
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    length = 0;
}

void Double_List::remove_front() { // O(1) time - O(1) memory
    if (!length)
        return;

    if (length == 1) {
        Node *cur = head;
        head = tail = nullptr;
        delete cur;
    } else {
        Node *cur = head;
        head = head->next;
        head->prev = nullptr;
        delete cur;
    }
    length--;
    black_box_debugging();
}

void Double_List::remove_end() { // O(1) time - O(1) memory
    if (!length)
        return;

    if (length == 1) {
        Node *cur = tail;
        head = tail = nullptr;
        delete cur;
    } else {
        Node *cur = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete cur;
    }
    length--;
    black_box_debugging();
}

void Double_List::remove_with_key(int val) { // O(n) time - O(1) memory
    if (!length)
        throw out_of_range("The List is Empty.\n");
    int idx = search(val);
    remove_with_index(idx);
}

void Double_List::remove_with_index(int idx) { // O(n) time - O(1) memory
    if (!length)
        throw out_of_range("The List is Empty.\n");
    int cnt = -1;
    for (Node *cur = head; cur; cur = cur->next) {
        if (++cnt == idx) {
            if (!cur->prev)
                remove_front();
            else if (!cur->next)
                remove_end();
            else {
                Node *deleted = cur;
                link(cur->prev, cur->next);
                delete deleted;
                length--;
                black_box_debugging();
            }
            return;
        }
    }
    cout << "This Index Doesn't Exist !!.\n";
}

void Double_List::delete_all_nodes_with_key(int val) { // O(n) time - O(1) memory
    if (!length)
        throw out_of_range("The List is Empty.\n");

    Node *cur = head;
    while (cur) {
        if (cur->data == val) {
            Node *deleted = cur;
            if (cur == head) {
                cur = cur->next;
                remove_front();
            }
            else if (cur == tail)
            {
                cur = nullptr;
                remove_end();
            }
            else {
                cur = cur->next;
                link(deleted->prev, deleted->next);
                delete deleted;
                length--;
            }
        }
        else
            cur = cur->next;
    }
    black_box_debugging();
}

void Double_List::delete_all_even_positions() { // O(n) time - O(1) memory
    if (length <= 1)
        return;
    int i = 0;
    Node *prev = nullptr;
    for (Node *cur = head; cur; i++) {
        if(i & 1)
        {
            Node* deleted = cur;
            if (prev != nullptr)
                prev->next = cur->next;
            else
                head = cur->next;
            if (cur->next == nullptr)
                tail = prev;
            cur = cur->next;
            delete deleted;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    length = (length + 1) / 2;
    black_box_debugging();
}

void Double_List::delete_all_odd_positions() { // O(n) time - O(1) memory
    if (length == 0)
        return;
    insert_front(-1);
    delete_all_even_positions();
    remove_front();
    black_box_debugging();
}

bool Double_List::is_palindrome() { // O(n) time - O(1) memory
    if(length <= 1)
        return true;

    for(Node* left = head , *right = tail ; right != left && right->next != left ; right = right->prev , left = left->next)
    {
        if(right->data != left->data)
            return false;
    }
    return true;
}

int Double_List::find_middle_with_next_prev() { // O(n) time - O(1) memory
    if(!length)
        throw out_of_range("The List is Empty.\n");

    for(Node* left = head , *right = tail ; ; right = right->prev , left = left->next)
    {
        if(right == left) // if length is odd
            return left->data;
        if(left->prev == right) // if length is even
            return left->data;
    }
}

int Double_List::find_middle_with_next() { // O(n) time - O(1) memory
    if(!length)
        throw out_of_range("The List is Empty.\n");

    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

void Double_List::swap_forward_with_backward(int k) { // O(n) time - O(1) memory
    if(length <= 1 || k <= 0 || k > (length / 2))
        return;

    if(length == 2 && k == 1) {
        swap(head, tail);
        head->next = tail;
        tail->next = nullptr;
        head->prev = nullptr;
        tail->prev = head;
        return;
    }

    int cnt = 0;
    Node* left = head;
    Node* right = tail;

    while(cnt < k - 1) {
        left = left->next;
        right = right->prev;
        cnt++;
    }

    if(left->prev)
        left->prev->next = right;
    if(left->next)
        left->next->prev = right;
    if(right->prev)
        right->prev->next = left;
    if(right->next)
        right->next->prev = left;

    Node* tempNext = left->next;
    Node* tempPrev = left->prev;

    left->next = right->next;
    left->prev = right->prev;
    right->next = tempNext;
    right->prev = tempPrev;

    if(left == head)
        head = right;
    else if(right == head)
        head = left;

    if(left == tail)
        tail = right;
    else if(right == tail)
        tail = left;

    black_box_debugging();
}

