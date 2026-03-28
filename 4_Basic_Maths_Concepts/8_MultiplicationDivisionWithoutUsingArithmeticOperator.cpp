#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int multiply = n << 1;  // multiply by 2
    int divide = n >> 1;    // divide by 2

    cout << "Multiplication by 2: " << multiply << endl;
    cout << "Division by 2: " << divide << endl;

    return 0;
}