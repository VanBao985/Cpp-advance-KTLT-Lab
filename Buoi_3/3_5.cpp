#include<iostream>

using namespace std;
// Cao Van Bao 20225166

int binom(int n, int k){
    if (k>n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

// Khu de quy  
int binom2(int n, int k){
    int C[100][100];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            C[i][j] = 0;  // set up C(n,k) = 0 voi k > n
            if (i==j) C[i][j] = 1;  // set up C(n,k) = 1 voi k=n
        }
    }
    C[1][0]=1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (j==0){
                C[i][j] = 1;  // set up C(n,0) = 1 
            } else{
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
    return C[n][k];
}

int main(int argc, char const *argv[])
{
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
        cout <<  binom(n, k) << " ";
        cout << endl;
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            cout <<  binom2(n, k) << " ";
        cout << endl;
        
    }
    return 0;
}
