#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int>& arr) {

    for (int i = 1; i < arr.size(); i++) {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
    return arr;
}

vector<int> insertionSortSwap(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int val = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            arr[j] = val;
            j--;
        }
    }
    return arr;
}

void solve()
{

    // vector<int> arr = {20, 10, 2, 4, 1, 19, 28, 14, 5};
    srand(time(0));
    vector<int> arr(30);
    generate(arr.begin(), arr.end(), []() { return rand() % 100; });
    vector<int> sortedList = insertionSortSwap(arr);

    cout << "Insertion Swap Sort: [";
    for (int i = 0; i < sortedList.size() - 1; i++) {
        cout << sortedList[i] << ", ";
    }
    cout << sortedList[sortedList.size() - 1] << "]";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}