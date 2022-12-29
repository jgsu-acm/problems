#include "testlib.h"
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    setName("compare output");
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(), m = inf.readInt(), ansFile = ans.readInt();
    vector<int> inFile(n), outFile;
    for (int i = 0; i < n; i++)
        inFile[i] = inf.readInt();
    if (~ansFile)
    {
        while (!ouf.seekEof())
        {
            int x = ouf.readInt();
            outFile.push_back(x);
        }
        if (outFile.size() != n)
            quitf(_wa, "illegal length of output");
        int now = 0;
        map<int, bool> mp;
        for(auto i : outFile)
        {
            if(mp[i])
                quitf(_wa, "repeat index %d", i);
            mp[i] = true;
            if(i > n || i < 1) quitf(_wa, "illegal output of %d", i);
            now += inFile[i-1];
            if(now == m) quitf(_wa, "world end!");
        }
        quitf(_ok, "accepted");
    }
    else
    {
        int userOut = ouf.readInt();
        if (~userOut)
            quitf(_wa, "expected -1, found %d", userOut);
        else
            quitf(_ok, "accepted");
    }
}
