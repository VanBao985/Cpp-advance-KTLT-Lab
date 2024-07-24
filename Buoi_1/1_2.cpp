#include<bits/stdc++.h>

// Cao Văn Bảo 20225166
using namespace std;

int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    cout << "address of first five elements in memory." << endl ;
    for (int i=0; i<5;i++) 
        cout << "\ta[" << i << "]\t"; 
    cout << endl;
    int *p;
    for (int i = 0; i < 5; i++)
    {
        p = &a[i];
        cout << "\t" << p;
    }
    return 0;
}