// Viet ham tinh su thang bang (balance) cua xau 
// idea: ky tu 1: balance++, 0: balance--
// Gap 2 balance giong nhau: duoc 1 chuoi can bang

#include<iostream>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

    
vector<int> balance;
void caculate_balance(vector<int> &value){

    int balance_value = 0;
    balance.push_back(balance_value);
    for (int i = 1; i <= value.size()-1; i++){
        if (value[i] == 1) balance_value++;
        else balance_value--;
        balance.push_back(balance_value);
    }
}

int caculate_C_2_n(int n){
    if (n==2) return 1;
    if (n<2) return 0;
    return caculate_C_2_n(n-1) + n-1;
}

void solve(){
    map<int, int> caculate;
    for(auto i: balance){
        caculate[i]++;
    }
    int count = 0;
    for(auto x: caculate){
        count += caculate_C_2_n(x.second);
    }
    cout << count;
}

int main(int argc, char const *argv[])
{
    string str;
    ifstream infile("test5_4_13.txt");
    if (!infile.is_open()) {
        exit(1);
    }
    infile >> str;
    vector<int> value;
    value.push_back(0);
    for (int i = 0; i < str.size(); i++){
        value.push_back((int) str[i] - '0');
    }
    caculate_balance(value);
    solve();
    return 0;
}
