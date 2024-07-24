#include<bits/stdc++.h>

using namespace std;

// Khu de quy
int Fibonacci(int n){
    int f0, f1, f2, k;
    if (n<=1) return n; // f0 = 0, f1 = 1
    else {
        for (int k = 2; k <= n; k++)
        {
            f2 = f0 + f1; 
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
}