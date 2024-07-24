#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    vector<int> results(adj.size(), INT_MAX);
    vector<bool> selected(adj.size());  // updated, after not access 
    int index = 0; // index_select
    results.at(0) = 0;
    for (unsigned int i = 0; i < adj.size()-1; i++) {
        // Access adj and update
        for (auto x : adj[index]){
            if (!selected[x.first]){
                results[x.first] = min(results[x.first], x.second + results[index]);
            }
        }
        selected[index] = true;

        // Find min element for the next access
        int min_value = INT_MAX;
        for (unsigned int i = 0; i < results.size(); i++){
            if (!selected[i] && (results[i] <= min_value)){
                min_value = results[i];
                index = i;
            }
        }
    }
    return results;
}

int main() {
    int n = 9;
    vector< vector< pair<int, int> > > adj(n);
    // lambda function
    auto add_edge = [&adj] (int u, int v, int w) { 
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);
    vector<int> distance = dijkstra(adj);
    for (int i = 0; i < distance.size(); ++i) {
        cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
    }
    return 0;
}