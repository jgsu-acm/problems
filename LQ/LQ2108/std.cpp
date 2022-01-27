#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
#include <vector>
#include <cstring>
const int MAXN = 1e5+5;
vector<int> v;
bool sa[MAXN], sb[MAXN];
int mx, ans;
void add(int p)
{
    if(!sb[p]) ans++;
    sb[p] = true;
    mx = max(mx, p);
}
signed main(signed argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    system("cls");
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    for(auto i : v)
    {
        for(int j=1;j<=mx;j++)
        {
            if(sa[j])
            {
                if(i!=j) add(abs(i-j));
                add(i+j);
            }
        }
        add(i);
        memcpy(sa, sb, sizeof(sa));
    }
    cout<<ans<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}