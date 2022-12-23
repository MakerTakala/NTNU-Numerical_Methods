#include <iostream>
#include <cmath>
using namespace std;

double gradient(double x) {
    return 4 * pow(x, 3) - 6 * pow(x, 2);
}

int main() {
    double x = 5, learning_rate = 0.01;
    while(gradient(x) > 1e-6) {
        x -= learning_rate * gradient(x);
    }
    cout<<x<<endl;
    return 0;
}