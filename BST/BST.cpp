//
// Created by Mahmoud Elshafei on 9/1/2024.
//

#include "BST.h"

BST::BST(int val) : root(new TreeNode(val)) {  // o(1) time - o(1) memory

}

void BST::insert(int target) { // o(h) time - o(n) memory
    if (!root) {
        root = new TreeNode(target);
        return;
    }
    _insert(root, target);
}

void BST::_insert(TreeNode *cur_node, int target) {
    if (target < cur_node->val) {
        if (!cur_node->left)
            cur_node->left = new TreeNode(target);
        else
            _insert(cur_node->left, target);
    } else if (target > cur_node->val) {
        if (!cur_node->right)
            cur_node->right = new TreeNode(target);
        else
            _insert(cur_node->right, target);
    } // else : already exists
}

void BST::print_inoreder() const { // o(n) time - o(n) memory
    _print_inoreder(root);
    cout << '\n';
}

void BST::_print_inoreder(TreeNode *node) const {
    if (!node)
        return;
    _print_inoreder(node->left);
    cout << node->val << ' ';
    _print_inoreder(node->right);
}

int BST::Max_Value() const { // o(h) time - o(n) memory
    return _Max_Value(root);
}

int BST::_Max_Value(TreeNode *node) const {
    if (!node->right)
        return node->val;
    return _Max_Value(node->right);
}

int BST::Min_Value() const { // o(h) time - o(n) memory
    return _Min_Value(root);
}

int BST::_Min_Value(TreeNode *node) const {
    if (!node->left)
        return node->val;
    return _Min_Value(node->left);
}

bool BST::search(int val) const { // o(h) time - o(n) memory
    return _search(root, val);
}

// iteratively
bool BST::_search(TreeNode *Node, int val) const {
    queue<TreeNode *> q;
    q.push(Node);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        if (node->val == val)
            return true;
        if (node->left && node->val > val)
            q.push(node->left);
        else if (node->right && node->val < val)
            q.push(node->right);
    }
    return false;
}

//// recursively
//bool BST::_search(TreeNode* node , int val) const {
//    if(!node)
//        return false;
//    if(val == node->val)
//        return true;
//    if(val > node->val)
//        return _search(node->right,val);
//    return _search(node->left,val);
//}

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
bool BST::isValidBST() const {
    return _isValidBST(root, LONG_MIN, LONG_MAX);
}

bool BST::_isValidBST(TreeNode *node, long long int mini, long long int maxi) const {
    if (!node)
        return true;
    if (node->val >= maxi || node->val <= mini)
        return false;
    return _isValidBST(node->left, mini, node->val) && _isValidBST(node->right, node->val, maxi);
}

//  LCA(x, y): the farthest node from the root that is an ancestor for both x and y.
int BST::lowestCommonAncestor(int p, int q) const {
    return _lowestCommonAncestor(root, p, q);
}

int BST::_lowestCommonAncestor(TreeNode *node, int p, int q) const {
    if (!node)
        return -1;
    if ((node->val >= min(p, q)) && (node->val <= max(q, p)))
        return node->val;
    if (node->right && node->val < p)
        return _lowestCommonAncestor(node->right, p, q);
    return _lowestCommonAncestor(node->left, p, q);
}



