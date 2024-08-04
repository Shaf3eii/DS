#include <iostream>
using namespace std;

class two_stacks{
    int *arr{};
    int top1{};
    int top2{};
public:
    two_stacks(){
        arr = new int[100];
        top1 = -1;
        top2 = 49;
    }
    ~two_stacks(){
        delete []arr;
    }
    void push(int id , int val)
    {
        if(id == 1)
        {
            if(top1 == 49)
                return;
            arr[++top1] = val;
        }
        else
        {
            if(top2 == 100)
                return;
            arr[++top2] = val;
        }
    }
    void pop(int id)
    {
        if(id == 1)
        {
            if(top1 >= 0)
                --top1;
        }
        else
        {
            if(top2 >= 50)
                --top2;
        }
    }
    int peek(int id)
    {
        if(id == 1)
            return arr[top1];
        return arr[top2];
    }
    void display()
    {
        for(int i = top1 ; i >= 0 ; --i)
            cout << arr[i] << ' ';
        cout << '\n';
        for(int i = top2 ; i > 49 ; --i)
            cout << arr[i] << ' ';
        cout << '\n';
    }
};

int main() {
    two_stacks s;
    s.push(1 , 5);
    s.push(1 , 4);
    s.push(2 , 2);
    s.push(2 , 1);
//    s.pop(2);
    s.display();
    cout << s.peek(1) << '\n';
    cout << s.peek(2) << '\n';
    return 0;
}
