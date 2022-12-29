#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    auto check = [&](int x)
    {
        int temp = 0;
        for (int i = 0; i < n; i++)
            if (x - 1 - a[i].first <= temp && temp <= a[i].second)
                temp++;
        return temp >= x;
    };
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r >> 1) + 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}
