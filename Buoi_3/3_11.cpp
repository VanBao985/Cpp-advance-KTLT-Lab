
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
// Cao Van Bao 20225166

int n, r;
int list_v[1000]; // vertex need access
// trace path with index: vertex
int state_v[1000]; 
// check visited vertex, index: vertex, value: T/F
bool visited[1000];
int c[1000][1000]; // cost matrix
int t = 0; //size of list_v[]
int curr, best;

void input(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
}

void changeint(string str){
    t = 0;
    for (int i = 0; i < str.length(); i+=2){
        //convert char to int and store in array x
        list_v[t] = str[i] - '0';
        t++;
    }
}

void TRY(int k){
    int m = state_v[k-1];
    for (int j = 1; j < t-1; j++){
        int i = list_v[j];
        if ((!visited[i]) && c[m][i] > 0){
            visited[i] = true;
            state_v[k] = i;
            curr = curr + c[m][i];
            if (k == t - 2){
                if (c[i][list_v[t-1]] != 0){
                    best = min(best, curr + c[i][list_v[t-1]]);
                } 
            }
            else TRY(k+1);
            visited[i] = false;
            curr = curr - c[m][i];
        }
    }      
}

int main(int argc, char const *argv[])
{
    cin >> n >> r;
    input();
    while (r>=0){
        r--;
        string str;
        getline(cin, str, '\n');
        changeint(str);
        for (int i = 0; i <= n; i++){
            visited[i] = false;
        }
        state_v[list_v[0]] = 0;
        if (list_v[0]==0) continue; 
        curr = 0; best = INT_MAX;
        state_v[0] = list_v[0];
        TRY(1);
        if (best == INT_MAX) cout << 0;
        else cout << best;
        cout << endl;
    }
    return 0;
}
