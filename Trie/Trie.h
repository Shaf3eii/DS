//
// Created by Mahmoud Elshafei on 9/10/2024.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

class Trie {
    map <char,Trie*>child;
    bool isLeaf{};
public:
    Trie();
    void insert(string &, int idx = 0);
    bool word_exist(string &, int idx = 0);
    bool word_prefix(string &, int idx = 0);
    string first_word_prefix(string &, int idx = 0);
    void auto_complete(string &,vector<string> &);
    void get_all_strings(vector<string> &,string SoFar = "");
};


#endif //TRIE_TRIE_H
