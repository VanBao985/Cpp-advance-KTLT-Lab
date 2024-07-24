#include<iostream>

using namespace std;

struct bigNum{
    char sign;
    string num;
};

bigNum numA, numB;
void input(bigNum &number){
    string str; 
    cin >> str;
    number.sign = str[0];
    number.num ="";
    for (int i = 1; i < str.size(); i++){
        number.num += str[i];
    }
}

int to_int(char c){
    return c -'0';
}
// define: division 
int custom_div(int a, int b) {
    if ((a < 0) != (b < 0)) {
        return (a / b) - 1;
    } else {
        return a / b;
    }
}

int custom_mod(int a, int b) {
    int mod = a % b;
    if (mod < 0) {
        mod += abs(b);
    }
    return mod;
}

// s1 is longer than s2
string add(string s1, string s2){
    string str="";
    int c = 0;
    int i = 1;
    for (i; i <= s2.size(); i++){
        int x = to_int(s1[s1.size()-i]) + to_int(s2[s2.size()-i]) + c;
        c = custom_div(x,10);
        str = to_string(custom_mod(x, 10)) + str;
    }
    while (i <= s1.size()){
        int x = to_int(s1[s1.size()-i]) + c;
        c = custom_div(x,10);
        str = to_string(custom_mod(x, 10)) + str;
        i++;
        // str = s1[s1.size() - i] + str;
    }
    if (s1.size() == s2.size()){
        str = ( c == 0 ? str : to_string(c) + str);
    }
    return str;
}

string sub(string s1, string s2){
    string tmp ="";
    for (int i = 0; i < s2.size(); i++){
        tmp += '0'-to_int(s2[i]);
    }
    return add(s1, tmp);
}

bigNum operator + (bigNum s1, bigNum s2){
    bigNum c;
    c.num = add(s1.num, s2.num);
    if (s1.sign == s2.sign){
        c.sign = s1.sign;
        c.num = add(s1.num, s2.num);
    }
    else {
        if (s1.num < s2.num) {
            c.sign = s2.sign;
            c.num = sub(s2.num, s1.num);
        }
        else {
            c.sign = s1.sign;
            c.num = sub(s1.num, s2.num);
        }
    }
    return c;
}

bigNum operator - (bigNum s1, bigNum s2){
    bigNum c;
    if (s1.sign != s2.sign){
        c.sign = s1.sign;
        c.num = add(s1.num, s2.num);
    }
    if (s1.sign == s2.sign){
        if (s1.num < s2.num){
            c.sign = 1 - to_int(s1.sign) + '0';
        }
        else{
            c.sign = s1.sign;
        }
        c.num = sub(s1.num, s2.num);
    }
    return c;
}

bigNum operator * (int a, bigNum s2){
    bigNum s1;
    if (a==0){
        s1.sign = '1';
        s1.num = "0";
        return s1;
    }
    s1 = s2;
    for (int i = 1; i < a; i++){
       s1 = s1 + s2;
    }
    return s1;
}

bigNum operator * (bigNum s1, bigNum s2){
    bigNum c;
    c.sign = (s1.sign == s2.sign ? '1' : '0');
    c.num = "";
    s1.sign = '1';
    for(int i = s2.num.size()-1; i>=0; i--){
        bigNum tmp = to_int(s2.num[i]) * s1;
        string str = tmp.num;
        int k = i;
        while (k<s2.num.size()-1){
            str = str + '0';
            k++;
        }
        // cout << str << endl;
        c.num = add(str, c.num);
    }
    return c;
}

void solve(bigNum c){
    cout << to_int(c.sign);
    for (char i : c.num){
        cout << to_int(i);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input(numA);
    input(numB);
    bigNum numC = numA * numB - 3 * numA + 4 * numB;
    solve(numC);
    return 0;
}
