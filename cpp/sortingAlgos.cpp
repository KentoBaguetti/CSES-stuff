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

// void Merge(vector<int> &arr, int left, int mid, int right) {
//     int first1 = left;
//     int first2 = mid + 1;
//     int last1 = mid;
//     int last2 = right;
//     vector<int> temp;
//     int index = 0;

//     while ((first1 <= last1) && (first2 <= last2)) {
//         if (arr[first1] <= arr[first2]) {
//             temp.push_back(arr[first1++]);
//         } else {
//             temp.push_back(arr[first2++]);
//         }
//     }

//     while (first1 <= last1)
//         temp.push_back(arr[first1++]);
//     while (first2 <= last2)
//         temp.push_back(arr[first2++]);

//     for (int i = left; i <= right; i++) {
//         arr[i] = temp[index++];
//     }

// }

// vector<int> MS(vector<int> &arr, int left, int right) {
//     if (left < right) {

//         int mid = (left + right) / 2;

//         MS(arr, left, mid);
//         MS(arr, mid + 1, right);
//         Merge(arr, left, mid, right);
//     }
//     return arr;
// }
// 
void Merge(vector<int>& arr, int left, int mid, int right) {

    int first1 = left;
    int first2 = mid + 1;
    int last1 = mid;
    int last2 = right;

    vector<int> temp;
    int tempIndex = 0;

    while ((first1 <= last1) && (first2 <= last2)) {
        if (arr[first1] <= arr[first2])
            temp.push_back(arr[first1++]);
        else
            temp.push_back(arr[first2++]);
    }

    while (first1 <= last1)
        temp.push_back(arr[first1++]);
    while (first2 <= last2)
        temp.push_back(arr[first2++]);

    for (int i = left; i <= right; i++) {
        arr[i] = temp[tempIndex++];
    }

}

vector<int> MS(vector<int>& arr, int left, int right) {
    if (left < right) {

        int mid = (left + right) / 2;

        MS(arr, left, mid);
        MS(arr, mid + 1, right);

        Merge(arr, left, mid, right);

    }
    return arr;
}

vector<int> MergeSort(vector<int> &arr) {
    return MS(arr, 0, arr.size()-1);
}

int main() {

    // vector<int> arr(30);
    // generate(arr.begin(), arr.end(), []() { return rand() % 100; });
    vector<int> arr = {5,2,3,7,1,2,3,4,56,7,100,-1,6,4};
    vector<int> sortedList = MergeSort(arr);

    cout << "[";
    for (int i = 0; i < sortedList.size() - 1; i++) {
        cout << sortedList[i] << ", ";
    }
    cout << sortedList[sortedList.size() - 1] << "]";

    return 0;
}