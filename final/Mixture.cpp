#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>
using namespace std;


vector<vector<double>> transpose(vector<vector<double>> A) {
    vector<vector<double>> out(A.front().size(), vector(A.size(), 0.0));
    for(int i = 0; i < A.front().size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            out[i][j] = A[j][i];
        }
    }
    return out;
}

vector<vector<double>> mul_matrix(vector<vector<double> > &a, vector<vector<double> > &b) {
    vector<vector<double>> ans(a.size(), vector<double>(b.front().size(), 0));
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            for(int k = 0; k < a.front().size(); k++) {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<double> mul_vector(vector<vector<double> > &a, vector<double> &b) {
    vector<double> ans(a.size(), 0);
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a.front().size(); j++) {
            ans[i] += a[i][j] * b[j];
        }
    }
    return ans;
}

vector<double> guss(vector<vector<double> > a, vector<double> b) {
    int n = a.size();
    vector<double> ans(n, 0);
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double times = a[j][i] / a[i][i];
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

void display(vector<vector<double>> A) {
    for(auto v : A) {
        for(auto x : v) {
            cout<<setw(10)<<to_string(x)<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<double>> node = {{-1, 0, 1}, {1, 0.5, 0.5}, {1, -0.5, 0.5}, {0, 1, 0.5}};
    int n = node.size(), m = node.front().size();
    vector<vector<double>> Dr(n, vector<double>(m, 0));
    vector<double> ans = {0, 0, 0};

    for(int t = 0; t < 1000; t++) {
        vector<double> rx(n, 0);
        for(int i = 0; i < n; i++) {
            Dr[i][0] = (ans[0] - node[i][0]) / sqrt( pow(ans[0] - node[i][0], 2) + pow(ans[1] - node[i][1], 2));
            Dr[i][1] = (ans[1] - node[i][1]) / sqrt( pow(ans[0] - node[i][0], 2) + pow(ans[1] - node[i][1], 2));
            Dr[i][2] = -1;
            rx[i] = (-1) * (sqrt( pow(ans[0] - node[i][0], 2) + pow(ans[1] - node[i][1], 2) ) - (node[i][2] + ans[2]));
        }
        //display(Dr);
        vector<vector<double>> DrT = transpose(Dr);
        vector<vector<double>> DrTDr = mul_matrix(DrT, Dr);
        vector<double> DrTrx = mul_vector(DrT, rx);
        vector<double> v = guss(DrTDr, DrTrx);
        for(int i = 0; i < m; i++) {
            ans[i] += v[i];
        }
    }

    for(int i = 0; i < m; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}