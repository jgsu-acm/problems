#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
struct Matrix
{
    int r,c;
    ll ele[2][2];
    Matrix(int r,int c) : r(r),c(c) { memset(ele, 0, sizeof(ele)); }
};
Matrix operator*(Matrix& A, Matrix& B)
{
    Matrix C(A.r, B.c);
    for(int i=0;i<A.r;i++)
        for(int j=0;j<B.c;j++)
            for(int k=0;k<A.c;k++)
                C.ele[i][j]=(C.ele[i][j]+A.ele[i][k]*B.ele[k][j]%mod)%mod;
    return C;
}
Matrix qpow(Matrix A, ll k)
{
    Matrix R = A;
    for(k--;k;k>>=1,A=A*A)
        if(k&1)
            R=R*A;
    return R;
}
ll f(ll n)
{
    if(n<=2) return 1;
    else 
    {
        Matrix A(2,2);
        A.ele[0][1]=A.ele[1][0]=A.ele[1][1]=1;
        Matrix B(2,1);
        B.ele[0][0]=B.ele[1][0]=1;
        Matrix T = qpow(A, n-2);
        Matrix C = T * B;
        return C.ele[1][0];
    }
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        cout<<f(n)<<'\n';
    }
    return 0;
}