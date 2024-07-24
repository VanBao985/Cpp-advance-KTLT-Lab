#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}
void delete_even(vector<int> &a) {
    vector<int>:: iterator it;
    for (it = a.begin(); it != a.end(); it++){
        if ((*it)%2==0){
            vector<int>:: iterator tmp = it;
            it--;
            a.erase(tmp);
        }
    }
}

void sort_decrease(vector<int> &a) {
    unsigned int i, j;
    for (i = 0; i < a.size(); i++){
        for (j = i; j < a.size(); j++){
            if (a[i] < a[j])  swap (a[i], a[j]);
        }
    }
}
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    vector <int> c;
    unsigned int i=0, j=0;
    while (i < a.size() && j < b.size()){
        if (a[i] > b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()){
        c.push_back(a[i]);
        i++;
    }
    while (j < b.size()){
        c.push_back(b[j]);
        j++;
    }
    return c;
}
int main() {
    int m, n, u;
    std::vector<int> a, b;
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }
    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);
    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);
    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);
    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);
    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);
    return 0;
}