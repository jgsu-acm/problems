#include <iostream>
#include <algorithm>
using namespace std;
int a[200007], n, k, l;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, [](int x,int y) { return x>y; });
    k = 2;
    while (k <= n && a[k] == a[k - 1]) k++;
    l = k + 1;
    while (l <= n && a[l] == a[l - 1]) l++;
    if (k > n)
        cout << -1;
    else if (l > n)
        cout << a[1] % a[k];
    else
        cout << max(a[l], a[1] % a[k]);
    return 0;
}