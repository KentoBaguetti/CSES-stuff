#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int MOD = 1e9 + 7;

    int n;
    int x;
    cin >> n;
    cin >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = 1; i <= x; i++) {
            if (i - coin >= 0) {
                dp[i] += dp[i - coin];
                dp[i] %= MOD;
            }
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