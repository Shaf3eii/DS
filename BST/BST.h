//
// Created by Mahmoud Elshafei on 9/1/2024.
//

#ifndef BST_BST_H
#define BST_BST_H
#include <iostream>
using namespace std;
#include <queue>

struct TreeNode {
    int val { };
    TreeNode* left { };
    TreeNode* right { };
    TreeNode(int val) : val(val) {}
};

class BST {
    TreeNode* root{ };
    void _insert(TreeNode*,int);
    void _print_inoreder(TreeNode*) const;
    int _Max_Value(TreeNode*)const;
    int _Min_Value(TreeNode*)const;
    bool _search(TreeNode*,int)const;
    int _lowestCommonAncestor(TreeNode*,int,int)const;
    bool _isValidBST(TreeNode*,long long ,long long )const;
public:
    BST(int);
    void insert(int);
    void print_inoreder() const;
    int Max_Value()const;
    int Min_Value()const;
    bool search(int)const;
    int lowestCommonAncestor(int,int)const;
    bool isValidBST() const;
};


#endif //BST_BST_H
