#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,p1,p2,p3,p4;
        cin>>A>>p1>>p2>>p3>>p4;
        cout<<((int)(A*(1-p1/100.0)) + (int)(A * 0.85 * (1-p2/100.0)) + (int)(A * 0.85 * 0.85 * (1-p3/100.0)) + (int)(A * 0.85 * 0.85 * 0.85 * (1-p4/100.0)))<<endl;
    }
    return 0;
}