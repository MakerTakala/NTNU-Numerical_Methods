#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n = 3;


int main() {
    double input[3][4] = {{18, 10, -2, -105}, {-10, -16, -2, -88}, {-6, -2, -2, -108}};
    double L[5][5] = {{0}};
    vector<double> ans(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                L[j][i] = 1;
                continue;
            }
            double times = input[j][i] / input[i][i];
            L[j][i] = times;
            for(int k = i; k <= n; k++) {
                input[j][k] -= input[i][k] * times;
            }
        }
    }


    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            input[i][n] -= input[i][j] * ans[j];
        }
        ans[i] = input[i][n] / input[i][i];
    }

    char var[4] = {'x', 'y', 'z', 'w'};
    for(int i = 0; i < n; i++) {
        cout<<var[i]<<" :"<<ans[i]<<endl;
    }
    
    return 0;
}