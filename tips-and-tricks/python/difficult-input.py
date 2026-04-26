"""
Paiza A: https://paiza.jp/works/mondai/a_rank_level_up_problems/a_rank_snake_mapmove_boss

入力される値
H W sy sx N        
S_0     
...     
S_(H-1)     
t_1 d_1     
...     
t_N d_N


・ 1 行目にはマップの行数を表す整数 H , マップの列数を表す整数 W , 現在の y, x 座標を表す sy sx , 移動する回数 N が与えられます。
・ 続く H 行のうち i 行目 (0 ≦ i < H) には、マップの i 行目の文字をまとめた文字列 S_i が与えられ、 S_i の j 文字目は、マップの i 行目の j 列目に書かれている文字を表します。(0 ≦ j < W)
・ 続く N 行のうち i 行目 (1 ≦ i ≦ N) には、i 回目の方向転換をおこなう時刻 t_i と方向転換の向き d_i が与えられます。

5 5 3 1 3
.....
.....
.....
.....
.....
2 R
4 R
6 R
"""


it = iter(open(0).read().split())

h, w, sy, sx, n = map(int, [next(it) for _ in range(5)])

s = [next(it) for _ in range(h)]

turns = {int(next(it)): next(it) for _ in range(n)}
