// DFS (depth first search)
// access vertex use recursion

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> neigh_v; // contain vertex neighbor
vector<bool> visited; // check visited ?
int current;     // number of visited vertex
int cntPath = 0; // count nember of satisfy solve


void DFS(int start, int current, int k){
    for (int v : neigh_v[start]){
        if (!visited[v]){     
            current++;  
            if (current == k){
                cntPath++;
            }
            else{
                visited[v] = true;
                DFS(v, current, k);
            }
            // visited[v] = false;
            current--;
        }
    }
    visited[start] = false;
}

int main(int argc, char const *argv[]){
    int n, k, m;
    cin >> n >> k;
    cin >> m;
    neigh_v.resize(n+1);  // 1 to n
    for (int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y;
        neigh_v[x].push_back(y);
        neigh_v[y].push_back(x);
    }
    visited.resize(n+1, false); 
    for (int i = 1; i <= n; i++){ 
        visited[i]=true; // declare all is false, except vertex start
        int current = 0;
        DFS(i,current, k);
    }
    cout << cntPath/2;  // overlap: data counted 2nd
    return 0;
}