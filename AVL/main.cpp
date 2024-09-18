#include "AVL.h"


int main() {
    AVL T;
    T.insert(10);
    T.insert(15);
    T.insert(17);
    T.insert(5);
    T.insert(8);
    T.insert(3);
    T.insert(1);
    T.print_preorder();
    T.erase(5);
    cout << '\n';
    T.print_preorder();
    T.erase(17);
    cout << '\n';
    T.print_preorder();
    T.erase(1);
    cout << '\n';
    T.print_preorder();
    cout << "\n";
    cout << T.search(15) << '\n';
    cout << T.search(17) << '\n';
    cout << T.upper_bound(15) << '\n';
    cout << T.lower_bound(15) << '\n';
    return 0;
}
