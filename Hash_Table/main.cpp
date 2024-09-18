#include "HashTable.h"


int main() {
    HashTable hash;
    PhoneEntry P;
    P.name = "Mahmoud";
    P.phone = "01046123";
    hash.insert(P);
    P.name = "ShaFeiii";
    P.phone = "546123";
    hash.insert(P);
    string s;
    s = "Mahmoud";
    cout << hash.search(s) << '\n';
    hash.remove(P);
    s = "ShaFeiii";
    cout << hash.search(s) << '\n';
    return 0;
}
