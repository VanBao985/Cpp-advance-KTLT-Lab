#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct element{
    int key;
    int value;
};

vector<element> a;
void input(){
    element temp;
    while (cin >> temp.key && cin >> temp.value)
    {
        a.push_back(temp);
    }
}

void output(){
    for (element tmp: a)
    {
        cout << tmp.key << " " << tmp.value << endl;
    }
}

int main(int argc, char const *argv[])
{
    input();
    std::sort(a.begin(), a.end(), [=] (element tmp1, element tmp2){
        if (tmp1.value != tmp2.value) return tmp1.value > tmp2.value;
        else return tmp1.key > tmp2.key;
    });
    output();
    return 0;
}
