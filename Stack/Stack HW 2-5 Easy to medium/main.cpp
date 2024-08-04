#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

void reverse_sub_words(string &s)
{
    stack<char> rev;
    s += ' ';
    for(auto & c : s)
    {
        if(c != ' ')
            rev.push(c);
        else
        {
            while(!rev.empty())
            {
                cout << rev.top();
                rev.pop();
            }
            cout << ' ';
        }
    }
}

int reverse_a_number(int n)
{
    stack<int> rev;
    while(n != 0)
    {
        rev.push(n % 10);
        n /= 10;
    }
    int leading_zeroes = 1;
    while(!rev.empty())
    {
        n += (rev.top() * leading_zeroes);
        leading_zeroes *= 10;
        rev.pop();
    }
    return n;
}

bool Valid_Parentheses(string &s)
{
    stack<char> Parentheses;
    for(auto & c : s)
    {
        if(c == '{' || c == '[' || c == '(')
            Parentheses.push(c);
        else
        {
            if(Parentheses.empty())
                return false;
            else if(c == ')' && Parentheses.top() != '(')
                return false;
            else if(c == '}' && Parentheses.top() != '{')
                return false;
            else if(c == ']' && Parentheses.top() != '[')
                return false;

            Parentheses.pop();
        }
    }
    return Parentheses.empty();
}

string removeDuplicates(string &s)
{
    stack<char> dup;
    for(char c : s) {
        if(!dup.empty() && dup.top() == c)
            dup.pop();
        else
            dup.push(c);
    }
    string c;
    while(!dup.empty()) {
        c.push_back(dup.top());
        dup.pop();
    }
    reverse(c.begin(),c.end());
    return c;
}

int main() {
    int n ;cin >> n;
    cout << reverse_a_number(n);
    return 0;
}
