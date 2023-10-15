#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &it : v) cin >> it;
    sort(v.begin(), v.end());
    while(m--) {
        int x;
        cin >> x;
        cout << n - (upper_bound(v.begin(), v.end(), x) - v.begin()) + 1 << ' ';
    }
    return 0;
}
