#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int D[MAX][MAX];
int n; int k;

int C(int n, int k){
    if (n==k || k ==0)
    {
        D[n][k] = 1;
    }
    if (D[n][k] < 0){
        D[n][k] = C(n-1, k-1) + C(n-1, k);
    }
    return D[n][k];
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            D[i][j] = -1;
        }
    }
    cin >> n;
    cin >> k;
    cout << C(n, k);
    return 0;
}
