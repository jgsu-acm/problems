#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    s = '0' + s;
    bool flag = true;
    int head = s.length() - 1;
    while(flag){
        flag = false;
        for(int i = s.length() - 1; i > 0; i--){
            if(s[i] >= '5'){
                flag = true;
                s[i - 1]++;
                s[i] = '0';
                head = i;
            }
            if(flag) continue;
        }
    }
    for(int i = 0; i < s.length(); i++){
        if(i == 0 && s[i] == '0') continue;
        if(i <= head) cout << s[i];
        else cout << '0';
    }
    cout << '\n';
    return 0;
}
