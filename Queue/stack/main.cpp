#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack st;
    st.push(10);
    st.push(1);
    st.push(5);
    st.push(7);
    while(!st.is_Empty())
    {
        cout << st.peek() << " ";
        st.pop();
    }
    return 0;
}
