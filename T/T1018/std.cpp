#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<(n%(m+1)?"YES":"NO")<<endl;
    }
    return 0;
}