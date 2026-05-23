#include <bits/stdc++.h>
using namespace std;

// my solution
class Solution
{
public:
    bool isValid(string s)
    {
        map<char, char> brak =
            {{'(', ')'},
             {'{', '}'},
             {'[', ']'}};
        stack<char> open;
        for (char c : s)
        {
            if (brak.contains(c))
            {
                open.push(brak[c]);
            }
            else if (!open.empty() && open.top() == c)
            {
                open.pop();
            }
            else
                return false;
        }
        return open.empty();
    }
};
