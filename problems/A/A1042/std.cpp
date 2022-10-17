#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a, bc;
        cin>>a>>bc;
        int p;
        for(p=1;;p++) if(isupper(bc[p])) break;
        string b, c;
        for(int i=0;i<p;i++) b.push_back(bc[i]);
        for(int i=p;i<bc.length();i++) c.push_back(bc[i]);
        cout<<a<<c<<' '<<b<<endl;
    }
    return 0;
}
