#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct BSTHNode{
    BSTHNode* left;
    BSTHNode* right;
    int data; 
};

struct BST{
    BSTHNode* root;
};


BSTHNode* MakeRightSpine (BSTHNode* nd) {
    return nullptr;
}

BSTHNode* RotateLeft ()



BSTHNode* Balance (BSTHNode* nd){
  


}

void Merge(vector<int>& v, int left, int mid, int right) {

    int first1 = left;
    int first2 = mid + 1;
    int last1 = mid;
    int last2 = right;

    vector<int> temp;
    int tempIndex = 0;

    while ((first1 <= last1) && (first2 <= last2)) {

        if (v[first1] < v[first2]) temp.push_back(v[first1++]);
        else temp.push_back(v[first2++]);

    }

    while (first1 <= last1) temp.push_back(v[first1++]);
    while (first2 <= last2) temp.push_back(v[first2++]);

    for (int i = left; i <= right; i++)
        v[i] = temp[tempIndex++];

}

void MergeSort(vector<int>& v, int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        MergeSort(v, left, mid);
        MergeSort(v, mid + 1, right);

        Merge(v, left, mid, right);

    }

}

void Sort(vector<int>& v) {

    MergeSort(v, 0, v.size() - 1);

}

void PrintVector(vector<int>& v) {

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ", ";
    cout << endl;

}

void Partition(vector<int>& v);

void QuickSort(vector<int>& v);



int main () {

    vector<int> x = {1, 4, 5, 2, 12, 8, 10, 99, 75};
    Sort(x);

    PrintVector(x);



    return 0;

}

