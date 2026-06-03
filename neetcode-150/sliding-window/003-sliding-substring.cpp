#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
using namespace std;
using ll = long long;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int l = 0, maxL = 0;
        unordered_set<char> seen;

        for (int r = 0; r < n; ++r)
        {
            while (seen.contains(s[r]))
            {
                seen.erase(s[l++]);
            }
            seen.insert(s[r]);
            maxL = max(maxL, r - l + 1);
        }

        return maxL;
    }
};
