#include <iostream>
using namespace std;
int main()
{
    long long m;
    int n, cnt = 0;
    cin >> m >> n;
    for(int x; cnt < n && m > 0; m -= x, cnt++) cin >> x;
    if(m <= 0) cout << "YES " << cnt << endl;
    else cout << "NO " << m << endl;
    return 0;
}
