#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        stack<double> tGoal;
        vector<pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i)
        {
            cars[i] = {position[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());
        for (int i = 0; i < n; ++i)
        {
            double rest = target - cars[i].first;
            double t = rest / cars[i].second;
            if (i == 0 || tGoal.top() < t)
                tGoal.push(t);
            else
            {
                tGoal.push(tGoal.top());
            }
        }
        unordered_set<double> ans;
        while (!tGoal.empty())
        {
            ans.insert(tGoal.top());
            cout << tGoal.top() << endl;
            tGoal.pop();
        }
        return ans.size();
    }
};
