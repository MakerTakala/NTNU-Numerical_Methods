#include <iostream>
#include <cmath>
using namespace std;

double gradient(double x) {
    return 4 * pow(x, 3) + 9 * pow(x, 2) - 66 * x + 36;
}

double func(double x) {
    return pow(x, 4) + 3 * pow(x, 3) - 33 * pow(x, 2) + 36 * x - 23;
}

int main() {
    double x = 2.0, learning_rate = 0.0001;
    
    while(abs(gradient(x)) > 1e-6) {
        x -= learning_rate * gradient(x);
    }
    cout<<x<<endl;
    cout<<func(x)<<endl;
    return 0;
}