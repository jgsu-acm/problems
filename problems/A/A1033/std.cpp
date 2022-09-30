#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
int main()
{
    int n;
    cin >> n; 
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    if(n&1) cout << a[n/2+1] << endl;
    else cout << (a[n/2]+a[n/2+1])/2.0 << endl;
    return 0;
}
