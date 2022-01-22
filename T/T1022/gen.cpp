#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <algorithm>
#include <cstring>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;

struct edge{int u,v,w;};
vector<edge>v;
int id[5000][5000],n=9,tp,m=42866/n,a[1000000];

int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        if(t<=5)
        {
            v.clear();
            memset(id, 0, sizeof(id));
            n=9, tp=0, m=42866/n;
            memset(a, 0, sizeof(a));
            
            for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                id[i][j]=++tp,a[tp]=tp;
            int SIZE=29989;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=m;++j){
                    if(i<n){
                        v.push_back(edge{id[i][j],id[i+1][j],1});
                        v.push_back(edge{id[i+1][j],id[i][j],1});
                        if(j<m){
                            if(1)v.push_back(edge{id[i][j],id[i+1][j+1],rnd(1, 1e9)(egn)%SIZE+10});
                            else v.push_back(edge{id[i+1][j+1],id[i][j],rnd(1, 1e9)(egn)%SIZE+10});
                        }
                    }
                    if(j<m){
                        v.push_back(edge{id[i][j],id[i][j+1],rnd(1, 1e9)(egn)%SIZE+10});
                        v.push_back(edge{id[i][j+1],id[i][j],rnd(1, 1e9)(egn)%SIZE+10});
                    }
                }
            random_shuffle(v.begin(),v.end());
            fout<<tp<<' '<<v.size()<<endl;
            for(int i=0;i<v.size();++i)
                fout<<a[v[i].u]<<' '<<a[v[i].v]<<' '<<v[i].w<<endl;
        }
        else 
        {
            int n=99999,m=199996;
            fout<<n<<' '<<m<<endl;
            for(int i=n;i>=2;--i)
            {
                fout<<1<<' '<<i<<' '<<(n-i+1)*2+1<<endl;
                fout<<i<<' '<<i-1<<' '<<1<<endl;
            }
        }
        // ==============================
        fout.close();
    }
    return 0;
}