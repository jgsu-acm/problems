#include <iostream>
using namespace std;
const int maxn = 1e5+5;
typedef pair<int,int> pii;
struct Node { int l,r,cnt,sum; } hjt[maxn*20];
int cnt, root[maxn];
void pushup(int k) { hjt[k].sum = hjt[hjt[k].l].sum+hjt[hjt[k].r].sum; }
void modify(int l,int r,int pre,int &k,int p)
{
    hjt[k=++cnt] = hjt[pre];
    hjt[k].cnt++;
    hjt[k].sum += p;
    if(l==r) return;
    int m = (l+r)>>1;
    if(p<=m) modify(l,m,hjt[pre].l,hjt[k].l,p);
    else modify(m+1,r,hjt[pre].r,hjt[k].r,p);
}
int query(int l,int r,int L,int R,int k)
{
    if(l==r) return l;
    int m = (l+r)>>1;
    int tmp = hjt[hjt[R].l].cnt-hjt[hjt[L].l].cnt;
    if(k<=tmp) return query(l,m,hjt[L].l,hjt[R].l,k);
    else return query(m+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
int query_sum(int l,int r,int L,int R,int k)
{
    if(l==r)
    {
        int s = hjt[R].sum-hjt[L].sum;
        int c = hjt[R].cnt-hjt[L].cnt;
        return s-s/c*(k-1);
    }
    int m = (l+r)>>1;
    int tmp = hjt[hjt[R].l].cnt-hjt[hjt[L].l].cnt;
    if(k<=tmp) return query_sum(l,m,hjt[L].l,hjt[R].l,k)+hjt[hjt[R].r].sum-hjt[hjt[L].r].sum;
    else return query_sum(m+1,r,hjt[L].r,hjt[R].r,k-tmp);
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        modify(1,n,root[i-1],root[i],x);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int l=1, r=y-x+1;
        while(l<r)
        {
            int m = (l+r)>>1;
            int c = query(1,n,root[x-1],root[y],m);
            if(c>y-x+1-m) r = m;
            else l = m+1;
        }
        int s = query_sum(1,n,root[x-1],root[y],l);
        int len = y-x+1-l+1;
        cout<<s-(len-1)*len/2+42<<'\n';
    }
    return 0;
}
