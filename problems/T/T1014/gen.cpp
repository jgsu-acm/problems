#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
typedef uniform_int_distribution<> rnd;
typedef uniform_real_distribution<> rndf;
mt19937 egn(time(nullptr));
const int CASES = 10;
#include <cmath>
int isprime(unsigned long long n) {
  /*if((n&1)==0) return n==2;*/
  if(n%3==0) return n==3;
  /*if(n<25) return n>1;*/
  unsigned long long p = 5;
  while (p*p <= n) {
    if (n%p==0) return 0;
    p += 2;
    if (n%p==0) return 0;
    p += 4;
  }
  return 1;
}

unsigned long long rand_prime(int lower, int upper) {
  unsigned long long spread = upper - lower + 1;
  while(1) {
    unsigned long long p = 1 | (rand() % spread + lower);
    if (isprime(p)) return p;
  }
}
int main(int argc, char const* argv[])
{
    for(int t=1;t<=CASES;t++)
    {
        ofstream fout(to_string(t)+".in");
        // ==============================
        int n;
        if(t<=5) n=rnd(1,4e6)(egn);
        else n = 4e6;
        int p;
        do p = rand_prime(rnd(1e7, 20000528)(egn), 20000528);
        while(p<=n);
        fout<<n<<' '<<p;
        // ==============================
        fout.close();
    }
    return 0;
}