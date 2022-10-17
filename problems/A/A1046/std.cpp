#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1e5+5;
struct S { long long x,p; } a[maxn];
int main()
{
    int n;
    cin>>n;
    long long sum = 0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x;
        sum += a[i].x;
        a[i].p = i;
    }
    if(sum%n) cout<<-1<<endl;
    else
    {
        long long ans = 0;
        long long aver = sum/n;
        stack<S> s1, s2;
        for(int i=1;i<=n;i++)
        {
            long long x = a[i].x;
            if(x<aver)
            {
                x = aver-x;
                while(!s2.empty())
                {
                    if(s2.top().x<=x)
                    {
                        x -= s2.top().x;
                        ans += s2.top().x*(i-s2.top().p);
                        s2.pop();
                    }
                    else
                    {
                        s2.top().x -= x;
                        ans += x*(i-s2.top().p);
                        break;
                    }
                }
                if(x) s1.push({x,i});
            }
            else if(x>aver)
            {
                x = x-aver;
                while(!s1.empty())
                {
                    if(s1.top().x<=x)
                    {
                        x -= s1.top().x;
                        ans += s1.top().x*(i-s1.top().p);
                        s1.pop();
                    }
                    else
                    {
                        s1.top().x -= x;
                        ans += x*(i-s1.top().p);
                        break;
                    }
                }
                if(x) s2.push({x,i});
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}