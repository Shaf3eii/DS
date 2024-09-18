//
// Created by Mahmoud Elshafei on 9/16/2024.
//

#include "AVL.h"

int AVL::child_height(Binary_Node *node) { // O(1) time - O(1) memory
    if (!node)
        return -1;
    return node->height;
}

int AVL::update_height(Binary_Node *node) { // O(1) time - O(1) memory
    if (!node)
        return -1;
    return node->height = 1 + max(child_height(node->left), child_height(node->right));
}

int AVL::balance_factor(Binary_Node *node) { // O(1) time - O(1) memory
    if (!node)
        return -1;
    return child_height(node->left) - child_height(node->right);
}

Binary_Node *AVL::balance_tree(Binary_Node *node) { // O(1) time - O(1) memory
    if(balance_factor(node) == 2) {
        if(balance_factor(node->left) == -1) // left - right imbalance ?
            node->left = left_rotation(node->left);

        node = right_rotation(node);
    } else if(balance_factor(node) == -2) {
        if(balance_factor(node->right) == 1) // right - left imbalance ?
            node->right = right_rotation(node->right);

        node = left_rotation(node);
    }
    return node;
}


Binary_Node *AVL::right_rotation(Binary_Node *Q) { // O(1) time - O(1) memory
    if(!Q)
        return nullptr;
    Binary_Node* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    update_height(Q);
    update_height(P);
    return P;
}

Binary_Node *AVL::left_rotation(Binary_Node *Q) { // O(1) time - O(1) memory
    if(!Q)
        return nullptr;
    Binary_Node* P = Q->right;
    Q->right = P->left;
    P->left = Q;
    update_height(Q);
    update_height(P);
    return P;
}

AVL::AVL() : root(nullptr) { } // O(1) time - O(1) memory

void AVL::insert(int val) { // o(log(n) time - o(1) memory
    if(!root)
        root = new Binary_Node(val);
    else
        root = insert_node(root,val);
}

Binary_Node *AVL::insert_node(Binary_Node *node, int val) { // o(log(n) time - o(1) memory
    if(val < node->data) {
        if(!node->left)
            node->left = new Binary_Node(val);
        else
            node->left = insert_node(node->left, val);
    }    else if(val > node->data) {
        if(!node->right)
            node->right = new Binary_Node(val);
        else
            node->right = insert_node(node->right, val);
    }
    update_height(node);
    return balance_tree(node);
}

void AVL::erase(int val) { // o(log(n) time - o(1) memory
    if(!root)
        throw runtime_error("Run Time Error.\n");
    else
        root = delete_node(root,val);
}

Binary_Node *AVL::delete_node(Binary_Node *node, int val) { // o(log(n) time - o(1) memory
    if(!node)
        return nullptr;

    if(val < node->data)
        node->left = delete_node(node->left , val);
    else if(val > node->data)
        node->right = delete_node(node->right, val);
    else {
        if(!node->right && !node->left) { // no children
            delete node;
            return nullptr;
        }
        if(node->right && !node->left) { // right child
            Binary_Node* tmp = node->right;
            delete node;
            return tmp;
        } else if(node->left && !node->right) { // left child
            Binary_Node* tmp = node->left;
            delete node;
            return tmp;
        } else { // two children
            Binary_Node* tmp = node->right;
            while(tmp->left)
                tmp = tmp->left;
            node->data = tmp->data;
            node->right = delete_node(node->right,tmp->data);
        }
    }
    update_height(node);
    return balance_tree(node);
}

int AVL::upper_bound(int target) { // o(log(n) time - o(1) memory
    pair<bool,int> exist = {false,INT_MAX};
    _upper_bound(target , exist, root);
    if(exist.first)
        return exist.second;
    return -1;
}

pair<bool, int> AVL::_upper_bound(int target, pair<bool, int> &exist, Binary_Node* node) { // o(log(n) time - o(1) memory
    if(!node)
        return exist;
    if(node->data > target) {
        exist.first = true;
        exist.second = min(exist.second,node->data);
        _upper_bound(target , exist,node->left);
    } else {
        _upper_bound(target,exist,node->right);
    }
    return exist;
}

void AVL::print_inorder() { // o(n) time - o(1) memory
    print_inorder(root);
}

void AVL::print_inorder(Binary_Node *node) { // o(n) time - o(1) memory
    if(!node)
        return;
    print_inorder(node->left);
    cout << node->data << ' ';
    print_inorder(node->right);
}

int AVL::lower_bound(int target) { // o(log(n) time - o(1) memory
    pair<bool,int> exist = {false,INT_MAX};
    _lower_bound(target , exist, root);
    if(exist.first)
        return exist.second;
    return -1;
}

pair<bool, int> AVL::_lower_bound(int target, pair<bool, int> &exist, Binary_Node* node) { // o(log(n) time - o(1) memory
    if(!node)
        return exist;
    if(node->data >= target) {
        exist.first = true;
        exist.second = min(exist.second,node->data);
        _lower_bound(target , exist,node->left);
    } else {
        _lower_bound(target,exist,node->right);
    }
    return exist;
}

AVL::~AVL() { // o(n) time - o(1) memory
    delete_tree(root);
}

void AVL::delete_tree(Binary_Node *node) { // o(n) time - o(1) memory
    if(!node)
        return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

void AVL::print_preorder() { // o(n) time - o(1) memory
    print_inorder(root);
}

void AVL::print_preorder(Binary_Node* node) { // o(n) time - o(1) memory
    if(!node)
        return;
    cout << node->data << ' ';
    print_preorder(node->left);
    print_preorder(node->right);
}

bool AVL::search(int target) {
    return search(target , root);
}

bool AVL::search(int target, Binary_Node *node) {
    if(!node)
        return false;
    if(node->data > target)
        return search(target,node->left);
    else if(node->data < target)
        return search(target,node->right);
    else
        return true;
}
