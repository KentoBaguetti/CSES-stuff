#include <bits/stdc++.h>
using namespace std;

void mystery(vector<int> & A) {
    int n = A.size() - 1;
    for (int i = 1; i <= n; ++i) {
        int j = i;                    // Initialize j.
        while (j > 1) {
            if (A[j/2] <= A[j])       // Integer division.
                break;                // End the loop early.
            int temp = A[j];          // LINE A.
            A[j] = A[j/2];            // LINE B.
            A[j/2] = temp;            // LINE C.
            j = j/2;
        }
    }
}