#include <iostream>
#include <list>
using namespace std;
const int maxn = 1e5+5;
list<int> ls;
list<int>::iterator pos[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ls.push_back(x);
        pos[x] = --ls.end();
    }
    for(int i=n;i>=1;i--)
    {
        auto s = pos[i], f = s++;
        if(f!=ls.end()&&s!=ls.end())
        {
            cout<<i<<' '<<*s<<' ';
            pos[i] = pos[*s] = ls.end();
            ls.erase(f); ls.erase(s);
        }
    }
    return 0;
}