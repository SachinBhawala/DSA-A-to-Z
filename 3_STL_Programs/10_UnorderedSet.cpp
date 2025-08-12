#include<bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> us;

    // Inserting elements into the unordered set
    us.insert(10);
    us.insert(5);
    us.insert(20);
    us.insert(20);
    us.insert(50);
    us.insert(60);
    us.insert(60);

    // Displaying the elements in the unordered set
    cout << "Elements in the unordered set: ";
    for (const auto& elem : us) {
        cout << elem << " ";
    }
    cout << endl;

    // Checking if an element exists
    int key = 10;
    if (us.find(key) != us.end()) {
        cout << key << " found in the unordered set." << endl;
    } else {
        cout << key << " not found in the unordered set." << endl;
    }

    us.erase(20);
    cout << "Elements in the unordered set after erasing 20: ";
    for (const auto& elem : us) {
        cout << elem << " ";
    }
    cout << endl;

    cout << us.count(60) << " instances of 60 found in the unordered set." << endl;

    return 0;
}
