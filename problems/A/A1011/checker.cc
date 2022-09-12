#include "testlib.h"
#include <cmath>

const int EPS = 2;

int main(int argc, char *argv[]) {
    setName("compare two integers, maximal absolute error = %d", 2);
    registerTestlibCmd(argc, argv);
    int t = inf.readInt();
    while(t--)
    {
        int ja = ans.readInt();
        int pa = ouf.readInt();
        if (abs(ja - pa) > EPS)
            quitf(_wa, "expected %d, found %d", ja, pa);
    }
    quitf(_ok, "accepted");
}
