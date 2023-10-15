#include <iostream>
#include <ctime>
#include <math.h>
#include <iomanip>
using namespace std;
const double eps = 1e-6;
double distanceSquare(double x1, double y1, double x2, double y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
double area(double rSquare) {
    return acos(-1) * rSquare;
}
//=====================================
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //=====================================
    int x1, y1, x2, y2, x3, y3, n, tot = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> n;
    double a1 = (y1 + y2) / 2.0, k1 = (x2 - x1) * 1.0 / (y1 - y2), b1 = (x1 + x2) / 2.0;
    double a2 = (y1 + y3) / 2.0, k2 = (x3 - x1) * 1.0 / (y1 - y3), b2 = (x1 + x3) / 2.0;
    double x = (k1 * b1 - k2 * b2 + a2 - a1) / (k1 - k2), y = k1 * (x - b1) + a1;
    double rSquare = distanceSquare(x1, y1, x, y);
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        tot += (distanceSquare(a, b, x, y) > rSquare ? 0 : 1);
    }
    cout << fixed << setprecision(8) << area(rSquare) << endl;
    cout << tot << endl;
    return 0;
}
