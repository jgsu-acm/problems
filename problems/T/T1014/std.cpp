#include <cstdio>
const int maxn = 4e6+5;
int inv[maxn];
int main()
{
    inv[1]=1;
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=2;i<=n;i++)
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    for(int i=1;i<=n;i++)
        printf("%d\n",inv[i]);
    return 0;
}