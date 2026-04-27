// https : // atcoder.jp/contests/abc455/tasks/abc455_c
// I can solve now
// map<ll, ll> freq;
// vector<ll> sums(n + 9);
// for (auto [key, val] : freq)
//     sums.push_back(key *val);
// sort(sums.begin(), sums.end());

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> freq;
    for (int i = 0; i < n; ++i)
    {
        ll a;
        cin >> a;
        freq[a] += 1;
    }

    vector<ll> sums(n + 9);
    for (auto [key, val] : freq)
        sums.push_back(key * val);
    sort(sums.begin(), sums.end());

    for (int i = 0; i < k; ++i)
        if (!sums.empty())
            sums.pop_back();

    cout << reduce(sums.begin(), sums.end());

    return 0;
}