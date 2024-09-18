#include "Trie.h"


int main() {
    Trie T;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) {
        string s;
        cin >> s;
        T.insert(s);
    }
    vector<string> res;
    string s = "abc";
    T.get_all_strings(res);
    for(auto &i : res)
        cout << i << '\n';
//    int q;
//    cin >> q;
//    while(q--) {
//        string s;
//        cin >> s;
//        cout << s << " : "<< (T.word_exist(s) ? "Exist" : "Not Exist") << '\n';
////        cout << s << " : " << T.first_word_prefix(s) << '\n';
//    }
    return 0;
}
