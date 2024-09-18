//
// Created by Mahmoud Elshafei on 9/18/2024.
//

#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct PhoneEntry {
    string name;
    string phone;
    PhoneEntry() {
        name = "";
        phone = "";
    }
};

class HashTable {
    int table_size {};
    int hash_elements {};
    vector<vector<PhoneEntry>> table;

    bool load_factor() const;
    int hash_string(string &) const;
    int hash_num(int) const;
    void expand_capacity();
public:
    HashTable(int size);
    HashTable();
    void insert(PhoneEntry&);
    bool search(string&) const;
    bool remove(PhoneEntry&);
};


#endif //HASH_TABLE_HASHTABLE_H
