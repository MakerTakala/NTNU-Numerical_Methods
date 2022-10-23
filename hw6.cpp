#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<double> > matrix_add(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(a.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.front().size(); j++) {
            ans[i][j] = a[i][j] + b[i][j];
        }
    }
    return ans;
}


vector<vector<double> > matrix_min(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(a.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.front().size(); j++) {
            ans[i][j] = a[i][j] - b[i][j];
        }
    }
    return ans;
}

vector<vector<double> > matrix_mul(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double> > ans(a.size(), vector<double>(a.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            for(int k = 0; k < a.front().size(); k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}


int main() {
    int n = 10;
    vector<vector<double> > U(10, vector<double>(10, 0)) , L(10, vector<double>(10, 0)), D(10, vector<double>(10, 0)), b(10, vector<double>(1, 0));
    for(int i = 0; i < 10; i++) {
        D[i][i] = -1.0 / 4.0;
    }
    for(int i = 0; i < 9; i++) {
        U[i][i + 1] = 2;
    }
    for(int i = 1; i < 10; i++) {
        U[i][i - 1] = 2;
    }
    for(int i = 0; i < 10; i++) {
        b[i][0] = i + 2;
    }
    
    vector<vector<double> > X(10, vector<double>(1, 0));
    for(int t = 0; t < 1000; t++) {
        vector<vector<double> > UL = matrix_add(U, L);
        vector<vector<double> > ULX = matrix_mul(UL, X);
        vector<vector<double> > bULX = matrix_min(b, ULX);
        X = matrix_mul(D, bULX);
        for(int i = 0; i < 10; i++) {
            cout<<X[i][0]<<" ";
        }
        cout<<endl<<endl;
    }

    for(int i = 0; i < 10; i++) {
        cout<<X[i][0]<<" ";
    }
    cout<<endl;
    
    return 0;
}