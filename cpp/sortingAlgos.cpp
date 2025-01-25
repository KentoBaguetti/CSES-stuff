// #include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// int indexOfMin(vector<int>& arr, int a) {
//     int m = a;
//     for (int i = a + 1; i < arr.size(); i++) {
//         if (arr[i] < arr[m]) {
//             m = i;
//         }
//     }
//     return m;
// }

// vector<int> selectionSort(vector<int>& arr) {
//     for (int i = 0; i < arr.size(); i++) {
//         int minValIndex = i;
//         for (int j = i + 1; j < arr.size(); j++) {
//             if (arr[j] < arr[minValIndex]) {
//                 minValIndex = j;
//             }
//         }
//         int temp = arr[minValIndex];
//         arr[minValIndex] = arr[i];
//         arr[i] = temp;
//     }
//     return arr;
// }

// vector<int> selectionSortWithHelper(vector<int>& arr) {
//     for (int i = 0; i < arr.size(); i++) {
//         int minIndex = indexOfMin(arr, i);
//         int temp = arr[i];
//         arr[i] = arr[minIndex];
//         arr[minIndex] = temp;
//     }
//     return arr;
// }

// vector<int> insertionSort(vector<int>& arr) {
//     for (int i = 1; i < arr.size(); i++) {
//         int j = i - 1;
//         int val = arr[i];
//         while (j >= 0 && arr[j] > val) {
//             arr[j + 1] = arr[j];
//             arr[j] = val;
//             j--;
//         }
//     }
//     return arr;
// }

// vector<int> otherInsertionSort(vector<int>& arr) {
//     for (int i = 1; i < arr.size(); i++) {
//         int val = arr[i];
//         int j = i - 1;
//         while (j >= 0 && arr[j] > val) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = val;
//     }
//     return arr;
// }

vector<int> selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
      int minIndex = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] < arr[minIndex]) {
            minIndex = j;
        }
      }
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;

    }
    return arr;
}

vector<int> insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        int val = arr[i];
        while ( j >= 0 && arr[j] > val) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = val;
    }
    return arr;
}

int fun(int n) {
    int res = 8;
    int j = 2;
    while (j < n) {
        res *= 5;
        j++;
    }
    return res;
}

int main() {

    vector<int> arr(30);
    generate(arr.begin(), arr.end(), []() { return rand() % 100; });
    vector<int> sortedList = insertionSort(arr);

    cout << "[";
    for (int i = 0; i < sortedList.size() - 1; i++) {
        cout << sortedList[i] << ", ";
    }
    cout << sortedList[sortedList.size() - 1] << "]";

    return 0;
}