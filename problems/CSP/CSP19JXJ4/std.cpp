#include<cstdio> 
#include<algorithm>
#include<cstring>
#define ll long long
#define N 2003
#define reg register
#define p 1000000007
using namespace std;

inline int power(int a,int t){
    int res = 1;
    while(t){
        if(t&1) res = (ll)res*a%p;
        a = (ll)a*a%p;
        t >>= 1;
    }
    return res;
}

int n,ans,dec,odd;
char a[N];
int fac[N],ifac[N],cnt[26];

int main(){
    scanf("%d",&n);
    scanf("%s",a+1);
    ifac[0] = ifac[1] = fac[0] = fac[1] = 1;
    for(reg int i=2;i<=n;++i) ifac[i] = fac[i] = (ll)fac[i-1]*i%p;
    ifac[n] = power(fac[n],p-2);
    for(reg int i=n-1;i>1;--i) ifac[i] = (ll)ifac[i+1]*(i+1)%p;
    for(reg int i=1;i<=n;++i) ++cnt[a[i]-'a'];
    for(reg int i=0;i<26;++i) odd += cnt[i]&1;
    if(odd>1){
        printf("%d",fac[n]);
        return 0;
    }
    odd = 1;
    for(reg int i=0;i<26;++i)
        if(cnt[i]&1) odd = cnt[i];
    dec = (ll)fac[n>>1]*odd%p;
    for(reg int i=0;i<26;++i) cnt[i] >>= 1;
    for(reg int i=0;i<26;++i) dec = (ll)dec*fac[cnt[i]<<1]%p*ifac[cnt[i]]%p;
    ans = (fac[n]-dec+p)%p;
    printf("%d",ans);
    return 0;
}