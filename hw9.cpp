#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5;
    vector<pair<double, double> > data(5);
    data[0] = {0.6, 1.433329};
    data[1] = {0.7, 1.632316};
    data[2] = {0.8, 1.896481};
    data[3] = {0.9, 2.247908};
    data[4] = {1.0, 2.718282};

    vector<double> divided(n, 0);
    vector<double> divided_ans(n, 0);

    divided_ans[0] = data[0].second;
    for(int i = 0; i < n; i++) {
        divided[i] = data[i].second;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j + i < n; j++) {
            divided[j] = (divided[j + 1] - divided[j]) / (data[j + i].first - data[j].first);
        }
        divided_ans[i] = divided[0];
    }

    // for(int i = 0; i < n; i++) {
    //     cout<<divided_ans[i]<<" ";
    // }

    double input1 = 0.82;
    double ans1 = divided_ans[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        ans1 *= (input1 - data[i].first);
        ans1 += divided_ans[i];
    }
    cout<<"f(0.82) = "<<ans1<<endl;

    double input2 = 0.98;
    double ans2 = divided_ans[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        ans2 *= (input2 - data[i].first);
        ans2 += divided_ans[i];
    }
    cout<<"f(0.98) = "<<ans2<<endl;

    

    return 0;
}