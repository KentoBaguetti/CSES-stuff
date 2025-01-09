#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    cin >> n;

    int num;

    set<int> seen;

    for (int i = 0; i < n; i++) {
        cin >> num;
        seen.insert(num);
    }

    cout << seen.size();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}