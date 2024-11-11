//Recur1
//Assignment 3
//Jimmy Pham
//T00629354
//COMP 3051
//Thompson Rivers University

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

long long Recur1(int n) {
    if (n == 0 || n == 1)
        return 2;
    else
        return 2 * Recur1(n - 1) * Recur1(n - 2);
}


int main() {
    cout << "Recursive Algorithm:\n";
    for (int i = 0; i <= 7; ++i) {
        cout << "T(" << i << ") = " << Recur1(i) << "\n";
    }


    cout << "\nPerformance Test:\n";
    for (int n : {1, 2, 4, 6, 8}) {
        auto start = high_resolution_clock::now();  //start internal clock to record time 
        long long result = Recur1(n);
        auto end = high_resolution_clock::now();    //end internal clock 
        duration<double> duration = end - start;
        cout << "T(" << n << ") = " << result << " computed in " << duration.count() << " seconds\n";
    }
    return 0;
}
