#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
vector<int> temp;
long long ans;
void merge(vector<int> &v, int l, int mid, int r)
{
    if (l == r)
        return;
    temp.clear();
    int p = l, q = mid + 1;
    while (p <= mid && q <= r)
        if (v[p] <= v[q])
            temp.push_back(v[p++]);
        else
            temp.push_back(v[q++]), ans += mid - p + 1;
    while (p <= mid)
        temp.push_back(v[p++]);
    copy(temp.begin(), temp.end(), v.begin() + l);
}
void merge_sort(vector<int> &v, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) >> 1;
        merge_sort(v, l, mid);
        merge_sort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    merge_sort(v, 0, n - 1);
    cout << ans << endl;
    return 0;
}