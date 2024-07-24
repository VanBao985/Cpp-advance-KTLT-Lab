#include<bits/stdc++.h>

using namespace std;

int **matrix;
int n, m;

void input(){
    cin >> m >> n;
    matrix = new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        } 
    }
}

int sum(int** &matrix, int m, int n){
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] % 2 == 0)
            sum += matrix[i][j];
        }
    }
    return sum;
}

void slt(){
    cout << "Enter m, n = ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "mt[" << i << "][" << j << "] = ";
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] <<  " ";
        }
        cout << endl;
    } 
    cout << "The sum of all even elements is " << sum(matrix, m, n);
}
int main(int argc, char const *argv[])
{
    input();
    slt();
    return 0;
}

