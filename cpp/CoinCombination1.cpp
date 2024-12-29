#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int MOD = 1e9 + 7;

    int n;
    int x;
    cin >> n;
    cin >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> dp(x+1, 0);

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - v[j] == 0) {
                dp[i]++;
            } else if (i - v[j] > 0) {
                dp[i] += dp[i - v[j]];
            }
            dp[i] %= MOD;
        }
    }

    cout << dp[x];

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}