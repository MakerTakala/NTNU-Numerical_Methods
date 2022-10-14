#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n = 4;


int main() {
    double input[4][4] = {{0.0, 0.0, -1.0, 1.0}, {1.0, 1.0, -1.0, 2.0}, {-1.0, -1.0, 2.0, 0.0}, {1.0, 2.0, 0.0, 2.0}};
    double P[4][4] = {{1.0, 0.0, 0.0, 0.0}, {0.0, 1.0, 0.0, 0.0}, {0.0, 0.0, 1.0, 0.0}, {0.0, 0.0, 0.0, 1.0}};
    double L[4][4] = {{0}};
    vector<double> ans(n, 0);

    for(int i = 0; i < n; i++) {
        double MAX = __DBL_MIN__;
        int index = i;
        for(int j = i; j < n; j++) {
            if(MAX < abs(input[j][i])) {
                MAX = abs(input[j][i]);
                index = j;
            }
        }

        for(int j = 0; j < n; j++) {
            swap(input[i][j], input[index][j]);
             swap(P[i][j], P[index][j]);
        }
    }

    cout<<"input:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"P:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                L[j][i] = 1;
                continue;
            }
            double times = input[j][i] / input[i][i];
            L[j][i] = times;
            for(int k = i; k < n; k++) {
                input[j][k] -= input[i][k] * times;
            }
        }
    }

    cout<<"U:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< n; j++) {
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"L:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j< n; j++) {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}