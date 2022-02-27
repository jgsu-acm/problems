#include <iostream>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll& x,ll& y)
{
    if(!b)
    {
        x=1, y=0;
        return a;
    }
    ll ret = exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,p;
        cin>>a>>p;
        ll x,y;
        ll tmp = exgcd(a,p,x,y);
        if(tmp!=1) cout<<"invalid"<<endl;
        else cout<<(x+p)%p<<endl;
    }
    return 0;
}