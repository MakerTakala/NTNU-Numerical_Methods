#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    vector<pair<double, double> > data{{8.1, 16.94410}, {8.3, 17.56492}, {8.6, 18.50515}, {8.7, 18.82091}};
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

    double input = 8.4;
    double ans1 = divided_ans[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        ans1 *= (input - data[i].first);
        ans1 += divided_ans[i];
    }
    cout<<"f("<<input<<") = "<<ans1<<endl;

    

    return 0;
}