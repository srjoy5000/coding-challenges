#include <bits/stdc++.h>
using namespace std;

// my answer
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size();
        // for (int x : nums) cout << x << " ";
        vector<int> dp(n + 1);
        dp[1] = 1;
        int pos = 2;
        int len = 1;
        while (pos <= n)
        {
            if ((nums[pos - 2] + 1) == nums[pos - 1])
            {
                dp[pos] = dp[pos - 1] + 1;
            }
            else
            {
                dp[pos] = 1;
            }
            if (dp[pos] > len)
                len = dp[pos];
            // cout << dp[pos] << endl;
            pos++;
        }
        return len;
    }
};
