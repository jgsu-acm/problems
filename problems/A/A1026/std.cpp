#include <iostream>
#include <chrono>
using namespace std;
//==========================================
#include <vector>
#include <algorithm>
typedef pair<double,string> pds;
vector<pds> v;
signed main(signed argc, char const *argv[])
{
#ifdef LOCAL
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    auto c1 = chrono::high_resolution_clock::now();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //======================================
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;
        double s1,s2,s3,s4;
        cin>>name>>s1>>s2>>s3>>s4;
        v.emplace_back(s1+s2+s3+s4, name);
    }
    sort(v.begin(), v.end(), greater<pds>());
    cout<<v.front().second<<" is the FMVP!"<<endl;
    //======================================
#ifdef LOCAL
    auto c2 = chrono::high_resolution_clock::now();
    cerr<<"Time Used:"<<chrono::duration_cast<chrono::milliseconds>(c2-c1).count()<<"ms"<<endl;
#endif
    return 0;
}
