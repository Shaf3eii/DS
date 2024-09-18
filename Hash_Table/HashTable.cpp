//
// Created by Mahmoud Elshafei on 9/18/2024.
//

#include "HashTable.h"

bool HashTable::load_factor() const { // o(1) time - o(1) memory
    return double((double)hash_elements / (double)table_size) < 0.75;
}

void HashTable::expand_capacity() { // o(n) time - o(n) memory
    vector<vector<PhoneEntry>> old_table = table;
    table_size *= 2;
    table.clear();
    table.resize(table_size);

    hash_elements = 0;
    for(auto& i : old_table) {
        for(auto& cell : i)
            insert(cell);
    }
}

int HashTable::hash_string(string &str) const { // o(L) time - o(1) memory
    long long n = table_size;
    long long sum = 0;
    for(auto& c : str)
        sum = (sum * 26 + c - 'a') % n;

    return sum % n;
}

int HashTable::hash_num(int val) const { // o(1) time - o(1) memory
    long long n = table_size;
    return (val % n + n) % n;
}

HashTable::HashTable() : table_size(100) { // o(1) time - o(n) memory
    table.resize(table_size);
}

HashTable::HashTable(int size) : table_size(size) { // o(1) time - o(n) memory
    table.resize(table_size);
}

void HashTable::insert(PhoneEntry &phone) { // o(L) time - o(1) memory
    int idx = hash_string(phone.name);
    for(auto & i : table[idx]) {
        if(i.name == phone.name) {
            i = phone;
            return;
        }
    }
    table[idx].push_back(phone);
    hash_elements++;
    if(!load_factor())
        expand_capacity();
}

bool HashTable::search(string &name) const { // o(L) time - o(1) memory
    int idx = hash_string(name);
    for(auto& i : table[idx])
        if(i.name == name)
            return true;

    return false;
}

bool HashTable::remove(PhoneEntry &phone) { // o(L) time - o(1) memory
    int idx = hash_string(phone.name);
    for(int i = 0 ; i < table[idx].size() ; ++i) {
        if(table[idx][i].name == phone.name) {
            swap(table[idx][i],table[idx].back());
            table[idx].pop_back();
            hash_elements--;
            return true;
        }
    }
    return false;
}
