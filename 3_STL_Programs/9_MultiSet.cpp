#include<bits/stdc++.h>
using namespace std;

int main() {
    multiset<int> ms;

    // Inserting elements into the multiset
    ms.insert(10);
    ms.insert(5);
    ms.insert(20);
    ms.insert(20);
    ms.insert(50);
    ms.insert(60);
    ms.insert(60);

    // Displaying the elements in the multiset
    cout << "Elements in the multiset: ";
    for (const auto& elem : ms) {
        cout << elem << " ";
    }
    cout << endl;

    // Checking if an element exists
    int key = 10;
    if (ms.find(key) != ms.end()) {
        cout << key << " found in the multiset." << endl;
    } else {
        cout << key << " not found in the multiset." << endl;
    }

    ms.erase(20);
    cout << "Elements in the multiset after erasing 20: ";
    for (const auto& elem : ms) {
        cout << elem << " ";
    }
    cout << endl;

    cout << ms.count(60) << " instances of 60 found in the multiset." << endl;

    auto it = ms.lower_bound(60);
    if (it != ms.end()) {
        cout << "Lower bound of 60 is: " << *it << endl;
    } else {
        cout << "No lower bound found for 60." << endl;
    }

    auto it2 = ms.upper_bound(60);
    if (it2 != ms.end()) {
        cout << "Upper bound of 60 is: " << *it2 << endl;
    } else {
        cout << "No upper bound found for 60." << endl;
    }

    return 0;
}