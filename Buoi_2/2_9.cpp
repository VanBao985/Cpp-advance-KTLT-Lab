#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdio>

using namespace std;

// Cao Văn Bảo 20225166

const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;

double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double x[NUM_INPUTS];
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
    // rand(): hàm sinh giá trị random.
}

//# BEGIN fast code
const int MAX = 100000;
const double BEGIN = -5;
const double END = 5;
double delta = 0.0001;
double sigmoid[MAX];

// hàm chuẩn bị dữ liệu: tính toán trước
void precalc() {
    double value = BEGIN;
    for (int i = 0; i < MAX; i++)
    {
        sigmoid[i] = sigmoid_slow(value);
        value += delta;
    }
}
// hàm tính sigmoid(x) nhanh sigmoid_fast(x)
// inline: chèn code vào 

inline double sigmoid_fast(double x) {
    if (x>END)
    {
        return 1.0;
    }
    if (x<BEGIN)
    {
        return 0.0;
    }
    int idx = floor((x - BEGIN)/delta);  // floor: làm tròn về số nguyên không vượt quá.
    return sigmoid[idx] + ((sigmoid[idx + 1] - sigmoid[idx]) * (x - BEGIN - idx * delta) )/delta;

}
//# END fast code

double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    // printf("Time: %.9f\n", taken / CLOCKS_PER_SEC);
    return taken;
}
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;
    if (a.size() != b.size()) return false;
    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
        return false;
        }
    }
    return true;
}
int main() {
    prepare_input();
    precalc();
    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);
    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
    if (is_correct(a, b) || (slow/fast >= 1.3)) {
        printf("Correct answer! Your code is faster at least 30%%!");
    } else {
      printf("Wrong answer or your code is not fast enough!\n");
    }
    return 0;
}