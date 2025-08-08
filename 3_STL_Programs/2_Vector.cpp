#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.emplace_back(5);
    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    vector<int> v2 = {1, 2, 3, 4, 5};
    for (const auto& v : v2) {
        cout << v << " ";
    }
    cout << endl;

    vector<pair<int, int>> v3;
    v3.push_back({1, 2});
    v3.push_back({3, 4});
    v3.push_back({5, 6});
    v3.push_back({7, 8});
    v3.emplace_back(9, 10);
    for(int i = 0; i < v3.size(); i++) {
        cout << "(" << v3[i].first << ", " << v3[i].second << ") ";
    }
    cout << endl;

    vector<int> v4(5, 100);
    for(int i = 0; i < v4.size(); i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    vector<int> v5(5, 20);
    vector<int> v6(v5);
    for(int i = 0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }
    return 0;
}