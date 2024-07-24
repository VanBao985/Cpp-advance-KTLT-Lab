#include<bits/stdc++.h>

using namespace std;

int *arr;
int n;

void input(){
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void printArray(int *arr, int m, int n){
    for (int i = m; i <= n; i++)
    {
        cout << arr[i];
    }
    
}

void slt(){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printArray(arr, i, j);
            cout << endl;
        }
    }
}
// Cao Văn Bảo 20225166
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    slt();
    return 0;
    delete[] arr;
}
