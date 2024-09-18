//
// Created by Mahmoud Elshafei on 9/16/2024.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#include <iostream>

using namespace std;

struct Binary_Node {
    int data{};
    int height{};
    Binary_Node *left{};
    Binary_Node *right{};

    Binary_Node(int data) : data(data) {

    }
};

class AVL {
    Binary_Node *root;

    int child_height(Binary_Node *);
    int update_height(Binary_Node *);
    int balance_factor(Binary_Node *);
    Binary_Node *right_rotation(Binary_Node *);
    Binary_Node *left_rotation(Binary_Node *);
    Binary_Node *insert_node(Binary_Node *, int);
    Binary_Node *balance_tree(Binary_Node *);
    Binary_Node *delete_node(Binary_Node *, int);
    pair<bool, int> _upper_bound(int, pair<bool, int> &, Binary_Node *);
    pair<bool, int> _lower_bound(int, pair<bool, int> &, Binary_Node *);
    void print_inorder(Binary_Node*);
    void print_preorder(Binary_Node*);
    void delete_tree(Binary_Node*);
    bool search(int, Binary_Node*);
public:
    AVL();
    ~AVL();
    void insert(int);
    void erase(int);
    int upper_bound(int);
    int lower_bound(int);
    void print_inorder();
    void print_preorder();
    bool search(int);
};


#endif //AVL_AVL_H
