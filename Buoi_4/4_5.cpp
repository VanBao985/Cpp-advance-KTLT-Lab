#include<iostream>
#include<stack>
#include<vector>
#include<list>

using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> st;
    vector<bool> visited(adj.size()+1, false);
    st.push(1); 
    if (adj.size()== 0) return;
    while (!st.empty()){
        int a = st.top();
        if (!visited[a]){        
            cout << a << endl;
            visited[a] = true;
        }
        if (!adj[a].empty()){
            int x = adj[a].front();
            adj[a].pop_front();
            if (!visited[x]){
                st.push(x);
            }
        }
        else st.pop();
    }
}

int main(int argc, char const *argv[])
{
    // test case
    // int n = 7;
    // vector< list<int> > adj;
    // adj.resize(n + 1);
    // adj[1].push_back(2);
    // adj[2].push_back(4);
    // adj[1].push_back(3);
    // adj[3].push_back(4);
    // adj[3].push_back(5);
    // adj[5].push_back(2);
    // adj[2].push_back(7);
    // adj[6].push_back(7);
    // dfs(adj);
    // return 0;
    // Test case with only 1 node
    int n = 1;
    vector< list<int> > adj;
    adj.resize(n + 1);
    // The graph only has 1 node and no edges
    dfs(adj);
    return 0;
}

