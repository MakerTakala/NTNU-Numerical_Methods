#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<pair<double, double> > data{{0.6, 1.433329}, {0.7, 1.632316}, {0.8, 1.896481}, {0.9, 2.247908}, {1.0, 2.718282}};
    int n = data.size();
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

    double input = 0.82;
    double ans1 = divided_ans[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        ans1 *= (input - data[i].first);
        ans1 += divided_ans[i];
    }
    cout<<"f("<<input<<") = "<<ans1<<endl;

    

    return 0;
}