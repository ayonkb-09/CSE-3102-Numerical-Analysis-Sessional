#include <iostream>
using namespace std;

double func(double x) {
    return x * x * x - x - 2;
}

double bisection(double a, double b, double xr) {
    double c;
    while ((b - a) > xr) {
        c = (a + b) / 2;
        if (func(c) == 0.0)
            break;
        (func(c) * func(a) < 0) ? b = c : a = c;
    }
    return c;
}

int main() {
    double a,b,xr;
    cout<< "Enter the starting interval:";
    cin>> a;
    cout<< "Enter the starting interval:";
    cin>>b;
    cout<< "Enter tolerance:";
    cin>>xr;
    cout << "Root: " << bisection(a, b, xr) << endl;
    return 0;
}
