#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
//==========================================
#include <string>
#include <vector>
const int MAXN = 1e5 + 5;
vector<int> big = {1,3,5,7,8,10,12};
vector<int> sma = {4,6,9,11};
bool isbig(int x)
{
    for(auto i : big)
        if(i == x) return true;
    return false;
}
int calc(string s)
{
    int ret = 0;
    int month;
    if(s[0]=='0')
    {
        if(s[1]=='0')
        {
            ret++;
            month = -1;
        }
        else month = s[1]-'0';
    }
    else if(s[0]=='1')
    {
        if(s[1]>'2')
        {
            ret++;
            month = -1;
        }
        else month=10+s[1]-'0';
    }
    else 
    {
        ret++;
        if(s[1]<='2') month = -1;
        else month = s[1]-'0';
    }
    if(month==-1)
    {
        int d = (s[3]-'0')*10+s[4]-'0';
        if(d>31||!d) ret++;
    }
    else
    {
        if(s[3]=='0')
        {
            if(s[4]=='0') ret++;
        }
        else if(s[3]=='2')
        {
            if(month==2 && s[4]>'8') ret++;
        }
        else if(s[3]=='3')
        {
            if(month==2)
            {
                ret++;
                if(s[4]>'8') ret++;
            }
            else if(isbig(month))
            {
                if(s[4]>'1') ret++;
            }
            else if(s[4]!='0') ret++;
        }
        else if(s[3]!='1') ret++;
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    clock_t c1 = clock();
#ifdef LOCAL
    system("cls");
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    //======================================
    string s;
    cin>>s;
    cout<<calc(s)<<endl;
    //======================================
end:
    cerr << "Time Used:" << clock() - c1 << "ms" << endl;
    return 0;
}