#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
inline int min(int a, int b) { return a<b?a:b; }
int main(int argc, char const *argv[])
{
    int n,m,tmp;
    char opt[5];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        v.insert(upper_bound(v.begin(), v.end(),tmp),tmp);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",opt);
        switch(opt[0])
        {
            case 'a':
            scanf("%d",&tmp);
            v.insert(upper_bound(v.begin(), v.end(),tmp),tmp);
            break;
            case 'm':
            if(v.size()%2)
                printf("%d\n",v[(v.size()-1)/2]);
            else
                printf("%d\n",min(v[v.size()/2-1],v[v.size()/2]));
            break;
        }
    }
    return 0;
}
