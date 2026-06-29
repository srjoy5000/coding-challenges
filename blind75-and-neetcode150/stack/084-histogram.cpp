#include <bits/stdc++.h>
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
using namespace std;
using ll = long long;

// my answer (took time but accepted)
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ans = 0;
        int n = heights.size();
        vector<int> hs = heights;
        sort(hs.begin(), hs.end()); // see from the lowest height

        for (int i = 0; i < n; ++i) // check the maximum rect area for each height limit hs[i]
        {
            int cLim = hs[i];
            int maxL = 0;
            int len = 0;
            for (int j = 0; j <= n; ++j)
            {
                if (j < n && heights[j] >= cLim)
                {
                    len++;
                }
                else
                {
                    maxL = max(maxL, len);
                    len = 0;
                }
            }
            ans = max(ans, cLim * maxL);
        }
        return ans;
    }
};
