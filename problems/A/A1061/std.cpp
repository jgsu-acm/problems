#include <iostream>
using namespace std;
const int maxn = 1e6+5;
int tong[maxn];
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        tong[x]++;
    }
    for(int i = 1; i <= m; i++)
        cout << tong[i] << ' ';
    return 0;
}
