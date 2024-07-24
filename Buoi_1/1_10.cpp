#include<bits/stdc++.h>

using namespace std;

typedef struct matrix{
    int row;
    int column;
    int **arr;
    void input(){
        cout << "Size of matrix: \nRow: ";
        cin >> row;
        cout << "Column: "; cin >> column;
        arr = new int*[row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[column];
        }
        for (int i = 0; i < row; i++)
        {
            for (int  j = 0; j < column; j++)
            {
                cin >> *(*(arr+i)+j);
            }
        }
    }
} matrix;

matrix A, B, C;

void solution(matrix C){
    cout << "Result: ";
    for (int i = 0; i < C.row; i++)
    {
        for (int j = 0; j < C.column; j++)
        {
            cout << C.arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkAdd(matrix A, matrix B){
    if (A.row != B.row || A.column != B.column) return false;
    return true;
}
bool checkMulti(matrix A, matrix B){
    if (A.column==B.row) return true;
    return false;
}

matrix operator + (matrix A, matrix B){
    matrix C=A;
    for (int i = 0; i < C.row; i++)
    {
        for (int j = 0; j < C.column; j++)
        {
            C.arr[i][j] = A.arr[i][j] + B.arr[i][j];
        }
    }
    return C;
}

matrix operator * (matrix A, matrix B){
    matrix C;       int temp;
    C.row=A.row;    C.column=B.column;
    C.arr = new int*[C.row];
    for (int i = 0;i < C.row;i++)
    {
        C.arr[i] = new int[C.column];
    }
    for (int i = 0; i < C.row; i++)
    {
        for (int j = 0; j < C.column; j++)
            {
                temp = 0;
                for (int k = 0; k < A.column; k++)
                {
                    temp += A.arr[i][k]*B.arr[k][j];
                }
                C.arr[i][j]=temp;
            }
    }
    return C;
}

void addMatrix(matrix A, matrix B){
    if (checkAdd(A, B))
    {
        C = A + B;
        solution(C);
    }
    else cout << "Add matrix: Error size!!";
}
// Cao Văn Bảo 20225166
void subMatrix(matrix A, matrix B){
    for (int i = 0; i < B.row; i++)
    {
        for (int j = 0; j < B.column; j++)
        {
            B.arr[i][j]=-B.arr[i][j];
        }
    }
    addMatrix(A, B);
}

void multiMatrix(matrix A, matrix B){
    if (checkMulti(A, B))
    {
        C = A * B;
        solution(C);
    }
    else cout << "Multi matrix: Error size!!";
}

// void select(){
//     cout << "List selection: \n1. +\n2. - \n3. *\nInput selection: ";
//     int temp;    cin >> temp;
//     switch (temp)
//     {
//     case 1: addMatrix(A,B);
//         break;
//     case 2: subMatrix(A,B);
//         break;
//     case 3: multiMatrix(A,B);
//         break;
//     default: cout << "Selection: Error";
//         break;
//     }
// }

void deleteMatrix(matrix M){
    delete[] M.arr;
    for (int i = 0; i < M.row; i++)
    {
        delete[] M.arr[i];
    }
    
}
int main(int argc, char const *argv[])
{
    A.input();
    B.input();
    // select();
    addMatrix(A, B);
    multiMatrix(A, B);
    deleteMatrix(A); deleteMatrix(B); deleteMatrix(C);
    return 0;
}
