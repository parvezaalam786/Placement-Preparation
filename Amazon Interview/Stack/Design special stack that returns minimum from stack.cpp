#include<bits/stdc++.h>
using namespace std;

class Stack
{
    stack<int> s1;
    int min_ele = INT_MAX;
public:
    void push(int x)
    {
        if (s1.empty())
        {
            s1.push(x);
            min_ele = x;
        }
        else if (min_ele <= x)
        {
            s1.push(x);
        }
        else
        {
            s1.push(2 * x - min_ele);
            min_ele = x;
        }
    }
    int pop()
    {
        if (s1.empty())
            return -1;
        int popped;

        if (s1.top() < min_ele)
        {
            popped = min_ele;
            min_ele = 2 * min_ele - s1.top();
            s1.pop();
        }
        else
        {
            popped = s1.top();
            s1.pop();
        }
        return popped;
    }
    int getmin()
    {
        return min_ele;
    }
};

int main()
{
    Stack s1;
    s1.push(5);
    s1.push(2);
    s1.push(1);
    s1.push(4);
    cout << s1.getmin() << "\n";
    cout << s1.pop() << "\n";
    cout << s1.getmin() << "\n";
    cout << s1.pop() << "\n";
    return 0;
}