#include "BinaryTree.h"

int main() {
    BinaryTree T(1);
    T.add({2,4,5},{'L','L','R'});
    T.add({3,6},{'R','L'});
    T.add({2,4,7},{'L','L','L'});
    T.add({2,4,8},{'L','L','R'});
    T.add({2,5,9},{'L','R','R'});
    T.add({2,5,4},{'L','R','L'});
    T.add({3,6,10},{'R','R','L'});
    T.add({3,6,13},{'R','R','R'});
    T.add({3,6,13},{'R','L','L'});
    T.add({3,6,13},{'R','L','R'});
    T.print();
    cout << T.maxValue() << '\n';
    cout << T.maxDepth() << '\n';
    cout << T.hasPathSum(50) << '\n';
    cout << T.sumofleftleaves() << '\n';
    cout << T.isPerfectTree() << '\n';
    vector<vector<int>> zigzag = T.zigzagLevelOrder();
    for(auto&i : zigzag) {
        for (auto &j: i)
            cout << j << ' ';
        cout << '\n';
    }
    cout << T.goodnodes() << '\n';
    cout << T.diameterOfBinaryTree() << '\n';
    cout << T.isCompleteTree() << '\n';
    return 0;
}
