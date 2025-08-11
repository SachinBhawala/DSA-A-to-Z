#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5}; // Initialize vector

    vector<int>::iterator it1 = v.begin(); // Iterator pointing to the first element
    it1++;
    cout << *it1 << endl;
    vector<int>::iterator it2 = v.end(); // Iterator pointing to the past-the-end element
    it2--;
    cout << *it2 << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) { // Iterator for loop
        cout << *it << " ";
    }
    cout << endl;

    for (auto it = v.begin(); it != v.end(); it++){ // Iterator for loop using auto
        cout << *it << " ";
    }
    cout << endl;

    for (auto it : v) { // For each loop
        cout << it << " ";
    }
    cout << endl;

    v.erase(v.begin() + 2); // Erase the element at index 2
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   // Reinitialize vector

    v.erase(v.begin() + 2, v.begin() + 4); // Erase the elements at index 2 and 3
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> v1(5, 10); // Initialize vector with 5 elements, each of value 100
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;
    v1.insert(v1.begin() + 2, 20); // Insert 200 at index 2
    v1.insert(v1.begin() + 2, 2, 30); // Insert 300 twice at index 2
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> copy(2, 50); // Initialize vector with 2 elements, each of value 50
    v1.insert(v1.begin(), copy.begin(), copy.end()); // Insert elements of copy at index 2
    for (auto it : v1) {
        cout << it << " ";
    }
    cout << endl;

    cout << v1.size() << endl; // Print the size of the vector
    v1.pop_back(); // Remove the last element
    cout << "Popped" << endl;

    v1.swap(v); // Swap contents of v1 with v
    for (auto it : v) {
        cout << it << " ";
    }
    cout << endl;

    v1.clear(); // Clear the contents of v1
    cout << v1.empty() << endl; // Check if v1 is empty
    return 0;
}