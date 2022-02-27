#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
#include <set>
#include <tuple>
#include <vector>
#include <algorithm>
const int maxn = 1e5 + 5;
struct Node
{
    int ch[2],val;
}sgt[66*maxn];
int cnt;
inline int& ls(int k) { return sgt[k].ch[0]; }
inline int& rs(int k) { return sgt[k].ch[1]; }
int build(int l,int r,int p)
{
    int n = ++cnt;
    sgt[n].val=1;
    if(l!=r)
    {
        int m = (l+r)>>1;
        if(p<=m) ls(n) = build(l, m, p);
        else rs(n) = build(m+1, r, p);
    }
    return n;
}
void merge(int &x, int y)
{
    if(!x||!y) x|=y;
    else
    {
        sgt[x].val += sgt[y].val;
        merge(ls(x), ls(y));
        merge(rs(x), rs(y));
    }
}
int split(int k, int kth, bool rev)
{
    if(sgt[k].val == kth) return 0;
    int n = ++cnt;
    sgt[n].val = sgt[k].val-kth;
    sgt[k].val = kth;

    int val = sgt[sgt[k].ch[rev]].val;
    if(val>=kth)
    {
        sgt[n].ch[rev] = split(sgt[k].ch[rev], kth, rev);
        sgt[n].ch[!rev] = sgt[k].ch[!rev];
        sgt[k].ch[!rev] = 0;
    }
    else sgt[n].ch[!rev] = split(sgt[k].ch[!rev], kth - val, rev);
    return n;
}
typedef tuple<int, bool, int> tp3;
struct Cmp
{
    bool operator() (const tp3 t1, const tp3 t2) const
    {
        return get<0>(t1) < get<0>(t2);
    }
};
set<tp3, Cmp> rt;
void data(int l, int r, int k, vector<int>& v)
{
    if(!k) return;
    if(l==r) v.push_back(l);
    int m = (l+r)>>1;
    data(l, m, ls(k), v);
    data(m+1, r, rs(k), v);
}
vector<int> print(int l, int r)
{
    vector<int> ret;
    for(auto t : rt)
    {
        vector<int> v;
        data(l, r, get<2>(t), v);
        if(get<1>(t)) ret.insert(ret.end(), v.rbegin(), v.rend());
        else ret.insert(ret.end(), v.begin(), v.end());
    }
    return ret;
}
auto split(int p)
{
    auto it = rt.lower_bound(tp3(p, false, 0));
    if(get<0>(*it)==p) return it;
    it--;
    int l,n; bool rev;
    tie(l, rev, n) = *it;
    return rt.insert(tp3(p, rev, split(n, p-l, rev))).first;
}
void solve(int l, int r, bool rev)
{
    if(l>r) return;
    auto itl = split(l);
    auto itr = split(r+1);
    int n = 0;
    for(auto it = itl; it!=itr; ++it)
        merge(n, get<2>(*it));
    rt.erase(itl, itr);
    rt.insert(tp3(l, rev, n));
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        rt.insert(tp3(i, false, build(1, n, i)));
    rt.insert(tp3(n+1, false, 0));
    while(m--)
    {
        int opt,x;
        cin>>opt>>x;
        if(opt) solve(x, n, false);
        else solve(1, x, true);
    }
    for(auto i : print(1, n)) cout<<i<<' ';
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}