#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double l = 3, r = 4;
    while(r - l > 1e-6 && l < r) {
        double mid =  l + (r - l) / 2.0;
        double cur = mid - pow(mid, 1.0 / 3.0) - 2;
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