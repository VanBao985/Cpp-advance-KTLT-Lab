#include<iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    if (adj.size() == 0) return;
    q.push(1); 
    visited[1] = true;
    cout << 1 << endl;
    while (!q.empty()){
        int a = q.front();
        q.pop();
        for (int x : adj[a]){
            if (!visited[x]){
                visited[x] = true;
                cout << x << endl;
                q.push(x);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
    return 0;
}
