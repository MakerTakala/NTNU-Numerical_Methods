#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


vector<double> guss(vector<vector<double> > a, vector<double> b) {
    int n = a.size();
    vector<double> ans(n, 0);
    vector<vector<double> > L(n, vector<double>(n, 0));
    for(int i = 0 ; i < n; i++) {
        L[i][i] = 1;
    }
    
    for(int i = 0; i < n; i++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<b[i]<<endl;
        }
        for(int j = i + 1; j < n; j++) {
            double times = a[j][i] / a[i][i];
            L[j][i] = times;
            for(int k = i; k < n; k++) {
                a[j][k] -= a[i][k] * times;
            }
            b[j] -= b[i] * times;
        }
        
    }

    cout<<"U:"<<endl;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"L:"<<endl;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            b[i] -= a[i][j] * ans[j];
        }
        ans[i] = b[i] / a[i][i];
    }
    return ans;
}

vector<double> guss_swap(vector<vector<double> > a, vector<double> b) {
    int n = a.size();

    vector<vector<double> > P(n, vector<double>(n, 0));
    vector<double> ans(n, 0);

    for(int i = 0; i < n; i++) {
        P[i][i] = 1;
    }

    for(int i = 0; i < n; i++) {
        double MAX = __DBL_MIN__;
        int index = i;
        for(int j = i; j < n; j++) {
            if(MAX < abs(a[j][i])) {
                MAX = abs(a[j][i]);
                index = j;
            }
        }
        for(int j = 0; j < n; j++) {
            swap(a[i][j], a[index][j]);
            swap(P[i][j], P[index][j]);
        }
        swap(b[i], b[index]);
    }

    cout<<"P:"<<endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return guss(a, b);
}


int main() {
    vector<vector<double> > a(4, vector<double>(4, 0));
    vector<double> b(4, 0);
   
    a[0][0] = 1.19;
    a[0][1] = 2.11;
    a[0][2] = -100;
    a[0][3] = 1;
    a[1][0] = 14.2;
    a[1][1] = -0.122;
    a[1][2] = 12.2;
    a[1][3] = -1;
    a[2][0] = 0;
    a[2][1] = 100;
    a[2][2] = -99.9;
    a[2][3] = 1;
    a[3][0] = 15.3;
    a[3][1] = 0.11;
    a[3][2] = -13.1;
    a[3][3] = -1;
    b[0] = 1.12;
    b[1] = 3.44;
    b[2] = 2.15;
    b[3] = 4.16;

    vector<double> ans = guss_swap(a, b);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
} 