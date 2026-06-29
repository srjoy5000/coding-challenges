#include <bits/stdc++.h>
using namespace std;

// first try
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (char c : s)
            if (c != ' ' && isalnum(c))
                str += tolower(c);
        string orig = str;
        reverse(str.begin(), str.end());
        return str == orig;
    }
};

// 2nd version
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (!isAlNum(s[l]))
                l++;
            else if (!isAlNum(s[r]))
                r--;
            // Inline Post-Increments: In the final else branch, s[l++] and
            // s[r--] compare the characters first and then move the pointers in a single, compact line.
            else if (tolower(s[l++]) != tolower(s[r--]))
                return false;
        }
        return true;
    }

    bool isAlNum(char c)
    {
        return (c >= 'a' && c <= 'z' ||
                c >= 'A' && c <= 'Z' ||
                c >= '0' && c <= '9');
    }
};
