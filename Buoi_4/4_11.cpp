/*
n buc tuong: 1 -> n 
Moi buc tuong: a-i giac, x-i linh, moi linh chong do k-i giac
Neu a-i < x-i khong ai lot qua 
Nguoc lai: lot a-i - x-i * k-i
Tong so linh s, tong giac lot vao min

input: n va s, n: tong so tuong, s: tong so linh
cac dong tiep : a-i, k-i: giac tan cong, kha nang chong do cua linh
*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

struct segment_wall {
    int a_i;
    int k_i;
};

// enemy get through
// int enemy_get_through(int a_i, int x_i, int k_i){
//     if (a_i<= x_i) return 0;
//     int enemy = a_i - x_i * k_i;
//     if (enemy <= 0) return 0;
//     return enemy;
// }

// define priority level: highest a_i, k_i pop first
struct cmp{
    bool operator() (segment_wall s1, segment_wall s2){
        return min(s1.a_i, s1.k_i) < min(s2.a_i, s2.k_i);
    }
};

priority_queue <segment_wall, vector<segment_wall>, cmp> castle;

// arrange soldier
int killed_enemy = 0; 
void arrange_soldier(int s){
    while (!castle.empty()){
        if (s<=0) return;
        segment_wall sgm = castle.top();
        castle.pop();
        if (sgm.a_i <= sgm.k_i) {
            killed_enemy += sgm.a_i;
        }
        else{
            killed_enemy += sgm.k_i;
            sgm.a_i = sgm.a_i - sgm.k_i;
            castle.push(sgm);
        }       
        s--;
    }
}

int main(int argc, char const *argv[])
{
    int n, s;
    cin >> n >> s;
    int total_enemy = 0;
    for (int i = 0; i< n; i++){
        int a_i; 
        int k_i;
        cin >> a_i >> k_i;
        total_enemy += a_i;
        segment_wall sgm;
        sgm.a_i = a_i;
        sgm.k_i = k_i;
        castle.push(sgm);
    }
    arrange_soldier(s);
    std::cout << total_enemy - killed_enemy;
    return 0;
}
