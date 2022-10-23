#include <iostream>
#include <cmath>
using namespace std;

double func(double m) {
    return 0;
}

int main() {
    double l = 3, r = 4;
    while(r - l > 1e-6 && l < r) {
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