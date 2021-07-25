# 42_so_long

so_longは２次元ゲームを実行するプログラム。
プレイヤーを操作し、マップ上に配置されている宝物を収集後、ゴールである魔法陣へ向かうとクリアとなる。
宝物がすべて収集できていない状態だと魔法陣に到達してもクリアとならない。
各種情報はターミナル上に出力される。

## 実行方法
makeにてコンパイル後、実行ファイルso_longの引数にmapファイルを渡して実行する。
```
make
./cub3D && ./map/ok1.ber
```

## 操作
W:上に進む<br>
A:左に進む<br>
S:下に進む<br>
D:右に進む<br>

## マップファイル

```
1111111111111　　　　　　　　　　// 1 :壁
1C100000000C1　　　　　　　　　　// C :宝物
1010111101111　　
10001000000P1     // P :プレイヤー
1010110111101
1010C1E0101C1　　　　　　　　　　// E :ゴール
1111111111111
```
