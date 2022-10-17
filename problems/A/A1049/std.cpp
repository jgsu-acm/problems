#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TimeRange {
    int time_start, time_end;

    TimeRange(string const &s): time_start(0), time_end(0) {
        int hh_start = stoi(s.substr(0, 2));
        int mm_start = stoi(s.substr(3, 2));
        int ss_start = stoi(s.substr(6, 2));

        int hh_end = stoi(s.substr(9, 2));
        int mm_end = stoi(s.substr(12, 2));
        int ss_end = stoi(s.substr(15, 2));

        time_start = hh_start * 3600 + mm_start * 60 + ss_start;
        time_end = hh_end * 3600 + mm_end * 60 + ss_end;
    }
};

const int N = 24 * 60 * 60 + 1;
int diff[N];

int main() {
    int T;
    cin >> T;
    cout << right << setfill('0');
    while (T--) {
        for (int i = 0; i < N; ++i) diff[i] = 0;
        int n;
        cin >> n;
        string s;
        for (int j = 0; j < n; ++j) {
            cin >> s;
            TimeRange tr(s);
            ++diff[tr.time_start];
            --diff[tr.time_end + 1];
        }
        for (int i = 1; i < N; ++i) diff[i] += diff[i - 1];
        int ans = 0;
        for (int i = 0; i < N - 1; ++i) ans += !diff[i];
        int ss = ans % 60;
        ans /= 60;
        int mm = ans % 60;
        ans /= 60;
        int hh = ans;
        cout << setw(2) << hh << ':' << setw(2) << mm << ':' << setw(2) << ss << '\n';
    }
}
