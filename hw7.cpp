#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
    vector<pair<double, double> > node(3);
    node[0] = make_pair(-1, 6);
    node[1] = make_pair(-2, -6);
    node[2] = make_pair(5, 0);

    vector<vector<double> > df(3, vector<double>(3, 0));
    vector<double> f(3);
    vector<double> ans(3, 0);
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 1;

    for(int t = 0; t < 10000; t++) {
        for(int i = 0; i < 3; i++) {
            df[i][0] = -2 * node[i].first + 2 * ans[0];
            df[i][1] = -2 * node[i].second + 2 * ans[1];
            df[i][2] = -2 * ans[2];
            f[i] = (-1) * (pow(node[i].first - ans[0], 2) + pow(node[i].second - ans[1], 2) - pow(ans[2], 2));
        }
        vector<double> s;
        s = guss(df, f);
        for(int i = 0; i < 3; i++) {
            ans[i] += s[i];
        }
        cout<<"ans: ";
        for(int i = 0; i < 3; i++) {
            cout<<ans[i] <<" ";
        }
        cout<<endl<<endl;
    }

    for(int i = 0; i < 3; i++) {
        cout<<ans[i]<<endl;
    }



    return 0;
}