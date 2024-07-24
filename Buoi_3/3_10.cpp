#include<iostream>

using namespace std;

int n, h;
int cnt; // count of binary 1
int x[1000]; // store binary sequence 
void input(){
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        x[i]=0;
    }
}

void print_solve(){
    for (int i=1; i<=n; i++){
        cout << x[i];
    }
    cout << endl;
}

void TRY1(int k){
    if (cnt==h) {
        print_solve();
        return;
    }
    if (k>n)  return;
    for (int i = 0; i <= 1; i++) {
        if (i == 1) {
            cnt++;   x[k]=1;
            TRY1(k+1);
            cnt--;   x[k]=0;
        } else{
            x[k]=0;
            TRY1(k+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        input();
        cnt=0;
        TRY1(1);
        cout << endl;
    }
    return 0;
}
