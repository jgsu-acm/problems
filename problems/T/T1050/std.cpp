#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
const int maxn = 2e5+5;
int a[maxn];
vector<int> v;
int getid(int x) { return lower_bound(v.begin(), v.end(),x)-v.begin()+1; }
struct Node {int l,r,val; } hjt[maxn*20];
int cnt, root[maxn];
void modify(int l,int r,int pre,int &k,int p)
{
    k = ++cnt;
    hjt[k] = hjt[pre];
    hjt[k].val++;
    if(l==r) return;
    int m = (l+r)>>1;
    if(p<=m) modify(l,m,hjt[pre].l,hjt[k].l,p);
    else modify(m+1,r,hjt[pre].r,hjt[k].r,p);
}
int query(int l,int r,int L,int R,int k)
{
    if(l==r) return l;
    int m = (l+r)>>1;
    int tmp = hjt[hjt[R].l].val-hjt[hjt[L].l].val;
    if(k<=tmp) return query(l,m,hjt[L].l,hjt[R].l,k);
    else return query(m+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#ifdef DEBUG
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++) modify(1,n,root[i-1],root[i],getid(a[i]));
    for(int i=1;i<=m;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<v[query(1,n,root[l-1],root[r],k)-1]<<'\n';
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}