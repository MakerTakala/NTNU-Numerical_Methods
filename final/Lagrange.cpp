#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4;
    vector<double> x{1.00, 1.05, 1.10, 1.15};
    vector<double> y{0.1924, 0.2414, 0.2933, 0.3492};
    double q = 1.09;
    double ans = 0;;
    for(int i = 0; i < n; i++ ) {
        double up = 1.0, down = 1.0;
        for(int j = 0; j < n; j++) {
            if(j != i) {
                up *= (q - x[j]);
                down *= (x[i] - x[j]);
            }
        }
        ans += y[i] * up / down;
    }
    cout<<ans<<endl;
    return 0;
}