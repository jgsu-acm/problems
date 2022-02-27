#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
const int MAXN = 3e5 + 5;
vector<int> a,b;
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    system("cls");
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) { int tmp; cin>>tmp; a.push_back(tmp); }
    for(int i=1;i<=m;i++) { int tmp; cin>>tmp; b.push_back(tmp); }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    unsigned long long ans = (long long)a[0] * (m-1) + (long long)b[0] * (n-1);
    int row=1,col=1;
    auto it_a = a.begin()+1, it_b = b.begin()+1;
    while(it_a!=a.end() && it_b!=b.end())
    {
        if(*it_a<=*it_b)
        {
            ans += (long long)(m-row) * (*it_a++);
            col++;
        }
        else 
        {
            ans += (long long)(n-col) * (*it_b++);
            row++;
        }
    }
    cout<<ans<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}