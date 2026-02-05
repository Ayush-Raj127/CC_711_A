#include <iostream>
#include <vector>
using namespace std;

int main () {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 2 || n == 3) {
            cout << -1 << endl;
            continue;
        }

        vector<int> odd;
        vector<int> even;

        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0)
                even.push_back(i);
            else
                odd.push_back(i);
        }

        for (int x : odd)
            cout << x << " ";

        for (int x : even)
            cout << x << " ";

        cout << 1 << endl;
    }

    return 0;
}