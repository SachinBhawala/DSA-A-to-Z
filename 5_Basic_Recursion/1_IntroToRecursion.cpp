#include<bits/stdc++.h>
using namespace std;
int cnt = 0; // Global variable

void f() {
    if(cnt == 4) { // Base condition
        return;
    }
    cout << "Function called " << cnt << " times" << endl;
    cnt++;
    f(); // Function calling itself
}

int main() {
    cout << "Function is called" << endl;
    f(); // Function f is called
    return 0;
}