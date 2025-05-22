#include <bits/stdc++.h>
using namespace std;

void solve()
{

    int n;
    int m;
    int k;

    cin >> n; // num of applicants
    cin >> m; // num of apartments
    cin >> k; // maximum allowed difference

    vector<int> desiredSizes(n); // desired apartment sizes of each applicant
    for (int i = 0; i < n; i++) {
        cin >> desiredSizes[i];    
    }

    vector<int> apartments(m); // the size of each apartment
    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    int count = 0;

    sort(desiredSizes.begin(), desiredSizes.end());
    sort(apartments.begin(), apartments.end());

    int i = 0;
    int j = 0;

    while (i < desiredSizes.size() && j < apartments.size()) {

        if ((desiredSizes[i] <= apartments[j] + k) && (desiredSizes[i] >= apartments[j] - k)) {
            count++;
            i++;
            j++;
        } else if (desiredSizes[i] > apartments[j] + k) {

            j++;

        } else {

            i++;

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