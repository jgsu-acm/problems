#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int Maxn = 3e5 + 5;
const LL Mod = 1e9 + 7;

int n, q, opt, x, y;
int Ans;
LL a[Maxn] = {1};
int w[Maxn] = {1}; 

/*快速幂*/ 
inline LL qpow(LL b, LL p)
{
	if(p == 0) return 1;
	LL x = 1;
	for(; p;b *= b, b %= Mod,p >>= 1) if(p & 1) x *= b, x %= Mod;
	return x;
}

/*并查集*/
int fa[Maxn];

int find(int t)
{
	return fa[t] == t ? t : fa[t] = find(fa[t]);
}

/*数学*/
LL fac[Maxn] = {1};
LL invf[Maxn];

LL C(int N, int M)
{
	return 1ll * fac[N] % Mod * invf[M] % Mod * invf[N - M] % Mod;
}

/*预处理*/ 
void Setup()
{
	for(register int i = 1; i <= n; ++i)
	{
		fa[i] = i;
		w[i] = a[i] = 1;
		fac[i] = fac[i - 1] * i;
		fac[i] %= Mod;
	}
	invf[n] = qpow(fac[n], Mod - 2);
	for(register int i = n - 1; i >= 0; --i)
	{
		invf[i] = invf[i + 1] * (i + 1);
		invf[i] %= Mod;
	}
}

/*链接 处理答案*/
void line(int u, int v)
{
	w[v] += w[u];
	a[v] = a[v] * a[u] % Mod * C(w[v] - 1, w[u]) % Mod;
	fa[u] = v;
}

/*输出答案 更新强制在线值*/
void print(int t)
{
	Ans = (int)a[t];
	printf("%d\n", Ans);
} 

/*快速读入*/ 
inline int read()
{
	int f = 1, w = 0; char ch = getchar();
	for(; (ch < '0') || (ch > '9'); ch = getchar()) if(ch == '-') f = -1;
	for(; (ch >= '0') && (ch <= '9'); ch = getchar()) w = (w << 3) + (w << 1) + (int)(ch ^ '0');
	return f * w;
}

int main()
{
	n = read(); q = read();
	Setup();
	while(q--)
	{
		opt = read();
		if(opt == 1)
		{
			x = (read() + Ans) % n;
			y = (read() + Ans) % n;
			x = find(x); y = find(y);
			line(x, y); 
		}
		else
		{
			x = (read() + Ans) % n;
			x = find(x);
			print(x);
		}
	}
	return 0;
}