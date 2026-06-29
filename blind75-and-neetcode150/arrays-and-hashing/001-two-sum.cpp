#include <bits/stdc++.h>
using namespace std;
// solution 1
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if ((nums[i] + nums[j]) == target)
                    return {i, j};
            }
        }
    }
};

// solution 2
// use of hash map
// unordered_map<int, int>
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; ++i)
        {
            int diff = target - nums[i];
            if (seen.find(diff) != seen.end())
                return {seen[diff], i};
            else
                seen[nums[i]] = i;
        }
        return {};
    }
};
