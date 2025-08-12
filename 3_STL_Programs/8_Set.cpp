#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    // Inserting elements into the set
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(20);
    s.insert(20);
    s.insert(50);
    s.insert(60);
    s.insert(60);
    s.insert(60);

    // Displaying the elements in the set
    cout << "Elements in the set: ";
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // Checking if an element exists
    int key = 10;
    if (s.find(key) != s.end()) {
        cout << key << " found in the set." << endl;
    } else {
        cout << key << " not found in the set." << endl;
    }

    s.erase(20);
    cout << "Elements in the set after erasing 20: ";
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    cout << s.count(60) << " instances of 60 found in the set." << endl;

    auto it = s.lower_bound(60);
    if (it != s.end()) {
        cout << "Lower bound of 60 is: " << *it << endl;
    } else {
        cout << "No lower bound found for 60." << endl;
    }

    auto it2 = s.upper_bound(60);
    if (it2 != s.end()) {
        cout << "Upper bound of 60 is: " << *it2 << endl;
    } else {
        cout << "No upper bound found for 60." << endl;
    }

    return 0;
}