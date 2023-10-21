#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> pre(n + 1);
    long long x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        pre[i] = pre[i - 1] + x;
    }
	if (k == 0) cout << pre[n] << "\n";
	else {
		long long mx = 0;
		for (int i = k; i <= n; i++) {
			mx = max(pre[i] - pre[i - k], mx);
		}
		cout << pre[n] - mx << "\n";
	}
    return 0;
}
