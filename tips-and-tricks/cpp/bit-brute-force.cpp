// from: https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-1-bit-全探索
//
// void Binary(int x) // convert int x to binary
// {
//     int bit[30];
//     for (int i = 0; i < 30; i++)
//     {
//         int Div = (1 << i); // target binary place
// (x / Div) eliminates all the values under this place
// (x / Div) % 2 get the number of only the target place
//         bit[i] = (x / Div) % 2;
//     }
// }

// steps
// takes input
// create all bitmasks (2^N total bitmasks)

#include <iostream>
using namespace std;

int N, X, A[22];
bool flag = false;

int main()
{
    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 0; i < (1 << N); i++) // int # of all the combinations 8(000~111) (when N=3) or 2^N == (1 << N)
    {
        int bit[30], sum = 0;
        // # of coins N == # of digits in bitmask
        for (int j = 0; j < N; j++) // from coin[0] to coin[N]'s place (00'0') to ('0'00) when N=3
        {
            int Div = (1 << j);
            bit[j] = (i / Div) % 2; // convert i to bitmask (e.g. 8 to 111)
        }
        // bitmask is created as bit[j]

        for (int j = 0; j < N; j++)
            sum += A[j] * bit[j]; // (coin value) x (bit mask value (0 or 1))
        if (sum == X)             // if the sum matches the value X
            flag = true;
    }
    if (flag == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

// bit-brute-force applied to base-3 number
void solve(int x)
{
    int B[18], power3 = 1; // 3^0 == 1
    for (int i = 0; i < 18; i++)
    {
        B[i] = (x / power3) % 3;
        power3 *= 3; // 3^i from 3^1~3^17
    }
}