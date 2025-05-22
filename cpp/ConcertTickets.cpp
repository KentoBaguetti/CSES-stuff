#include <bits/stdc++.h>
using namespace std;

void solve() {

        int n; // num of concert tickets available
        int m; // num of customers
        cin >> n;
        cin >> m;

        multiset<int> tickets;

        for (int i = 0; i < n; i++) {
            int price;
            cin >> price;
            tickets.insert(price);
        }

        for (int i = 0; i < m; i++) {
            int maxPrice;
            cin >> maxPrice;

            auto it = tickets.upper_bound(maxPrice);

            if (it == tickets.begin()) {
                cout << -1 << endl;
            } else {
                it--;
                cout << *it << endl;
                tickets.erase(it);
            }

        }


}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}