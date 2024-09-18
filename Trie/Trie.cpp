//
// Created by Mahmoud Elshafei on 9/10/2024.
//

#include "Trie.h"

Trie::Trie() = default; // o(1) time - o(1) memory

// Recursive version
void Trie::insert(string &str, int idx) { // o(l) time - o(l) memory
    if(idx == (int) str.size()) {
        isLeaf = true;
        return;
    }
    char pos = str[idx];
    if(!child[pos])
        child[pos] = new Trie();
    child[pos]->insert(str,idx + 1);
}


// Iterative version
//void Trie::insert(string &str, int idx) { // o(l) time - o(l) memory
//    Trie* cur = this;
//
//    for( ; idx < (int)str.size() ; ++idx) {
//        char pos = str[idx];
//        if (!cur->child[pos])
//            cur->child[pos] = new Trie();
//
//        cur =  cur->child[pos];
//    }
//    cur->isLeaf = true;
//}


// Recursive version
bool Trie::word_exist(string &str , int idx) { // o(l) time - o(l) memory
    if(idx == (int) str.size())
        return isLeaf;
    char pos = str[idx];
    if(!child[pos])
        return false;
    return child[pos]->word_exist(str,idx + 1);
}


// Iterative version
//bool Trie::word_exist(string &str , int idx)  { // o(l) time - o(1) memory
//    Trie* cur = this;
//    for( ; idx < (int)str.size() ; ++idx) {
//        char pos = str[idx];
//        if(!cur->child[pos])
//            return false;
//
//        cur = cur->child[pos];
//    }
//    return cur->isLeaf;
//}


// Recursive version
bool Trie::word_prefix(string &str, int idx) { // o(l) time - o(l) memory
    if(idx == (int)str.size())
        return true;
    char pos = str[idx];
    if(!child[pos])
        return false;
    return child[pos]->word_prefix(str,idx + 1);
}

string Trie::first_word_prefix(string &str, int idx) { // o(l) time - o(1) memory
    Trie* cur = this;
    string pre;
    for(idx = 0 ; idx < (int)str.size() ; ++idx) {
        char pos = str[idx];
        if(!cur->child[pos] || cur->isLeaf)
            break;
        else
            pre += str[idx];
        cur = cur->child[pos];
    }
    return pre;
}

void Trie::get_all_strings(vector<string> &res, string SoFar) { // o(NL) time - o(n) memory
    if(isLeaf)
        res.push_back(SoFar);
    for(auto & i : child)
            i.second->get_all_strings(res, SoFar + char(i.first));
}

void Trie::auto_complete(string &str,vector<string> &v) {
    Trie* cur = this;
    string s;
    for(char pos : str) {
        if(!cur->child[pos])
            return;
        s += pos;
        if(cur->child[pos]->isLeaf)
            v.push_back(s);
        cur = cur->child[pos];
    }
    for(char i = 'a' ; i <= 'z' ; ++i) {
        if(!cur->child[i])
            continue;
        s += char(i);
        if(cur->child[i]->isLeaf)
            v.push_back(s);
        cur = cur->child[i];
    }
}