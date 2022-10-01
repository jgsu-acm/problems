#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << fixed << setprecision(6) << sqrt(b*b+a*a) << endl;
    return 0;
}
