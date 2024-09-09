//
// Created by Mahmoud Elshafei on 8/25/2024.
//

#include "BinaryTree.h"

BinaryTree::BinaryTree(int val) : root(new TreeNode(val)) {} // o(1) time - o(1) memory

void BinaryTree::add(vector<int> values, vector<char> directions) { // o(n) time - o(n) memory
    if ((int) values.size() != (int) directions.size())
        throw out_of_range("Values Not Equal Size.\n");

    transform(directions.begin(), directions.end(), directions.begin(), ::toupper);

    TreeNode *cur = this->root;
    for (int i = 0; i < (int) values.size(); ++i) {
        if (directions[i] == 'R') {
            if (!cur->right)
                cur->right = new TreeNode(values[i]);
            else if (cur->right->data != values[i])
                throw out_of_range("Invalid Path.\n");
            cur = cur->right;
        } else if (directions[i] == 'L') {
            if (!cur->left)
                cur->left = new TreeNode(values[i]);
            else if (cur->left->data != values[i])
                throw out_of_range("Invalid Path.\n");
            cur = cur->left;
        } else
            throw out_of_range("Invalid Direction.\n");
    }
}

void BinaryTree::print() const { // o(n) time - o(n) memory
    _print(root);
    cout << '\n';
}

void BinaryTree::_print(TreeNode *cur) const {
    if (!cur)
        return;
    _print(cur->left);
    cout << cur->data << ' ';
    _print(cur->right);
}

int BinaryTree::maxValue() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    int max = -1e6;
    max = _maxValue(root, max);
    return max;
}

int BinaryTree::_maxValue(TreeNode *cur, int &Max) const {
    if (!cur)
        return -1e6;
    _maxValue(cur->right, Max);
    _maxValue(cur->left, Max);
    Max = max(Max, cur->data);
    return Max;
}

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
int BinaryTree::maxDepth() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    int cur_depth = 0, max_depth = 0;
    max_depth = _maxDepth(root);
    return max_depth;
}

//  first approach
int BinaryTree::_maxDepth(TreeNode *cur_node) const {
    if (!cur_node)
        return 0;
    return 1 + max(_maxDepth(cur_node->right), _maxDepth(cur_node->left));
}

//// Second approach
//int BinaryTree::_maxDepth(TreeNode* cur_node,int cur_depth,int &max_depth) const {
//    if(!cur_node) {
//        max_depth = max(cur_depth,max_depth);
//        return max_depth;
//    }
//    _maxDepth(cur_node->left,cur_depth+1,max_depth);
//    _maxDepth(cur_node->right,cur_depth+1,max_depth);
//    return max_depth;
//}


// return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
bool BinaryTree::hasPathSum(int target) const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    return _hasPathSum(root, target, 0);
}

bool BinaryTree::_hasPathSum(TreeNode *cur_node, int targetSum, int curSum) const {
    if (!cur_node)
        return false;

    curSum += cur_node->data;
    if (!cur_node->right && !cur_node->left) // we need to reach the leaves
        return curSum == targetSum;

    return _hasPathSum(cur_node->right, targetSum, curSum) ||
           _hasPathSum(cur_node->left, targetSum, curSum);
}


// return the sum of all left leaves.
int BinaryTree::sumofleftleaves() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    if (!root->right && !root->left)
        return 0;
    int Sum = 0;
    Sum = _sumofleftleaves(root, true, Sum);
    return Sum;
}

int BinaryTree::_sumofleftleaves(TreeNode *cur_node, bool left, int &cur_sum) const {
    if (!cur_node)
        return 0;
    if (!cur_node->left && !cur_node->right && left)
        cur_sum += cur_node->data;
    _sumofleftleaves(cur_node->left, true, cur_sum);
    _sumofleftleaves(cur_node->right, false, cur_sum);
    return cur_sum;
}

bool BinaryTree::isPerfectTree() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    int depth = maxDepth();
    return _isPerfectTree(root, depth, 0);
}


// The Tree is perfect if each node have 2 children except the leaf node
bool BinaryTree::_isPerfectTree(TreeNode *cur_node, int depth, int level) const {
    if (!cur_node)
        return true;
    if (!cur_node->left && !cur_node->right)
        return depth == (level + 1);
    if (!cur_node->left || !cur_node->right)
        return false;
    return _isPerfectTree(cur_node->left, depth, level + 1) ||
           _isPerfectTree(cur_node->right, depth, level + 1);
}


// return the zigzag level order traversal of its nodes' values.
vector<vector<int>> BinaryTree::zigzagLevelOrder() const { // O(n) time - O(n) memory
    vector<vector<int>> ans;
    if (!root)
        return ans;
    bool L_Or_R = true;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> cur;
        int sz = (int) q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode *node = q.front();
            q.pop();
            cur.push_back(node->data);
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
        if (L_Or_R)
            reverse(cur.begin(), cur.end());
        L_Or_R = !L_Or_R;
        ans.push_back(cur);
    }
    return ans;
}

// a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
int BinaryTree::goodnodes() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    return _goodnodes(root, root->data);
}

// first approach -> recursive
int BinaryTree::_goodnodes(TreeNode *cur_node, int largest_val) const {
    if (!cur_node)
        return 0;
    int count = 0;
    if (cur_node->data >= largest_val) {
        count = 1;                     // current node is good
        largest_val = cur_node->data; // update largest_val
    }
    count += _goodnodes(cur_node->left, largest_val);
    count += _goodnodes(cur_node->right, largest_val);
    return count;
}

//// second approach -> iterative
//int BinaryTree::goodnodes() const {
//    stack<pair<TreeNode*,int>> st;
//    st.push({root,INT_MIN});
//    int good = 0;
//    while(!st.empty()){
//        auto [node,val] = st.top();
//        st.pop();
//        if(val <= node->data)
//            good++, val = node->data;
//        if(node->left)st.push({node->left,val});
//        if(node->right)st.push({node->right,val});
//    }
//    return good;
//}

//// third approach -> iterative
//int BinaryTree::goodnodes() const {
//    queue<pair<TreeNode*,int>> q;
//    q.push({root,INT_MIN});
//    int good = 0;
//    while(!q.empty()){
//        auto [node,val] = q.front();
//        q.pop();
//        if(val <= node->data)
//            good++, val = node->data;
//        if(node->left)q.push({node->left,val});
//        if(node->right)q.push({node->right,val});
//    }
//    return good;
//}

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
int BinaryTree::diameterOfBinaryTree() const { // O(n) time - Balanced->O(log(n)) memory   skew->O(n)
    int max_diameter = 0;
    _diameterOfBinaryTree(root, max_diameter);
    return max_diameter;
}

int BinaryTree::_diameterOfBinaryTree(TreeNode *cur_node, int &MaxSoFar) const {
    if (!cur_node)
        return 0;

    int l = _diameterOfBinaryTree(cur_node->left, MaxSoFar);
    int r = _diameterOfBinaryTree(cur_node->right, MaxSoFar);
    MaxSoFar = max(MaxSoFar, l + r);
    return max(l, r) + 1;
}

//In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.
// It can have between 1 and 2h nodes inclusive at the last level h.
bool BinaryTree::isCompleteTree() const { // O(n) time - O(n) memory
    queue<TreeNode *> q;
    q.push(root);
    bool no_more = false;
    while (!q.empty()) {
        int sz = (int) q.size();
        for (int i = 0; i < sz; ++i) {
            TreeNode *node = q.front();
            q.pop();
            if (no_more && (node->left || node->right))
                return false;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            if (node->right && !node->left)
                return false;
            if ((!node->right && node->left) || (!node->right && !node->left))
                no_more = true;
        }
    }
    return true;
}


//// Another Approach
//bool BinaryTree::isCompleteTree() const { // O(n) time - O(n) memory
//    queue<TreeNode*> q;
//    q.push(root);
//    bool no_more = false;
//    while(!q.empty()) {
//        TreeNode* node = q.front();
//        q.pop();
//        if(!node)
//            no_more = true;
//        else {
//            if(no_more)
//                return false;
//            q.push(node->left);
//            q.push(node->right);
//        }
//    }
//    return true;
//}

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
bool BinaryTree::isSymmetric() const { // o(n) time - o(n) memory
    return _isSymmetric(root->left, root->right);
}

// recursively
bool BinaryTree::_isSymmetric(TreeNode *Left, TreeNode *Right) const {
    if (!Left && Right)
        return false;
    if (Left && !Right)
        return false;
    if (!Left && !Right)
        return true;
    return ((Left->data == Right->data) && _isSymmetric(Left->left, Right->right) &&
            _isSymmetric(Left->right, Right->left));
}


//// iteratively
//bool BinaryTree::isSymmetric() const {
//    queue<TreeNode *> q;
//    q.push(this->root);
//    while (!q.empty()) {
//        int sz = (int) q.size();
//        vector<int> temp;
//        for (int i = 0; i < sz; ++i) {
//            TreeNode *node = q.front();
//            q.pop();
//            if (node->left) {
//                q.push(node->left);
//                temp.push_back(node->left->data);
//            } else
//                temp.push_back(200);
//            if (node->right) {
//                q.push(node->right);
//                temp.push_back(node->right->data);
//            } else
//                temp.push_back(200);
//        }
//        int l = 0, r = (int) temp.size() - 1;
//        while (l <= r)
//            if (temp[l++] != temp[r--])
//                return false;
//    }
//    return true;
//}


// A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
bool BinaryTree::flipEquiv() const { // o(n) time - o(n) memory
    return _flipEquiv(root, root);
}

// recursively
bool BinaryTree::_flipEquiv(TreeNode *root1, TreeNode*root2) const {
    if (root1 == root2)
        return true;
    if ((!root1) || (!root2) || (root1->data != root2->data))
        return false;
    return _flipEquiv(root1->left, root2->left) && _flipEquiv(root1->right, root2->right) ||
            _flipEquiv(root1->left, root2->right) && _flipEquiv(root1->right, root2->left);
}


//// using representation
//string BinaryTree::_flipEquiv(TreeNode *node) const {
//    if(!node)
//        return "()";
//    string repr = "(" + to_string(node->data);
//    vector<string> v;
//    if(node->left)
//        v.push_back(_flipEquiv(node->left));
//    else
//        v.emplace_back("()");
//    if(node->right)
//        v.push_back(_flipEquiv(node->right));
//    else
//        v.emplace_back("()");
//    sort(v.begin(),v.end());
//    for(auto &i : v)
//        repr += i;
//    repr += ")";
//    return repr;
//}
