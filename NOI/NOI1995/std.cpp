#include <iostream>
#include <ctime>
#include <cstdio>
#include <cctype>
namespace FastIO
{
    char buf[1 << 21], buf2[1 << 21], a[20], *p1 = buf, *p2 = buf;
    int p, p3 = -1;
    inline int getc()
    {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++;
    }
    inline int read()
    {
        int ret = 0, f = 0;
        char ch = getc();
        while (!isdigit(ch))
        {
            if (ch == '-')
                f = 1;
            ch = getc();
        }
        while (isdigit(ch))
        {
            ret = ret * 10 + ch - 48;
            ch = getc();
        }
        return f ? -ret : ret;
    }
    inline void flush()
    {
        fwrite(buf2, 1, p3 + 1, stdout), p3 = -1;
    }
    inline void print(int x)
    {
        if (p3 > 1 << 20)
            flush();
        if (x < 0)
            buf2[++p3] = 45, x = -x;
        do
        {
            a[++p] = x % 10 + 48;
        } while (x /= 10);
        do
        {
            buf2[++p3] = a[p];
        } while (--p);
        buf2[++p3] = '\n';
    }
}
#define read() FastIO::read()
#define print(x) FastIO::print(x)
//======================================
#include <climits>
#include <vector>
typedef std::pair<int,int> pii;
int a[201];
pii mem[201][201];
bool b[201][201];
int sum(int l, int r)
{
    int s=0;
    for(int i=l;i<=r;i++)
        s+=a[i];
    return s;
}
pii dfs(int l, int r)
{
    if(l==r) return mem[l][l]=pii(0,0);
    if(b[l][r]) return mem[l][r];
    int min=INT_MAX,max=INT_MIN;
    for(int k=l;k<r;k++)
    {
        min=std::min(min,dfs(l,k).first+dfs(k+1,r).first+sum(l,r));
        max=std::max(max,dfs(l,k).second+dfs(k+1,r).second+sum(l,r));
    }
    b[l][r]=true;
    return mem[l][r]=pii(min,max);
}
int main(int argc, char const *argv[])
{
    clock_t c1 = clock();
    //======================================
    int n = read();
    for(int i=1;i<=n;i++)
        a[i]=a[i+n]=read();
    //答案为max(dp[1][n],dp[2][n+1]...,dp[n][n+n-1])
    int min=INT_MAX,max=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        min=std::min(min,dfs(i,i+n-1).first);
        max=std::max(max,dfs(i,i+n-1).second);
    }
    print(min);print(max);
    //======================================
    FastIO::flush();
    std::cerr << clock() - c1 << std::endl;
    return 0;
}