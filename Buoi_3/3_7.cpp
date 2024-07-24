#include<bits/stdc++.h>

using namespace std;

// Cao Van Bao 20225166

struct state{
    // i: current position in the binary sequence
    // j: current value at position 'i'
    // old_L: value 'L' before current state was processed
    int i, j, old_L;
    // constructor
    state(int _i=0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    // count number of consecutive suffix 1
    int L = 0;
    s.push(state(1,0));
    while (!s.empty())
    {
        // Khu de quy quay lui
        state &top = s.top();
        // if a new binary sequence is found
        if (top.i > n)
        {
            for (int i = 1; i <= n; ++i)
            {
                cout << x[i] << " ";
                if (i==n) cout << "\n";
            }
            s.pop();
            continue;
        }
        // Khu de quy

        if (top.j > 0){
            L = top.old_L; 
        }
        if (top.j > 1){
            s.pop();
            continue;
        }
        if ((L + 1 ) < k || top.j == 0){
            x[top.i] = top.j;
            top.old_L = L;
            L = (top.j) ? (L+1) : 0;
            s.push(state(top.i+1,0));
        }
        top.j++;
    }
    return 0;
}
