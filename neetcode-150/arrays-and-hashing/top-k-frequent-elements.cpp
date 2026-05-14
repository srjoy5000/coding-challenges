#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        for (int num : nums)
        {
            freq[num]++;
        }
        vector<pair<int, int>> rfreq;
        for (auto &p : freq)
        {
            rfreq.push_back({p.second, p.first});
        }
        sort(rfreq.rbegin(), rfreq.rend());
        int cnt = 0;
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(rfreq[i].second);
        }
        return res;
    }
};
