#include <cstdio>
#include <cmath>
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int delta = b*b-4*a*c;
    if(delta < 0) printf(":(\n");
    else printf("%.6f %.6f\n",(-b+sqrt(delta))/(2*a), (-b-sqrt(delta))/(2*a));
    return 0;
}
