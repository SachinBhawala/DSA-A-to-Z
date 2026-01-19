// Greedy Approach : TC = O(n log n), SC = O(1)
#include<bits/stdc++.h>
using namespace std;

int greedyAlgo(vector<int>& greed, vector<int>& s) {
    sort(greed.begin(), greed.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < greed.size() && j < s.size()) {
        if(s[j] >= greed[i]) {
            count++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return count;
}

int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};

    cout << "\n" << greedyAlgo(greed, s);

    return 0;
}