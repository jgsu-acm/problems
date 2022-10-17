#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <string>
bool eq(char a, char b, char c, char d)
{
    return a==b&&b==c&&c==d;
}
signed main(signed argc, char const *argv[])
{
#if defined(LOCAL) || defined(DEBUG)
    freopen("in.in", "r", stdin);
#ifndef DEBUG
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int t;
    cin>>t;
    while(t--)
    {
        string s[3];
        for(int i=0;i<3;i++) cin>>s[i];
        int x=0, o=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(s[i][j]=='X') x++;
                else if(s[i][j]=='O') o++;
            }
        }
        if(!(x==o||x==o+1)) cout<<"illegal!"<<'\n';
        else
        {
            int xw=0, ow=0;
            for(int i=0;i<3;i++)
            {
                if(eq(s[i][0], s[i][1], s[i][2], 'X')) xw++;
                if(eq(s[i][0], s[i][1], s[i][2], 'O')) ow++;
            }
            for(int i=0;i<3;i++)
            {
                if(eq(s[0][i], s[1][i], s[2][i], 'X')) xw++;
                if(eq(s[0][i], s[1][i], s[2][i], 'O')) ow++;
            }
            if(eq(s[0][0], s[1][1], s[2][2], 'X')) xw++;
            if(eq(s[0][2], s[1][1], s[2][0], 'X')) xw++;
            if(eq(s[0][0], s[1][1], s[2][2], 'O')) ow++;
            if(eq(s[0][2], s[1][1], s[2][0], 'O')) ow++;
            if((xw&&ow)||(xw&&x!=o+1)||(ow&&x!=o)) cout<<"illegal!"<<'\n';
            else
            {
                if(xw) cout<<"Algor win!"<<'\n';
                else if(ow) cout<<"AgOH win!"<<'\n';
                else if(o+x==9) cout<<"draw!"<<'\n';
                else if(o==x) cout<<"Algor now!"<<'\n';
                else if(x>o) cout<<"AgOH now!"<<'\n';
                else throw "???";
            }
        }
    }
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
