#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5+5, maxm = 2e5+5;
struct E {
    int to, next;
} Edge[maxm << 1];
inline int tot, Head[maxn], t;
inline void AddEdge(int u, int v) {
    Edge[tot] = {v, Head[u]};
    Head[u] = tot++;
}
bool flag, vis[maxn];
void dfs(int u) {
    if(flag) return;
    vis[u] = true;
    for(int i = Head[u]; ~i; i = Edge[i].next) {
        int v = Edge[i].to;
        if(vis[v]) continue;
        if(v == t) {
            flag = true;
            return;
        }
        dfs(v);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(Head, -1, sizeof(Head));
    int n, m, s;
    cin >> n >> m >> s >> t;
    if(s == t) {
        cout << "YES" << endl;
        return 0;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        AddEdge(u, v);
        AddEdge(v, u);
    }
    dfs(s);
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}