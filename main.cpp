#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int a, b;

    cout << "Enter two integers: ";
    cin >> a >> b;

    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;

    cout << "Divisors of " << a << ": ";
    int x = abs(a);
    if (x == 0) {
        cout << "All integers divide 0";
    } else {
        for (int i = 1; i <= x; i++) {
            if (a % i == 0) cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
