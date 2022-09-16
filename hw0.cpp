#include <iostream>
using namespace std;

double p(double x) {
    double ans = 1;
    for(int i = 0; i < 50; i++) {
        ans = ans * x + 1;
    }
    return ans;
}

int main() {
    cout<<p(1.0001)<<endl;

    return 0;
}