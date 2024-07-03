#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    if(n==1) cout<<0<<endl;
    else if(n==2) cout<<1<<endl;
    else if(n==3) cout<<3<<endl;
    else
    {
        long long tmp = pow(2, n-3);
        cout<<3*(n-1)*tmp+1-tmp*4<<' '<<tmp<<endl;
    }
    return 0;
}
