#include "polynomials.h"
using namespace std;

double plo(vector<double> &cof, double x) {
    int h_term = cof.size();
    double ans = cof[h_term - 1];
    for(int i = h_term - 2; i >= 0; i--) {
        ans = cof[i] + x * ans;
    }
    return ans;
}
