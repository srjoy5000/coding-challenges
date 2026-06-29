#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define debug(x) std::cerr << #x << " = " << (x) << std::endl
using namespace std;
using ll = long long;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (*it != target)
            return -1;
        else
            return it - nums.begin();
    }
};
