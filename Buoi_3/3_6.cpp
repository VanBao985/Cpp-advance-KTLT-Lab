#include<iostream>

using namespace std;
// Cao Van Bao 20225166

int gcd(int a, int b){
    if (b == 0 ) return a;
    return gcd(b, a%b);
}

// Khu de quy
int gcd2(int a, int b){
    int ucln = 0;
    int c = std::min(a,b);
    for (int i = 1; i <= c; i++)
    {
        if (a%i == 0 && b%i == 0)
        {
            ucln = i;
        }
    }
    return ucln;
}

int main() {
int a, b;
cin >> a >> b;
cout << gcd(a, b) << endl << gcd2(a, b);
return 0;
}