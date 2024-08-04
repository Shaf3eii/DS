#include <iostream>

using namespace std;

class Stack {
    int *arr{};
    int added_elements{};
    int size {};
public:
    Stack(int elements) : added_elements(0) {
        arr = new int[elements];
        size = elements;
    }

    ~Stack() {
        delete[]arr;
    }
    void print()
    {
        for(int i = 0 ; i < added_elements; ++i)
            cout << arr[i] << " ";
        cout << '\n';
    }

    bool push(int val) {
        if (added_elements == size)
            return false;
        if (!added_elements)
            arr[0] = val;
        else {
            for (int i = added_elements; i >= 0; --i)
                arr[i + 1] = arr[i];

            arr[0] = val;
        }
        added_elements++;
        return true;
    }
    bool peek()
    {
        if(!added_elements)
            return false;
        cout << arr[0] << '\n';
        return true;
    }
    bool pop()
    {
        if(!added_elements)
            return false;
        for(int i = 0 ; i < added_elements - 1;++i)
            arr[i] = arr[i + 1];
        added_elements--;
        return true;
    }
};

int main() {
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(5);
    s.pop();
    s.print();
    s.peek();
    return 0;
}
