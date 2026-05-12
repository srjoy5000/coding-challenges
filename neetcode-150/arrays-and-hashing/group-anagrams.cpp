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
            seen[str_sorted].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        // 'pair' is a reference to an entry in your map, but it's just a name.
        // pair.first  -> The string key (the character counts)
        // pair.second -> The vector<string> (the list of anagrams)
        //
        // Without & : The compiler makes a copy of every item in the collection.
        // If you have a vector of 1, 000 strings, it will copy those strings one by one, which is slow and wastes memory.
        //
        // With &: You are creating a reference (an alias).
        // It’s like creating a shortcut to the original data. No copying happens, so it is much faster.
        for (auto &pair : seen)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
