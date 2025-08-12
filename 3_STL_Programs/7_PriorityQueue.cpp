#include<bits/stdc++.h>
using namespace std;

int main() {
    // Max-Heap
    priority_queue<int> pq;

    // Inserting elements into the priority queue
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Displaying the top element
    cout << "Top element: " << pq.top() << endl;

    // Removing the top element
    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl;

    // Min-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(20);

    cout << "Top element in Min-Heap: " << minHeap.top() << endl;

    return 0;
}