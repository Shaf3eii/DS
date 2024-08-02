//
// Created by Mahmoud Elshafei on 7/17/2024.
//

#ifndef DOUBLE_LINKED_LIST_DOUBLE_LIST_H
#define DOUBLE_LINKED_LIST_DOUBLE_LIST_H

#include <iostream>

using namespace std;

struct Node {
    int data{ };
    Node *next{ };
    Node *prev{ };

    Node(int data) : data(data) {}
};


class Double_List {
    Node* head;
    Node* tail;
    int length;
    void black_box_debugging();
public:
    ~Double_List();
    void link(Node*,Node*)const;
    void print()const;
    void print_reversed()const;
    void print_address()const;
    int search(int)const;
    void insert_sorted(int);
    void insert_front(int);
    void insert_end(int);
    void remove_with_key(int);
    void remove_with_index(int);
    void remove_front();
    void remove_end();
    void delete_all_nodes_with_key(int);
    void delete_all_even_positions();
    void delete_all_odd_positions();
    bool is_palindrome();
    int find_middle_with_next_prev();
    int find_middle_with_next();
    void swap_forward_with_backward(int);
};


#endif //DOUBLE_LINKED_LIST_DOUBLE_LIST_H
