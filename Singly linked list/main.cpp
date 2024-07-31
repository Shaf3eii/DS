#include <iostream>
#include "Single_List.h"
using namespace std;


int main() {
    Single_List s1,s2;
//    s1.insert_end(2);
    s1.insert_end(1);
//    s1.insert_end(2);
//    s1.insert_end(2);
//    s1.insert_end(3);
//    s1.insert_end(3);
//    s1.insert_end(3);
    s1.insert_end(1);
    s1.insert_end(1);
    s1.insert_end(2);
    s1.insert_end(4);
    s1.insert_end(1);
    s1.insert_end(1);
//    s1.insert_end(8);
    s1.insert_end(1);
    s1.insert_end(7);
//    s1.insert_end(1);

    s1.print();
    cout << s1.max_rec() << '\n';
    return 0;
}
