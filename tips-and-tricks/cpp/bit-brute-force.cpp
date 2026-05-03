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

// 今の書き方（正しい）
// int d = (1 << j);
// bit[j] = (i / d) % 2;

// // よく使われる書き方（もっと楽）
// if ((i >> j) & 1)
// {
//     total += a[j + 1];
//     set_cnt++;
// }
// (i >> j) & 1 で(i >> j)は
// i桁のビットのうちj桁分を切り捨てて(割って)マスキングする。j桁目が一番右の桁にくる！
// & 1はフィルターの役割で&(論理積)で一番右の桁以外を切り捨ててマスキングする！
//
// 例： i = 13(2進数で 1101)、 j = 2 のときのi >> j
// 1101 を右に 2回ずらします。
// 右側の 01 がポイッと捨てられます。 11|01と仕切りで考えるとわかりやすい
// 手元に残るのは 11 です。
// 知りたかった「右から2番目（0から数えて）」のカードが、一番右端に来ました！
//
// 例：さきほどの 11 に & 1 をすると…
// 11(調べたい列)
// 01(フィルター：1)
// 結果：一番右は 1 &
// 1 で 1、その隣は 1 & 0 で 0。
// 最終的な答えは 1 になります！

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
            // ここが一番重要　(int Div = jはダメ)、bitの位で割る必要があるため
            int Div = (1 << j);
            bit[j] = (i / Div) % 2; // convert i to bitmask (e.g. 8 to 111), % 2 is same as % (1 << 1)
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