#include<bits/stdc++.h>
using namespace std;

int main() {
    pair<int, int> p = {1, 3};
    cout << "First: " << p.first << ", Second: " << p.second << endl;

    pair<int, pair<int, int>> nestedPair = {2, {4, 5}};
    cout << "First: " << nestedPair.first << ", Second: " << nestedPair.second.first << ", Third: " << nestedPair.second.second << endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    for (const auto& a : arr) {
        cout << "First: " << a.first << ", Second: " << a.second << endl;
    }
    return 0;
}