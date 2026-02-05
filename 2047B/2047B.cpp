#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main () {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        char target = s[0];
        int mx = 0;
        for (auto &p : freq) {
            if (p.second > mx) {
                mx = p.second;
                target = p.first;
            }
        }

        bool changed = false;
        for (int i = 0; i < n; i++) {
            if (s[i] != target) {
                s[i] = target;
                changed = true;
                break;
            }
        }

        if (!changed) {
            s[0] = s[0];
        }

        cout << s << '\n';
    }
    return 0;
}