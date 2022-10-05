#include <iostream>
using namespace std;
void hanoi(char start, char target, char tool, int tot) {
    if(tot == 0) return;
    hanoi(start, tool, target, tot - 1);
    cout << start << "->" << target << '\n';
    hanoi(tool, target, start, tot - 1); 
}

int main() {
    int n;
    cin >> n;
    hanoi('A', 'C', 'B', n);
    return 0;
}