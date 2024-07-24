#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t, a;
        cin >> k >> t;
        if (t == 1){
            while(k--){
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        }
        else{
            while(k--){
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}