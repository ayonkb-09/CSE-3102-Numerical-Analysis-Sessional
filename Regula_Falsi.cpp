#include <bits/stdc++.h>
using namespace std;
#define MAX_ITER 1000000

double func(double x) {
    return x * x * x - x * x + 2;
}

void regulaFalsi(double a, double b) {
    if (func(a) * func(b) >= 0) {
        cout << "Invalid interval. The function must have opposite signs at a and b." << endl;
        return;
    }

    double c = a;

    for (int i = 0; i < MAX_ITER; i++) {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        if (func(c) == 0) {
            break;
        }
        else if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    cout << "The value of root is : " << c << endl;
}

int main() {
    double a, b;
    cout << "Enter the initial values for a and b: ";
    cin >> a >> b;

    regulaFalsi(a, b);
    return 0;
}

