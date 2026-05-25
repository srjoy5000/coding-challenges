#include <bits/stdc++.h>
using namespace std;

// I solved by myself
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stack;
        for (string &c : tokens)
        {
            if (c == "+" ||
                c == "-" ||
                c == "*" ||
                c == "/")
            {
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();
                int cal = 0;
                if ("+" == c)
                {
                    cal = a + b;
                }
                else if ("-" == c)
                {
                    cal = a - b;
                }
                else if ("*" == c)
                {
                    cal = a * b;
                }
                else if ("/" == c)
                {
                    cal = a / b;
                }
                stack.push(cal);
            }
            else
            {
                stack.push(stoi(c));
            }
        }
        return stack.top();
    }
};
