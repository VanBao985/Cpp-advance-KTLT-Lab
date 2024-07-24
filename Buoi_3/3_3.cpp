#include<bits/stdc++.h>

using namespace std;
// Cao Van Bao 20225166

const int MAX = 100;
// INT_MAX: hang co gia tri = 0x7fffffff = 2^31-1
int n, c[MAX][MAX]; // so thanh pho + ma tran chi phi
int cmin = INT_MAX; // chi phi di lai nho nhat giua hai thanh pho
int best = INT_MAX; // tong chi phi nho nhat can tim

int curr=0; // tong chi phi hien tai
bool mark[MAX]; // danh dau thanh pho da di qua
int x[MAX]; // luu giu hanh trinh

void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] > 0){
                cmin = min(cmin, c[i][j]);
            }
        }
    }
}

// Nhanh can
void TRY(int k){
    for (int i = 2; i <= n ; i++)
    {
        if (mark[i] == false){
            mark[i] = true;
            x[k] = i; 
            curr += c[x[k-1]][i];
            if (k==n){
                if (curr + c[i][1] < best){
                    best = curr + c[i][1];
                }
            }
            else {
                int g = curr + (n-k+1) * cmin; // Tinh can
                if (g < best){
                    TRY(k+1);
                }
            }
            mark[i] = false;
            curr = curr - c[x[k-1]][i];
        }
    }
}
int main() {
    for (auto &&i : mark)
    {
        mark[i] = false;
    }
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}