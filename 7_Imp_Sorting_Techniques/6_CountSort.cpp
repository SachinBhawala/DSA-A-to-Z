#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {9, 4, 2, 6, 5, 3, 5, 3, 1};

    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    vector<int> countArr(maxVal + 1, 0);

    for (int val : arr) {
        countArr[val]++;
    }

    for (int i = 1; i < countArr.size(); i++) {
        countArr[i] += countArr[i - 1];
    }

    vector<int> result(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        countArr[arr[i]]--;
        result[countArr[arr[i]]] = arr[i];
    }

    arr = result;

    for (int val : arr) {
        cout << val << " ";
    }

    return 0;
}
