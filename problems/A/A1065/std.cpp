#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int now = 0;
        string s = "hello", t;
        cin >> t;
        for(char ch : t)
            if(s[now] == ch) now++;
        cout << (now == 5 ? "YES\n" : "NO\n");
    }
    return 0;
}
