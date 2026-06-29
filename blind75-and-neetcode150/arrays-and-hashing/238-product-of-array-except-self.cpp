#include <bits/stdc++.h>
using namespace std;

// 累積積で前からと後ろからのものを用意する
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> forward(n), backward(n), res(n);
        for (int i = 0; i < n; ++i)
        {
            forward[i] = (i > 0 ? forward[i - 1] * nums[i] : nums[0]);
        }
        for (int i = n - 1; i >= 0; --i)
        {
            backward[i] = (i < n - 1 ? backward[i + 1] * nums[i] : nums[n - 1]);
        }
        for (int i = 0; i < n; ++i)
        {
            res[i] = (i > 0 ? forward[i - 1] : 1) * (i < n - 1 ? backward[i + 1] : 1);
        }
        return res;
    }
};
