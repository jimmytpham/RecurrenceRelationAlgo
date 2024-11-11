//Recur2
//Assignment 3
//Jimmy Pham
//T00629354
//COMP 3051
//Thompson Rivers University

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace chrono;

long long Recur2(int n) {
    if (n == 0 || n == 1) return 2;
    vector<long long> T(n + 1);
    T[0] = 2;
    T[1] = 2;
    for (int i = 2; i <= n; ++i) {
        T[i] = 2 * T[i - 1] * T[i - 2];
    }
    return T[n];
}


int main() {

    cout << "\nDynamic Programming Algorithm:\n";
    for (int i = 0; i <= 7; ++i) {
        cout << "T(" << i << ") = " << Recur2(i) << "\n";
    }

    cout << "\nPerformance Test:\n";
    for (int n : {1, 2, 4, 6, 8}) {
        auto start = high_resolution_clock::now();  //start internal clock to record time
        long long result = Recur2(n);
        auto end = high_resolution_clock::now();    //end internal clock
        duration<double> duration = end - start;
        cout << "T(" << n << ") = " << result << " computed in " << duration.count() << " seconds\n";
    }

    return 0;

}
