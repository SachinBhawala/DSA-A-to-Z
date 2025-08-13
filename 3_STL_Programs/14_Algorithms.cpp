#include<bits/stdc++.h>
using namespace std;

bool comp(int a, int b) { // Custom comparator for sorting
    return a > b;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(v.begin(), v.end()); // Sort in ascending order
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    sort(v.begin(), v.end(), greater<int>()); // Sort in descending order
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Max element: " << *max_element(v.begin(), v.end()) << endl; // Find max element
    cout << "Min element: " << *min_element(v.begin(), v.end()) << endl; // Find min element

    sort(v.begin(), v.end(), comp); // Sort using custom comparator
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}