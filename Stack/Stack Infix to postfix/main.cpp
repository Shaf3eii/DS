#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

string infixToPostfix_digits(string &infix) {
    string postfix;
    stack<char> op;
    op.push('#'); // to avoid check if(!op.empty())
    infix.push_back('-'); // to avoid make another outside loop
    auto precedence = [](char c) -> int {
        if (c == '^') return 3;
        else if (c == '+' || c == '-') return 1;
        else if (c == '*' || c == '/') return 2;
        return 0;
    };
    for (auto &i: infix) {
        if (isdigit(i))
            postfix.push_back(i);
        else if (i == '(')
            op.push('(');
        else if (i == ')') {
            while (op.top() != '(') {
                postfix.push_back(op.top());
                op.pop();
            }
            op.pop(); // remove the (
        } else {
            while (precedence(i) != 3 && precedence(i) <= precedence(op.top())) {
                postfix.push_back(op.top());
                op.pop();
            }
            op.push(i);
        }
    }
    return postfix;
}

double evaluate_postfix(string &postfix) {
    stack<double> st;
    for (auto& i: postfix) {
        if (isdigit(i))
            st.push(i - '0');
        else {
            double top1 = st.top();
            st.pop();
            double top2 = st.top();
            st.pop();
            double ans;
            switch (i) {
                case '^':
                    ans = pow(top2, top1);
                    break;
                case '*':
                    ans = top2 * top1;
                    break;
                case '/':
                    ans = top2 / top1;
                    break;
                case '+':
                    ans = top2 + top1;
                    break;
                default:
                    ans = top2 - top1;
            }
            st.push(ans);
        }
    }
    return st.top();
}

string infixToPostfix_chars(string &s)
{
    string postfix;
    stack<char> op;
    op.push('#');
    s += '-';
    auto f = [](char c)->bool{return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (isdigit(c)));};
    auto p = [](char c)->int{
        if(c == '^')
            return 3;
        else if(c== '*' || c == '/')
            return 2;
        else if(c== '+' || c == '-')
            return 1;
        else
            return 0;
    };
    for(char i : s)
    {
        if(f(i))
            postfix += i;
        else if(i == '(')
            op.push('(');
        else if(i == ')')
        {
            while(op.top()!='(')
            {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while(p(op.top()) >= p(i))
            {
                postfix += op.top();
                op.pop();
            }
            op.push(i);
        }
    }
    return postfix;
}

int main() {
    string s, res;
    cin >> s;
    res = infixToPostfix_chars(s);
//    cout << evaluate_postfix(res) << '\n';
    cout << res;
    return 0;
}
