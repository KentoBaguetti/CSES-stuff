#include <bits/stdc++.h>
using namespace std;

int indexOfMin(vector<int>& arr, int a) {
    int m = a;
    for (int i = a + 1; i < arr.size(); i++) {
        if (arr[i] < arr[m]) {
            m = i;
        }
    }
    return m;
}

vector<int> selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int minValIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minValIndex]) {
                minValIndex = j;
            }
        }
        int temp = arr[minValIndex];
        arr[minValIndex] = arr[i];
        arr[i] = temp;
    }
    return arr;
}

int main() {

    

    return 0;
}