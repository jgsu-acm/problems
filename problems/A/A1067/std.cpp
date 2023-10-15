#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(long long x)
{
    if(x==1) return false;
    for(long long i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
int main()
{
    long long l,r;
    cin>>l>>r;
    long long cnt = 0;
    for(long long i=sqrt(l);;i++)
    {
        long long t = i*i+1;
        if(t<l) continue;
        if(t>r) break;
        if(is_prime(t)) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
