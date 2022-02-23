#include <iostream>
#include <string>
using namespace std;
const int maxn = 2e6 + 5;
int nxt[maxn];
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (size_t i = 1, j = 0; i < s2.size(); i++)
    {
        while (j > 0 && s2[j] != s2[i])
            j = nxt[j - 1];
        if (s2[j] == s2[i])
            nxt[i] = ++j;
    }
    for (size_t i = 0, j = 0; i < s1.size();)
    {
        if (s1[i] == s2[j])
        {
            i++, j++;
            if (j != s2.size())
                continue;
            cout << i - s2.size() + 1 << ' ';
        }
        j = nxt[j - 1];
        if (s1[i] != s2[j])
            i++;
    }
    return 0;
}