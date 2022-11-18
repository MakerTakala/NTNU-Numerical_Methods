#include <iostream>
#include <vector>
using namespace std;

int main() {
    double tx[4] = {1.00, 1.05, 1.10, 1.15};
    double ty[4] = {0.1924, 0.2414, 0.2933, 0.3492};
    vector<double> x(tx, tx + 4);
    vector<double> y(ty, ty + 4);
    double q = 1.09;
    int n = x.size();
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