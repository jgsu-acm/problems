#include <iostream>
using namespace std;
#define ll long long
int main()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    for(ll i = 1, x; i <= n; ans += x - m, i++) cin >> x;
    cout << (ans > 0 ? "good job!" : ":(") << endl;
    return 0;
}
