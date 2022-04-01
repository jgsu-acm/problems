//! Cygwin Linux 下测试通过
//! TDM-GCC MSVC 下测试失败
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    tm d1 = {0,0,0,23,6,21};
    tm d2 = {0,0,0,1,6,120};
    time_t t1 = mktime(&d1);
    time_t t2 = mktime(&d2);
    cout<<(int)(difftime(t2, t1)/60)<<endl;
    return 0;
}