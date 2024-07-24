#include<bits/stdc++.h>

using namespace std;

// Cao Van Bao 20225166

int a[1000], n;
int mem[1000]; // ghi nho do dai day con tang ket thuc tai chi so tuong ung

// Ham set up gia tri cho mang mem la -1
void init(){
    std::memset(mem, -1, sizeof(mem));
}

// Quy hoach dong
// Ham lis(i) tra ve do dai day con t/m ket thuc boi a[i]
int lis(int i){
    if (mem[i] != -1) return mem[i];
    mem[i] = 1;
    for (int j = 0; j < i; j++){
        if (a[j] < a[i]) {
            mem[i] = max(mem[i], lis(j)+1);
        }
    }
    return mem[i];
}

// Truy vet loi giai
void trace (int i){
    for (int j = 0; j < i; j++)
    {
        if (a[j]<a[i] && mem[i] == 1 + mem[j])  
        {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // do dai day con tang dai nhat va vi tri ket thuc
    int res = 1, pos = 0;
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}