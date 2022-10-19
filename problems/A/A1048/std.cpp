#include <iostream>
using namespace std;
const int maxn = 1e5+5;
int a[maxn], d[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) d[i] = a[i] - a[i-1];
    while(m--) {
        int l, r, k;
        cin >> l >> r >> k;
        d[l] += k, d[r+1] -= k;
    }
    for(int i = 1, pre = 0; i <= n; i++)
        cout << (pre += d[i]) << ' ';
    cout << endl;
    return 0;
}
