#include <iostream>
#include <ctime>
using namespace std;
//==========================================
const int maxn = 2025;
typedef long long ll;
//? 做法一：组合数学
//* 即在 2021 个 1 的 2020 个空隙中插入 4 个隔板
//* 答案：\binom{2020}{4}
ll solve1()
{
    ll mul = 1;
    for(int i=2020;i>2016;i--)
        mul *= i/(i-2016);
    return mul;
}
//? 做法二：DP
//* 状态设计：dp[i][j] i 分成 j 个正整数之和的方案数
//* 初始状态：dp[i][1] = 1
//* 转移方程：dp[i][j] = \sum_{k=1}^{i-1} dp[k][j-1]
//* 答案：dp[2021][5]
ll dp[maxn][maxn];
ll solve2()
{
    int n=2021, m=5;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(i,m);j++)
        {
            if(j==1) dp[i][j]=1;
            else 
            {
                ll sum = 0;
                for(int k=1;k<i;k++)
                    sum += dp[k][j-1];
                dp[i][j]=sum;
            }
        }
    }
    return dp[n][m];
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    clock_t c1 = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    cout<<"Method 1:"<<solve1()<<endl;
    cout<<"Method 2:"<<solve2()<<endl;
    //======================================
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    return 0;
}
