#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (m >= n)
    {
        for (int i = 1; i <= n; i++)
            cout << "0 ";
        return 0;
    }
    for (int i = 1, x; i <= m; i++)
        cin >> x;
    for (int i = m + 1, x; i <= n; i++)
    {
        cin >> x;
        cout << x << ' ';
    }
    for (int i = 1; i <= m; i++)
        cout << "0 ";
    return 0;
}
