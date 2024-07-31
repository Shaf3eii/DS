//
// Created by Mahmoud Elshafei on 7/7/2024.
//

#ifndef SINGLY_LINKED_LIST_SINGLE_LIST_H
#define SINGLY_LINKED_LIST_SINGLE_LIST_H

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

struct Node {
    int data{};  // my val
    Node *next{}; // link val to each other
    Node(int data) : data(data) {}

    //~Node() {cout << "Destroy value: " << data << " at address " << this << "\n";}

    void print(Node *head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << '\n';
    }

    void print_reversed(Node *head) {
        if (head == nullptr)
            return;
        print_reversed(head->next);
        cout << head->data << " ";
    }
};

class Single_List {
    Node *head = nullptr; // data    next
    Node *tail = nullptr;
    int length = 0;
    void black_box_debugging()const;
public:
    Single_List() = default;
    Single_List(const Single_List&) = delete;
    ~Single_List();
    Single_List &operator=(const Single_List &other) = delete;
    void print() const;
    int min_element() const;
    int max_element() const;
    int max_rec(Node* cur = nullptr,bool first_call = true) const;
    Node *find(int) const;
    int search(int) const;
    int nodes_sum() const;
    bool is_sorted() const;
    int improved_search(int)const;
    void insert_end(int);
    void insert_front(int);
    Node* get_nth(int)const;
    Node* get_nth_back(int)const;
    bool is_same(const Single_List &other);
    void remove_last();
    void remove_front();
    void remove_node_with_index(int);
    void remove_node_with_key(int);
    void swap_pairs();
    void reverse();
    void delete_even_position();
    void insert_sorted(int);
    void swap_head_tail();
    void print_address();
    void left_rotate(int);
    void remove_duplicates();
    void remove_last_occurrence(int);
    void move_occurrence_to_last(int);
    int size() const;
};


#endif //SINGLY_LINKED_LIST_SINGLE_LIST_H
