#include <bits/stdc++.h>
using namespace std;

void solve() 
{

    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    int MOD = 1e9 + 7;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=6; j++) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
    }

    cout << dp[n];

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