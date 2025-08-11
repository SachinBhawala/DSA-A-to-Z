#include<bits/stdc++.h>
using namespace std;

int main() {
    deque<int> d = {1, 2, 3, 4, 5};

    // Display the elements of the deque
    cout << "Deque elements: ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    // Add an element to the front
    d.push_front(0);
    cout << "After push_front(0): ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    // Add an element to the back
    d.push_back(6);
    cout << "After push_back(6): ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    // Remove an element from the front
    d.pop_front();
    cout << "After pop_front(): ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    // Remove an element from the back
    d.pop_back();
    cout << "After pop_back(): ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}