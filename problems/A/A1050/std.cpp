#include <iostream>
#include <numeric>
using namespace std;
const int maxn = 1e5 + 5;
inline int fa[maxn];
inline int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) { fa[find(x)] = find(y); }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    iota(fa + 1, fa + 1 + n, 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    cout << (find(s) == find(t) ? "YES" : "NO") << endl;
    return 0;
}

