
// my 1st try
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool ans = true;
        vector<unordered_set<char>> u_cube(9), u_row(9), u_col(9);
        vector<int> cube_cnt(9, 0), row_cnt(9, 0), col_cnt(9, 0);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char ele = board[i][j];
                if (ele != '.')
                {
                    u_row[i].insert(ele);
                    row_cnt[i]++;
                    u_col[j].insert(ele);
                    col_cnt[j]++;
                    int cube_id = (i / 3) * 3 + (j / 3); // returns 0-8 box id (from left to right, top to bottom
                    u_cube[cube_id].insert(ele);
                    cube_cnt[cube_id]++;
                    bool check = u_cube[cube_id].size() != cube_cnt[cube_id] || u_row[i].size() != row_cnt[i] || u_col[j].size() != col_cnt[j];
                    if (check)
                    {
                        return false;
                    }
                }
            }
        }
        return ans;
    }
};

// my 2nd try
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool ans = true;
        vector<unordered_set<char>> u_cube(9), u_row(9), u_col(9);
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char ele = board[i][j];
                if (ele == '.')
                    continue;

                int cube_id = (i / 3) * 3 + (j / 3);
                bool check = u_cube[cube_id].count(ele) ||
                             u_row[i].count(ele) ||
                             u_col[j].count(ele);
                if (check)
                {
                    return false;
                }
                u_cube[cube_id].insert(ele);
                u_row[i].insert(ele);
                u_col[j].insert(ele);
            }
        }
        return ans;
    }
};

// 2nd gemini
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<char>> u_cube(9), u_row(9), u_col(9);

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                char ele = board[i][j];
                if (ele == '.')
                    continue;

                int cube_id = (i / 3) * 3 + (j / 3);

                // insert() は {イテレータ, bool} のペアを返す
                // すでに値が存在して挿入に失敗した場合、2つ目の要素（.second）が false になる
                if (!u_row[i].insert(ele).second ||
                    !u_col[j].insert(ele).second ||
                    !u_cube[cube_id].insert(ele).second)
                {
                    return false; // 重複があった
                }
            }
        }
        return true; // 変数 ans を廃止し、最後まで行けば true
    }
};