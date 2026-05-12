#include <bits/stdc++.h>
using namespace std;

// my 1st try
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> seen;
        for (int i = 0; i < n; ++i)
        {
            string str_sorted = strs[i];
            sort(str_sorted.begin(), str_sorted.end());
            if (seen.find(str_sorted) != seen.end())
            {
                seen[str_sorted].push_back(strs[i]);
            }
            else
            {
                seen[str_sorted].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for (auto &pair : seen)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
