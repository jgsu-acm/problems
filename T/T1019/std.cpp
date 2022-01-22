#include<stdio.h>
#include<math.h>
int main()
{
    int _t;
    scanf("%d", &_t);
    while(_t--)
    {
        int n,m,t;
        scanf("%d%d",&n,&m);
        if(n > m) t = n,n = m,m = t; // 保证n<m
        double phi = (1.000 + sqrt(5.000)) / 2.000; // 计算phi
        if(floor(phi * (m - n)) == n) puts("NO"); // n=a[m-n]=floor(phi*(m-n))
        else puts("YES");
    }
    return 0;
}