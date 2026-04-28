// from https://qiita.com/e869120/items/25cb52ba47be0fd418d6#3-3-再帰関数を用いた全探索
// get all the incremental integer (1111, 1222, 1234, ...) not(1000, 1011 and so on.)

// use of [- '0'] to cast string or char into int type
// if you use (int) to cast, it's gonna be in ASCII value (e.g. '1' is 49)

#include <iostream>
#include <string>
using namespace std;

int M, N;

void recur(string crt)
{
    if (crt.size() == N)
    {
        cout << crt << "\n";
        return;
    }

    int last;
    if (crt.size())
        // cast crt[crt.size() - 1] to int by - '0', this is the most important point
        last = crt[crt.size() - 1] - '0';
    else
        last = 1;
    for (int i = last; i <= M; ++i)
    {
        // this is the opposite of - '0', it cast integer i to char (uses ASCII val)
        char nxt = '0' + i;
        recur(crt + nxt); // recursion
    }
}

int main()
{
    cin >> M >> N;

    recur("");
}