#include <iostream>
#include <functional>
#include <deque>
using namespace std;
const int maxn = 1e6+5;
int n,k;
int a[maxn];
deque<int> q;
void solve(function<bool(int,int)> rule)
{
    q.clear();
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&q.front()+k==i) q.pop_front();
        while(!q.empty()&&rule(a[i],a[q.back()]))
            q.pop_back();
        q.push_back(i);
        if(i>=k) cout<<a[q.front()]<<' ';
    }
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve([](int a,int b) { return a<b; });
    cout<<endl;
    solve([](int a,int b) { return a>b; });
    cout<<endl;
    return 0;
}
