#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<double,string> pds;
vector<pds> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    return 0;
}
