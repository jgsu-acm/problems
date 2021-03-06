# 题目描述

给定一个 $n \times m$ 的网格图，行从 $1 \sim n$ 编号，列从 $1 \sim m$ 编号，每个点可用它所在的行编号 $r$ 与所在的列编号 $c$ 表示为 $(r, c)$。

点 $(i,j)$ 与 $(i,j+1)$ 间连有一条权值为 $a_i$ 的边，其中 $1 \leq i \leq n, 1 \leq j<m$。

点 $(i, j)$ 与 $(i+1,j)$ 间连有一条权值为 $b_j$ 的边，其中 $1 \leq i< n, 1 \leq j \leq m$。

请你求出这个网格图的最小生成树。

# 输入格式

第一行两个正整数 $n, m$ 表示行数与列数。

第二行 $n$ 个正整数表示 $a_i$。

第三行 $m$ 个正整数表示 $b_j$。

# 输出格式

仅一行一个整数表示答案。

# 输入输出样例

```input1
3 3
2 4 3
1 3 2
```

```output1
16
```

# 说明/提示

【样例解释 #1】

最小生成树中的边包括：第一行上的所有边，第一列、第二列、第三列上的所有边。

【数据规模】

对于 $20 \%$ 的数据，$n, m \leq 3$，$a_i, b_j \leq 10$；

对于 $40 \%$ 的数据，$n, m \leq 20$，$a_i, b_j \leq 100$；

对于 $64 \%$ 的数据，$n, m \leq 300$，$a_i, b_j \leq 1000$；

对于 $100 \%$ 的数据：$3 \leq n, m \leq 3 \times {10}^5$，$1 \leq a_i, b_j \leq {10}^5$。
