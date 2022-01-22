#include <iostream>
#include <vector>
using namespace std;
int val[6005],mem[6005][2];
bool hf[6005];
std::vector<int> son[6005];
inline int max(int a, int b) { return a > b ? a : b; }
int dp(int a, bool b)
{
    if (son[a].size() == 0)
        return b ? val[a] : 0;
    if(mem[a][b]) return mem[a][b];
    int ret;
    if (b)
    {
        ret = val[a];
        for (auto i : son[a])
            ret += mem[i][0]=dp(i, false);
    }
    else
    {
        ret = 0;
        for (auto i : son[a])
            ret += max(mem[i][1]=dp(i, true), mem[i][0]=dp(i, false));
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    int n, x, y;
    cin>>n;
    for (int i = 1; i <= n; i++)
        cin>>val[i];
    for (int i = 0; i < n - 1; i++)
    {
        cin>>x>>y;
        son[y].emplace_back(x);
        hf[x] = true;
    }
    int root;
    for (int i = 1; i <= n; i++)
        if (!hf[i])
            root = i;
    cout<<max(dp(root, true), dp(root, false))<<endl;
    return 0;
}