#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
map<int, int> mp;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(mp.find(x) != mp.end()) pq.emplace(i-mp[x], i+mp[x]);
        mp[x] = i;
    }
    cout << (pq.empty() ? -1 : pq.top().second) << endl;
    return 0;
}