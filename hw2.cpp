#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 10;
    while(abs(x - pow(2 * x + 2, 1.0 / 3.0)) > 0.00001) {
        x = pow(2 * x + 2, 1.0 / 3.0);
    }
    cout<<x<<endl;
    return 0;
}