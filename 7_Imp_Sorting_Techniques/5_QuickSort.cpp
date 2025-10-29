#include<bits/stdc++.h>
using namespace std;

int find(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i] <= pivot && i <= high) {
            i++;
        }
        while(arr[j] > pivot && j >= low) {
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int partition = find(arr, low, high);
        quickSort(arr, low, partition - 1);
        quickSort(arr, partition + 1, high);
    }
}

int main() {
    vector<int> arr = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = arr.size() - 1;
    quickSort(arr, 0, n);
    for(int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}