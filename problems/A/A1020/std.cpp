#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
const int maxn = 4e7 + 5;
bitset<maxn> total;
const string mp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        bitset<8> bs(s[i]);
        for(int j=0;j<8;j++) total[i*8+j] = bs[7-j];
    }
    for(int i=0;i<ceil(s.length()*8/5.0);i++)
    {
        bitset<5> bs;
        for(int j=0;j<5;j++) bs[4-j] = total[i*5+j];
        cout<<mp[bs.to_ulong()];
    }
    return 0;
}