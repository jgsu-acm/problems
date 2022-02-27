#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef pair<string,int> psi;
map<string,int> mp;
psi max(psi a, psi b)
{
    if(a.second>b.second) return a;
    else if(a.second<b.second) return b;
    else return a.first<b.first?a:b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]++;
    }
    psi ans("", 0);
    for(auto p : mp)
        ans = max(ans, p);
    cout<<ans.first<<endl;
    return 0;
}