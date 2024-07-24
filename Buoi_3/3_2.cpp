#include<iostream>

using namespace std;

// Cao Văn Bảo 20225166
int n; 
int X[100], Y[100]; // lưu toạ độ các bước di chuyển
bool mark[100][100]; // đánh dấu vị trị đã đi qua

// Mảng hx, hy mô tả vị trí quân mã di chuyển được tiếp theo
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

// In ra quá trình di chuyển
void print_sol(){
    for (int i = 1; i <= n*n; ++i)
    {
        cout << "(" << X[i] << " " << Y[i] << ")" << endl;
    }
    exit(0);
}

bool check(int k, int x, int y){
    if (x < 1 || x > n) return false;
    if (y < 1 || y > n) return false;
    if (k==65) return false;
    return true;
}

// Đệ quy quay lui cho mã di chuyển
void TRY(int k){
    for (int i = 0; i < 8; i++)
    {
        int x = X[k-1] + hx[i];
        int y = Y[k-1] + hy[i];
        if (check(k, x, y))
        {
            if (mark[x][y] == false)
            {
                X[k] = x;
                Y[k] = y;
                mark[x][y] = true;
                if (k==n*n)
                {
                    print_sol();
                }
                TRY(k+1);
                mark[x][y] = false;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n;
    mark[1][1] = true;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
