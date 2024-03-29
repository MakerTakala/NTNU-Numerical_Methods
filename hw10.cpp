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
    vector<double> b{6.3806, 7.1338, 9.1662, 11.5545, 15.6414, 22.7371, 32.0696, 47.0756, 73.1596, 111.4684, 175.9895, 278.5550, 446.4441};
    int scale_size = 4;

    vector<vector<double> > A(b.size(), vector<double> (scale_size));
    for(int i = 0; i < b.size(); i++) {
        for(int j = 0; j < scale_size; j++) {
            A[i][j] = pow(x[i], j);
        }
    }

    vector<vector<double> > ATA(scale_size, vector<double> (scale_size));
    for(int i = 0; i < scale_size; i++) {
        for(int j = 0; j < scale_size; j++) {
            double sum = 0;
            for(int k = 0; k < b.size(); k++) {
                sum += A[k][i] * A[k][j];
            }
            ATA[i][j] = sum;
        }
    }

    vector<double> ATb(scale_size);
    for(int i = 0; i < scale_size; i++) {
        double sum = 0;
        for(int j = 0; j < b.size(); j++) {
            sum += A[j][i] * b[j];
        }
        ATb[i] = sum;
    }

    vector<double> ans = guss(ATA, ATb);

    for(int i = 0; i < scale_size; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;


    return 0;
}