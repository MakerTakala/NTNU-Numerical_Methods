#include <iostream>
#include <cmath>
using namespace std;

double func1 (double x) {
    return pow(x, 5.0) + x - 1;
}

double func2 (double x) {
    return log(x) + x * x - 3;
}

double func3 (double x) {
    return sin(x) - 6 * x - 5;
}

int main() {
    double xi, xi1;

    xi = 10, xi1 = 9;
    while(abs(xi - xi1) > 0.00001) {
        xi1 = xi - (func1(xi) * (xi - xi1)) / (func1(xi) - func1(xi1));
        swap(xi1, xi);
    }
    cout<<"Q1: "<<xi<<endl;


    xi = 10, xi1 = 9;
    while(abs(xi - xi1) > 0.00001) {
        xi1 = xi - (func2(xi) * (xi - xi1)) / (func2(xi) - func2(xi1));
        swap(xi1, xi);
    }
    cout<<"Q2: "<<xi<<endl;

    xi = 10, xi1 = 9;
    while(abs(xi - xi1) > 0.00001) {
        xi1 = xi - (func3(xi) * (xi - xi1)) / (func3(xi) - func3(xi1));
        swap(xi1, xi);
    }
    cout<<"Q3: "<<xi<<endl;
    return 0;
}