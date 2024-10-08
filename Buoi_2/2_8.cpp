#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Cao Văn Bảo 20225166

using namespace std;
int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
    {1, 3, 7},
    {2, 3, 4, val1},
    {9, 8, 15},
    {10, val2},
    };
    sort(a.begin(), a.end(), [=] (vector<int> x, vector<int> y) -> bool {
        return accumulate(x.begin(), x.end(), 0) >  accumulate(y.begin(), y.end(), 0);
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}