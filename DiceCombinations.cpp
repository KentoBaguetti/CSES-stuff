#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;

    vector<int> v(n + 1, 0);
    v[0] = 1;

    int MOD = 1000000007;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<= 6; j++) {
            if (i - j >= 0) {
                v[i] = (v[i] + v[i - j]) % MOD;
            }
        }
    }

    cout << v[n] << endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
}