#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n = 4;


int main() {
    double input[4][5] = {{2.0, 1.0, 0.0, 0.0, 1.0}, {0.0, 1.0, 2.0, 0.0, 1.0}, {2.0, 4.0, 5.0, 1.0, 2.0}, {8.0, 5.0, 0.0, 3.0, 0.0}};
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

    cout<<"U:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j<= n; j++) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"L:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j<= n; j++) {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
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