#include<bits/stdc++.h>
using namespace std;
 
int main() {
    stack<int> s;

    // Push elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Stack elements after pushes: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Pop an element from the stack
    s.pop();
    cout << "Stack elements after pop: ";
    temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // Get the top element
    cout << "Top element: " << s.top() << endl;

    // Check if the stack is empty
    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}