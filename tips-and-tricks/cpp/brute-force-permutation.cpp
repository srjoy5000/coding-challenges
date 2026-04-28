// from https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-2-順列全探索

// use next_permutation() or recursive functions

// do
// {
//  // write the process here
// } while (next_permutation(P, P + N));
//
// when N = 3, P = (1, 2, 3)
// it will go through all the permutation of P over N! == 6 times

#include <iostream>
#include <algorithm> // for using nex_permutation
using namespace std;

int N, A[11][11], ans = 1e9; // 1e9 is 10^9
int P[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int main()
{
    // input
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];
    }

    // output
    do
    {
        int total = 0;                  // init total price to go all the cities
        for (int i = 0; i < N - 1; ++i) // go from one city to the next
        {
            total += A[P[i]][P[i + 1]]; // add the price
        }
        ans = min(ans, total); // store the minimum total to ans
    } while (next_permutation(P, P + N));

    cout << ans << "\n";
    return 0;
}
