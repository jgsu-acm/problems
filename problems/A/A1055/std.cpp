#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int main()
{
    int m, n, o, p;
    cin >> m >> n >> o >> p;

    map<string, set<string>> mp;

    for (int i = 0; i < m; i++)
    {
        string lang;
        cin >> lang;
        set<string> keywords;
        for (int j = 0; j < n; j++)
        {
            string keyword;
            cin >> keyword;
            keywords.insert(keyword);
        }
        mp[lang] = keywords;
    }

    for (int i = 0; i < o; i++)
    {
        set<string> ans;
        vector<string> tokens(p);
        for (int j = 0; j < p; j++)
        {
            cin >> tokens[j];
        }

        for (auto lang : mp)
        {
            string name = lang.first;
            auto &keywords = lang.second;
            for (auto token : tokens)
            {
                if (keywords.find(token) != keywords.end())
                {
                    ans.insert(name);
                    break;
                }
            }
        }

        if (ans.empty())
        {
            cout << "Unknown" << endl;
        }
        else
        {
            cout << *ans.rbegin() << endl;
        }
    }

    return 0;
}
