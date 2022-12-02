#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> guss(vector<vector<double> > a, vector<double> b) {
    int n = a.size();
    vector<double> ans(n, 0);
    vector<vector<double> > L(n, vector<double>(n, 0));
    for(int i = 0 ; i < n; i++) {
        L[i][i] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double times = a[j][i] / a[i][i];
            L[j][i] = times;
            for(int k = i; k < n; k++) {
                a[j][k] -= a[i][k] * times;
            }
            b[j] -= b[i] * times;
        }
        
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            b[i] -= a[i][j] * ans[j];
        }
        ans[i] = b[i] / a[i][i];
    }
    return ans;
}

int main() {
    vector<double> x;
    for(double i = 0; i <= 3; i += 0.25) {
        x.push_back(i);
    }
    double y[13] = {6.3806, 7.1338, 9.1662, 11.5545, 15.6414, 22.7371, 32.0696, 47.0756, 73.1596, 111.4684, 175.9895, 278.5550, 446.4441};
    vector<double> b;
    for(int i = 0; i < 13; i++) {
        b.push_back(y[i]);
    } 

    vector<vector<double> > A(13, vector<double> (4));
    for(int i = 0; i < 13; i++) {
        for(int j = 0; j < 4; j++) {
            A[i][j] = pow(x[i], j);
        }
    }

    vector<vector<double> > ATA(4, vector<double> (4));
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            double sum = 0;
            for(int k = 0; k < 13; k++) {
                sum += A[k][i] * A[k][j];
            }
            ATA[i][j] = sum;
        }
    }

    vector<double> ATb(4);
    for(int i = 0; i < 4; i++) {
        double sum = 0;
        for(int j = 0; j < 13; j++) {
            sum += A[j][i] * b[j];
        }
        ATb[i] = sum;
    }

    vector<double> ans = guss(ATA, ATb);

    for(int i = 0; i < 4; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}