#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 20;
#include <tuple>
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        tuple<int,int,bool,bool> rule;
        switch(t)
        {
        case 1:  rule = { rnd(1,10)(egn)        , rnd(1,20)(egn)        , true  , false }; break;
        case 2:  rule = { rnd(1,10)(egn)        , 20                    , false , true  }; break;
        case 3:  rule = { 10                    , rnd(1,20)(egn)        , false , false }; break;
        case 4:  rule = { 10                    , 20                    , false , false }; break;
        case 5:  rule = { 300                   , rnd(21,600)(egn)      , true  , false }; break;
        case 6:  rule = { rnd(11,300)(egn)      , 600                   , false , true  }; break;
        case 7:  rule = { 300                   , 600                   , false , false }; break;
        case 8:  rule = { 2e3                   , rnd(601,4e3)(egn)     , true  , false }; break;
        case 9:  rule = { rnd(301,2e3)(egn)     , 4e3                   , false , true  }; break;
        case 10: rule = { 2e3                   , 4e3                   , false , false }; break;
        case 11: rule = { rnd(2e3+1,5e4)(egn)   , rnd(4e3+1,1e5)(egn)   , true  , false }; break;
        case 12: rule = { rnd(2e3+1,5e4)(egn)   , 1e5                   , false , true  }; break;
        case 13: rule = { 5e4                   , rnd(4e3+1,1e5)(egn)   , false , false }; break;
        case 14: rule = { 5e4                   , 1e5                   , false , false }; break;
        case 15: rule = { 5e4                   , 1e5                   , false , false }; break;
        case 16: rule = { rnd(5e4+1,3e5)(egn)   , rnd(1e5+1,3e5)(egn)   , true  , false }; break;
        case 17: rule = { rnd(5e4+1,3e5)(egn)   , 3e5                   , false , true  }; break;
        case 18: rule = { 3e5                   , rnd(1e5+1,3e5)(egn)   , false , false }; break;
        case 19: rule = { 3e5                   , 3e5                   , false , false }; break;
        case 20: rule = { 3e5                   , 3e5                   , false , false }; break;
        }
        auto [n,q,b1,b2] = rule;
        cout<<n<<' '<<q<<endl;
        if(b1)
        {
            int d = rnd(1,n-1)(egn);
            for(int i=0;i<d;i++)
                cout<<1<<' '<<rnd(0,n-1)(egn)<<' '<<rnd(0,n-1)(egn)<<endl;
            for(int i=d;i<n;i++)
                cout<<2<<' '<<rnd(0,n-1)(egn)<<endl;
        }
        else if(b2)
        {
            
        }
        else
        {
            int opt=rnd(1,2)(egn);
            cout<<opt<<' '<<rnd(0,n-1)(egn);
            if(opt==1) cout<<' '<<rnd(0,n-1)(egn)<<endl;
            else cout<<endl;
        }
        // ==============================
        fout.close();
    }
    return 0;
}