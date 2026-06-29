#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;
        for (string str : strs)
        {
            res += to_string(str.size()) + '#' + str;
        }
        return res;
    }

    // i = current pos (i < s.size());
    // str_len = length of the "string length" string
    // len = actual length of the string
    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;
        while (i < s.size())
        {
            int str_len = 0;
            while (s[i + str_len] != '#')
            {
                str_len++;
            }
            int len = stoi(s.substr(i, str_len));
            i = i + str_len + 1;
            res.push_back(s.substr(i, len));
            i = i + len;
        }
        return res;
    }
};
