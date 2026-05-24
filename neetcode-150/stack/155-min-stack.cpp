#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    ::stack<int> stack;
    ::stack<int> minStack;
    MinStack()
    {
    }

    void push(int val)
    {
        stack.push(val);
        minStack.push(minStack.empty() ? val : min(val, minStack.top()));
    }

    void pop()
    {
        stack.pop();
        minStack.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};
