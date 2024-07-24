#include<iostream>
#include<vector>
#include<algorithm>

// Cao Văn Bảo 20225166

using namespace std;

int m, n;
vector<int> a, b;
void input(){
    int temp;
    cin >> n;
    for(int i = 0;i<=n;i++){
        cin >> temp;
        a.push_back(temp);
    }
    cin >> m;
    for(int i = 0;i<=m;i++){
        cin >> temp;
        b.push_back(temp);
    }
}

vector<int> xor_multi(int n, int m, vector<int> a, vector<int> b){
    vector<int> c(n+m+1, 0);
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=m;j++){
            c.at(i+j) += a.at(i) * b.at(j);
        }
    }
    return c;
}

void solve(vector<int> c){
    int sol = 0;
    for (vector<int>::iterator it = c.begin(); it != c.end(); it++)
    {
        sol = sol ^ *it;
    }
    cout << sol;
}

int main(){    
    input();  
    vector<int> c;
    c = xor_multi(n, m, a, b);
    solve(c);
}   