#include <bits/stdc++.h>
using namespace std;

// my solution
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();
        int v_max = 0;

        for (int l = 0; l < n; ++l)
        {
            for (int r = n - 1; r > l; --r)
            {
                int min_h = min(heights[l], heights[r]);
                int len = r - l;
                v_max = max(v_max, min_h * len);
            }
        }
        return v_max;
    }
};

// solution 2
class Solution
{
public:
    int maxArea(vector<int> &heights)
    {
        int n = heights.size();
        int v_max = 0;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int min_h = min(heights[l], heights[r]);
            int len = r - l;
            v_max = max(v_max, min_h * len);

            if (heights[l] <= heights[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return v_max;
    }
};