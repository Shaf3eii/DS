#include <iostream>
#include <queue>
using namespace std;

class Last_k_numbers_sum{
    queue<int> q;
    int nums{0};
    int sum {0};
public:
    Last_k_numbers_sum(int k) : nums(k){}
    int next(int num)
    {
        if(q.size() == nums)
        {
            sum -= q.front();
            q.pop();
            q.push(num);
            sum += num;
        }
        else
        {
            q.push(num);
            sum += num;
        }
        cout << "Sum of the Last k Numbers = ";
        return sum;
    }
};

int main() {
    Last_k_numbers_sum process(4);
    int num;
    while(cin >> num)
        cout << process.next(num) << '\n';
    return 0;
}
