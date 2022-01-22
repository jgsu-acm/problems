#include <cstdio>
#include <cmath>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        double p = (a+b+c)/2.0;
        double s = sqrt(p*(p-a)*(p-b)*(p-c));
        printf("%.2f\n", s);
    }
    return 0;
}