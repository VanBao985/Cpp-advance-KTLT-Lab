#include <bits/stdc++.h>

using namespace std;

struct state{
    int i, j, old_L;   // old_L : store sum of state before
    state(int _i = 0, int _j = 0): i(_i), j(_j) {}
};

int main() {
    int n, M;
    cin >> n >> M;
    int m[n+1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n+1];
    stack<state> s;
    //# sum of selected weights
    int sum = 0;
    s.push(state(1, -1));
    while (!s.empty()){
        state &top = s.top();
        if (top.i > n){
            if (sum == M){
                for (int i = 1; i <= n; ++i){
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            } 
            s.pop();
            continue;
        }

        if (top.j > -1){
            sum = top.old_L;
        }
        if (top.j > 1){
            x[top.i] = 0;
            s.pop();
            continue;
        }
        if (sum != M && top.i <= n) {
            x[top.i] = top.j;
            top.old_L = sum;
            if(top.j == -1) sum -= m[top.i];
            if(top.j == +1) sum += m[top.i];
            s.push(state(top.i + 1, -1));
        }
        top.j++;
    }
    cout << "Not found solve!";
    return 0;
}