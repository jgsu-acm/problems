#include <iostream>
#include <ctime>
using namespace std;
const int maxn = 1e5+5;
int main()
{
    time_t t;
    cin>>t;
    t /= 1000;
    auto time = *gmtime(&t);
    char ch[100];
    strftime(ch, sizeof(ch), "%H:%M:%S", &time);
    cout<<ch<<endl;
    return 0;
}