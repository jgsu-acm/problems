#include <iostream>
using namespace std;
const int maxn = 1e5+5;
int main()
{
    int n, m, last, sum;
    bool flag = true;
    cin >> n >> m >> last;
    sum = last;
    for(int i = 2, x; i <= n; i++) {
        cin >> x;
        sum += x;
        if(x != last) flag = false;
    }
    if(sum == m || sum > m && flag && m % last == 0) cout << -1;
    else cout << 0;
    return 0;
}
