#include <stdio.h>

double p(double x) {
    double ans = 1;
    for(int i = 0; i < 50; i++) {
        ans = ans * x + 1;
    }
    return ans;
}

int main() {
    printf("%.4lf\n", p(1.0001));

    return 0;
}