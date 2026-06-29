#include <bits/stdc++.h>
using namespace std;
// my answer (accepted)
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int l = 0, r = n - 1, vol = 0;
        int max_l = height[l];
        int max_r = height[r];
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                l++;
                int diff = max_l - height[l];
                if (diff > 0)
                    vol += diff;
                max_l = max(height[l], max_l);
            }
            else
            {
                r--;
                int diff = max_r - height[r];
                if (diff > 0)
                    vol += diff;
                max_r = max(height[r], max_r);
            }
        }
        return vol;
    }
};
