#include <bits/stdc++.h>
using namespace std;

// 1st solution
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int price = prices[j] - prices[i];
                res = max(price, res);
            }
        }
        return res;
    }
};

// 2nd solution
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int l = 0, r = 1, res = 0;
        while (r < n)
        {
            int buy = prices[l];
            int sell = prices[r];
            if (buy < sell)
            {
                res = max(res, sell - buy);
            }
            else
            {
                // since buy > sell, it's better to set the idx of sell as new buy
                l = r;
            }
            r++;
        }
        return res;
    }
};

// 3rd solution
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxP = 0;
        int minBuy = prices[0];
        for (int &sell : prices)
        {
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};
