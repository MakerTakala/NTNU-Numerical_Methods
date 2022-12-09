#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
using namespace std;

void display(vector<vector<double>> A) {
    for(auto v : A) {
        for(auto x : v) {
            cout<<setw(10)<<to_string(x)<<" ";
        }
        cout<<endl;
    }
}

vector<vector<double>> transform(vector<vector<double>> A) {
    vector<vector<double>> out(A.front().size(), vector(A.size(), 0.0));
    for(int i = 0; i < A.front().size(); i++) {
        for(int j = 0; j < A.size(); j++) {
            out[i][j] = A[j][i];
        }
    }
    return out;
}

vector<double> sub_vector(vector<double> A, vector<double> B) {
    for(int i = 0; i < A.size(); i++) {
        A[i] -= B[i];
    }
    return A;
}

double inner_mul_vector(vector<double> A, vector<double> B) {
    double sum = 0;
    for(int i = 0; i < A.size(); i++) {
        sum += A[i] * B[i];
    }
    return sum;
}

vector<double>  mul_scalar_vector(vector<double> A, double scalar) {
    for(int i = 0; i < A.size(); i++) {
        A[i] *= scalar;
    }
    return A;
} 

double normalize(vector<double> &v) {
    double sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i] * v[i];
    }
    sum = sqrt(sum);
    for(double &x : v) {
        x /= sum;
    }
    return sum;
}

void grame_schmidt(vector<vector<double>> A) {
    int n = A.front().size();
    vector<vector<double>> Q;
    Q = transform(A);
    vector<vector<double>> R(n, vector(n, 0.0));

    for(int i = 0; i < Q.size(); i++) {
        for(int j = 0; j < i; j++) {
            double inner = inner_mul_vector(Q[j], Q[i]);
            Q[i] = sub_vector(Q[i], mul_scalar_vector(Q[j], inner));
            R[j][i] = inner;
        }
        R[i][i] = normalize(Q[i]);
    }
    Q = transform(Q);

    cout<<endl<<"Q:"<<endl;
    display(Q);
    cout<<endl<<"R:"<<endl;
    display(R);
}


int main(){
    vector<vector<double>> A{{3, -1, 2}, {4, 1, 0}, {-3, 2, 1}, {1, 1, 5}, {-2, 0, 3}};
    grame_schmidt(A);

    return 0;
}