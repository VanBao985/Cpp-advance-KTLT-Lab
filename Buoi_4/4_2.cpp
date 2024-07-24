#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

using Point = pair<double, double>;
double area(Point a, Point b, Point c) {
    double ab = sqrt(pow((a.first - b.first),2)+ pow((a.second - b.second),2));
    double bc = sqrt(pow((c.first - b.first),2)+ pow((c.second - b.second),2));
    double ac = sqrt(pow((a.first - c.first),2)+ pow((a.second - c.second),2));
    double p = (ab+bc+ac)/2;
    return sqrt(p*(p-ab)*(p-bc)*(p-ac));
}
// int main() {
// cout << setprecision(2) << fixed;
// cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
// return 0;
// }