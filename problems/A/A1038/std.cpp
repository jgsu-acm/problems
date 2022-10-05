#include <iostream>
using namespace std;
const int maxn = 85;
long long f[maxn];
long long fib(int n) {
    if(n == 1 || n == 2) return 1;
    if(f[n]) return f[n];
    return f[n] = fib(n-1) + fib(n-2);
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
