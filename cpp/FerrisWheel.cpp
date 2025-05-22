#include <bits/stdc++.h>
using namespace std;

void solve() {

    int n; // num of children
    int m; // max allowed weight

    cin >> n;
    cin >> m;

    vector<int> v(n); // children weights

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int count = 0;

    int l = 0;
    int r = v.size() - 1;

    while (l <= r) {

        if (v[l] + v[r] <= m) {
            count++;
            l++;
            r--;
        } else if (v[l] + v[r] > m) {
            count++;
            r--;
        } else if (l == r) {
            count++;
        }

    }

    cout << count;

}

int32_t main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}