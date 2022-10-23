#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

double func0(double x1, double x2, double x3) {
    return 0;
}
double func1(double x1, double x2, double x3) {
    return 0;
}
double func2(double x1, double x2, double x3) {
    return 0;
}

double func00(double x1, double x2, double x3) {
    return 0;
}
double func01(double x1, double x2, double x3) {
    return 0;
}
double func02(double x1, double x2, double x3) {
    return 0;
}

double func10(double x1, double x2, double x3) {
    return 0;
}
double func11(double x1, double x2, double x3) {
    return 0;
}
double func12(double x1, double x2, double x3) {
    return 0;
}

double func20(double x1, double x2, double x3) {
    return 0;
}
double func21(double x1, double x2, double x3) {
    return 0;
}
double func22(double x1, double x2, double x3) {
    return 0;
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

int main() {

    vector<vector<double> > df(3, vector<double>(3, 0));
    vector<double> f(3);
    vector<double> ans(3, 0);

    for(int t = 0; t < 10000; t++) {
        df[0][0] = func00(ans[0], ans[1], ans[2]);
        df[0][1] = func01(ans[0], ans[1], ans[2]);
        df[0][2] = func02(ans[0], ans[1], ans[2]);
        df[1][0] = func10(ans[0], ans[1], ans[2]);
        df[1][1] = func11(ans[0], ans[1], ans[2]);
        df[1][2] = func12(ans[0], ans[1], ans[2]);
        df[2][0] = func20(ans[0], ans[1], ans[2]);
        df[2][1] = func21(ans[0], ans[1], ans[2]);
        df[2][2] = func22(ans[0], ans[1], ans[2]);
        f[0] = -1 * func0(ans[0], ans[1], ans[2]);
        f[1] = -1 * func1(ans[0], ans[1], ans[2]);
        f[2] = -1 * func2(ans[0], ans[1], ans[2]);
        vector<double> s;
        s = guss(df, f);
        for(int i = 0; i < 3; i++) {
            ans[i] += s[i];
        }
        // cout<<"ans: ";
        // for(int i = 0; i < 3; i++) {
        //     cout<<ans[i] <<" ";
        // }
        // cout<<endl<<endl;
    }

    for(int i = 0; i < 3; i++) {
        cout<<ans[i]<<endl;
    }
}