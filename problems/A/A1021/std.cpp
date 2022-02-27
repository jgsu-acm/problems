#include <iostream>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], pos[maxn];
struct Node { int l,r,val; } sgt[maxn<<2];
inline int ls(int k) { return k<<1; };
inline int rs(int k) { return k<<1|1; }
inline void pushup(int k) { sgt[k].val=max(sgt[ls(k)].val,sgt[rs(k)].val); }
void build(int l,int r,int k=1)
{
    sgt[k].l=l, sgt[k].r=r;
    if(l==r) sgt[k].val=a[l];
    else 
    {
        int m = (l+r)>>1;
        build(l,m,ls(k));
        build(m+1,r,rs(k));
        pushup(k);
    }
}
void modify(int p,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(l==r)
    {
        sgt[k].val=-1;
        return;
    }
    modify(p, p<=(l+r)>>1?ls(k):rs(k));
    pushup(k);
}
int query(int x,int y,int k=1)
{
    int l=sgt[k].l, r=sgt[k].r;
    if(x<=l&&y>=r) return sgt[k].val;
    int m = (l+r)>>1, ret = -1;
    if(x<=m) ret = query(x,y,ls(k));
    if(y>m) ret = max(ret,query(x,y,rs(k)));
    return ret;
}
int main(int argc, char const *argv[])
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    build(1,n);
    int end = n-1;
    while(true)
    {
        int prt = query(1,end);
        if(prt==-1) break;
        cout<<prt<<' ';
        int tmp = pos[prt];
        modify(tmp);
        int nxt = tmp+1;
        while(a[nxt]==-1) nxt++;
        cout<<a[nxt]<<' ';
        a[nxt]=a[tmp]=-1;
        modify(nxt);
        if(nxt>end)
        {
            end=tmp;
            while(a[end]==-1&&end>1) end--;
            if(end>1) { end--; while(a[end]==-1&&end>1) end--; }
        }
    }
    return 0;
}