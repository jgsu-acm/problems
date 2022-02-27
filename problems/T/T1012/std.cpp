#include <iostream>
using namespace std;
const int maxn = 1e6+5;
string s1, s2;
int pi[maxn];
int main()
{
    cin>>s1>>s2;
    for(int i=1;i<s2.length();i++)
    {
        int j=pi[i-1];
        while(j>0&&s2[i]!=s2[j])
            j=pi[j-1];
        if(s2[i]==s2[j]) j++;
        pi[i]=j;
    }
    
    return 0;
}