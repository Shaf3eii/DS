#include "BST.h"

int main() {
    BST T(50);
    T.insert(20);
    T.insert(40);
    T.insert(55);
    T.insert(60);
    T.insert(10);
    T.insert(15);
    T.insert(75);
    T.print_inoreder();
    cout << T.Max_Value() << '\n';
    cout << T.Min_Value() << '\n';
    cout << T.search(11) << '\n';
    cout << T.search(10) << '\n';
    cout << T.isValidBST() << '\n';
    return 0;
}
