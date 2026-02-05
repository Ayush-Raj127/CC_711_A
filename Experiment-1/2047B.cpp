#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> f(26, 0);
    for (char c : s) f[c - 'a']++;

    int mx = -1, mn = 11;
    int p1 = -1, p2 = -1;

    for (int i = 0; i < 26; i++) {
        if (f[i] > 0) {
            if (f[i] >= mx) {
                mx = f[i];
                p1 = i;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (f[i] > 0) {
            if (f[i] <= mn && i != p1) {
                mn = f[i];
                p2 = i;
            }
        }
    }

    if (p2 == -1) {
        cout << s << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == (char)(p2 + 'a')) {
            s[i] = (char)(p1 + 'a');
            break;
        }
    }

    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}