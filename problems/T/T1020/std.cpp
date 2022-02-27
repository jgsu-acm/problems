#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,res = 0;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i){
            int ai;
            scanf("%d",&ai);
            res ^= ai;
        }
        if(res) puts("YES");
        else puts("NO");
    }
    return 0;
}