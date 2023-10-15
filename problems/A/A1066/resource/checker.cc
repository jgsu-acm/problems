#include "testlib.h"
#include <stdio.h>
#include <math.h>

const double EPS = 1e-6;

double mx(double x) {
    return (x - 1 > EPS ? x : 1.0); 
}

int main(int argc, char * argv[])
{
    setName("compare two doubles, maximal absolute error = %.8f", EPS);
    registerTestlibCmd(argc, argv);
    
    double ja = ans.readDouble();
    double pa = ouf.readDouble();

    int jb = ans.readInt();
    int pb = ouf.readInt();

    if (fabs(ja - pa) / mx(ja) > EPS)
        quitf(_wa, "square expected %.8f, found %.8f", ja, pa);

    if (jb != pb)
        quitf(_wa, "count expected %d, found %d", jb, pb);
    
    quitf(_ok, "answer is %.8f, %d", ja, jb);
}
