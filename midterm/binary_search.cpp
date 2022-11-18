#include <iostream>
#include <cmath>
using namespace std;

double func(double x) {
    return x * x * x + 4 * x * x - 10;
}

int main() {
    double l = 1, r = 2;
    while(r - l > 1e-7 && l < r) {
        double mid =  l + (r - l) / 2.0;
        double cur = func(mid);
        if(cur > 0) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout<<l<<endl;
    return 0;
}