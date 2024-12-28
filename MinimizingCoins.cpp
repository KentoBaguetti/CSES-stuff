#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    int x;
    cin >> n;
    cin >> x;
    vector<int> coins(n);
    for (int k=0; k<n; k++) {
        cin >> coins[k];
    }
    sort(coins.begin(), coins.end());

    vector<int> dp(x+1, x+1);
    dp[0] = 0;

    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[x] == x+1) {
        cout << -1;
    } else {
        cout << dp[x];
    }
    

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}