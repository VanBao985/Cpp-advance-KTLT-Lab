#include<bits/stdc++.h>

using namespace std;

int lucas (int n){

    // Cao Văn Bảo 20225166
    if (n == 0) return 2;
    if (n == 1) return 1;
    return lucas (n -1) + lucas (n-2);
}

int main(int argc, char const *argv[])
{
    cout << lucas ( 10);
    return 0;
}
