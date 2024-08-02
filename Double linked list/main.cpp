#include <iostream>
#include "Double_List.h"
using namespace std;


int main() {
    Double_List list{};
    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
//    list.insert_end(6);
//    list.insert_end(7);
//    list.insert_end(8);
    list.print();
    list.print_address();
    list.swap_forward_with_backward(3);
    list.print();
    list.print_address();

    return 0;
}
