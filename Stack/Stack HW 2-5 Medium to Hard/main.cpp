#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// problem #1
void Asteroid_collision() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    stack<int> out;
    for (auto &i: arr) {
        bool alive = true;
        while (!out.empty() && i < 0 && out.top() > 0) {
            if (-i > out.top()) {
                out.pop();
                continue;
            } else if (-i == out.top())
                out.pop();
            alive = false;
            break;
        }
        if (alive)
            out.push(i);
    }
    vector<int> res;
    while (!out.empty()) {
        res.push_back(out.top());
        out.pop();
    }
    reverse(res.begin(), res.end());
    for (auto &i: res)
        cout << i << " ";
    cout << '\n';
}

// problem #2
void insert_to_bottom(int x, stack<int> &st) {
    // base case
    if (st.empty()) {
        st.push(x);
        return;
    }
    // transition
    int ele = st.top();
    st.pop();
    insert_to_bottom(x, st);
    st.push(ele);
}

// problem #3
void Reverse_Stack(stack<int> &st) {
    // base case
    if (st.empty())
        return;
    // transition
    int ele = st.top();
    st.pop();
    Reverse_Stack(st);
    insert_to_bottom(ele, st);
}

// problem #4
void score_of_parentheses() {
    string s;
    cin >> s;
    stack<int> st;
    int score = 0;
    for (char i: s) {
        if (i == '(') {
            st.push(score);
            score = 0;
        } else {
            score = st.top() + max(score * 2, 1); // if my prev is 0 add the element , else -> multiple then add
            st.pop();
        }
    }
    cout << score;
}

// problem #5
// monotonic stack
// Reverse thinking
//        * 	Instead of finding the next greater of an element
//        * 	Use an element to find all items it is greater than them
//        *     We will add each new element in the stack waiting for its next greater
void next_greater_element() {
    int n;
    cin >> n;
    vector<int> v(n);
    stack<int> st; // we will push indices
    for (auto &i: v)
        cin >> i;

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && v[i] > v[st.top()]) {
            v[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        v[st.top()] = -1;
        st.pop();
    }
    for (int i = 0 ; i < n ; ++i)
        cout << v[i] << " \n"[i == n - 1];
}

void print(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << '\n';
}

int main() {
//    Asteroid_collision();
//    insert_to_bottom(10,st);
//    Reverse_Stack(st);
//    score_of_parentheses();
    next_greater_element();
    return 0;
}
