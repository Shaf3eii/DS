//
// Created by Mahmoud Elshafei on 8/25/2024.
//

#ifndef BINARY_TREE_BINARYTREE_H
#define BINARY_TREE_BINARYTREE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int data { };
    TreeNode* right { };
    TreeNode* left { };
    TreeNode(int data) : data(data) {
    }
};

class BinaryTree {
    TreeNode* root { };
    void _print(TreeNode*) const;
    int _maxValue(TreeNode*,int&)const;
    int _maxDepth(TreeNode*)const;
    bool _hasPathSum(TreeNode*,int,int) const;
    int _sumofleftleaves(TreeNode*, bool, int&) const;
    bool _isPerfectTree(TreeNode*,int,int) const;
    int _goodnodes(TreeNode*, int) const;
    int _diameterOfBinaryTree(TreeNode*,int &)const;
    bool _isSymmetric(TreeNode*,TreeNode*) const;
    bool _flipEquiv(TreeNode*,TreeNode*) const;
public:
    BinaryTree(int);
    void add(vector<int>,vector<char>);
    void print() const;
    int maxValue()const;
    int maxDepth()const;
    bool hasPathSum(int) const;
    int sumofleftleaves() const;
    bool isPerfectTree() const;
    vector<vector<int>> zigzagLevelOrder() const;
    int goodnodes() const;
    int diameterOfBinaryTree()const;
    bool isCompleteTree() const;
    bool isSymmetric() const;
    bool flipEquiv() const;
};


#endif //BINARY_TREE_BINARYTREE_H
