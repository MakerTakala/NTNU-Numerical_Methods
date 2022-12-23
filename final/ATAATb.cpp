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
    vector<double> x{4, 7, 11};
    
    vector<double> b{3, 5, 8};
    int scale_size = 1;

    vector<vector<double> > A{{4}, {7}, {11}};
    

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

    for(int i = scale_size - 1; i >= 0; i--) {
        
        cout<<ans[i]<<"x^"<<i<<" ";
    }
    cout<<endl;


    return 0;
}