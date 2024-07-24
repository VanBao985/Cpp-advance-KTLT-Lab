#include <iostream>
#include <set>
using namespace std;

template<class T>  // class: representative struct, class, typename,...

set<T> set_union(const set<T> &a, const set<T> &b) {
    set <T> c;
    for (T x: a){
        c.insert(x);
    }
    for (T x: b){
        c.insert(x);
    }
    return c;
}
template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set <T> c;
    for (auto x : a){
        typename set<T>:: iterator it = b.find(x);
        if (it != b.end()){
            c.insert(*it);
        }
    }
    return c;
}

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::set<int> a = {1, 2, 3, 5, 7};
    std::set<int> b = {2, 4, 5, 6, 9};
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
    std::cout << "Union: "; print_set(c);
    std::cout << "Intersection: "; print_set(d);
    return 0;
}