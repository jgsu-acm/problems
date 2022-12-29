#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> v(n + 1), dp(m + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v.begin() + 1, v.end());
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = (i - 1) % m + 1;
        dp[pos] += v[i];
        ans += dp[pos];
        cout << ans << ' ';
    }
    return 0;
}
