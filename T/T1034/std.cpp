#include <iostream>
#include <ctime>
using namespace std;
clock_t c1;
inline void exit()
{
#ifdef LOCAL
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
#endif
    exit(0);
}
//==========================================
#include <stack>
const int maxn = 3e6+5;
int a[maxn];
stack<int> st, ans;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    c1 = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i])
            st.pop();
        ans.push(st.empty()?0:st.top());
        st.push(i);
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<' ';
        ans.pop();
    }
    //======================================
    exit();
}
