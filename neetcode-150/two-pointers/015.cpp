#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int rem = 0 - (nums[i] + nums[j]);
                auto it = lower_bound(nums.begin() + (j + 1), nums.end(), rem);
                int k = it - nums.begin();
                if (it != nums.end() && nums[k] == rem)
                {
                    // cout << i << " " << j << " " << k << " " << rem << endl;
                    ans.insert({nums[i], nums[j], nums[k]});
                }
            }
        }
        vector<vector<int>> ans_v = {ans.begin(), ans.end()};
        return ans_v;
    }
};
// -4, -1, -1, 0, 1, 2