#include<iostream>
#include<vector>
#include<stack>
#include<fstream>

using namespace std;

vector<int> high;
void input(){
    ifstream infile("data_test3_4_12.txt");
    if (!infile.is_open()) {
        exit(1);
    }
    int n;
    infile >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        infile >> x;
        high.push_back(x);
    }
    infile.close();
}

int lagrest_rectangle(){
    stack<int> st; // store index of rectangle
    int max_value = 0;

    for (int i = 0; i <= high.size(); i++) {
        int h;
        if (i == high.size()) h = 0; // create a virtual column to finish
        else h = high[i];
        // Exception stack is empty, 
        // Found a high column < st.top high do caculate area
        while (!st.empty() && h < high[st.top()]){
            int height = high[st.top()];
            st.pop();
            // width: if stack is empty, width: 0 -> i
            // else: width: i - index(column > high[i] before)
            int width = st.empty() ? i : i - st.top() - 1;
            max_value = max(max_value, width * height);
        }
        st.push(i);
    }
    return max_value;
}

int main(int argc, char const *argv[])
{
    input();
    cout << lagrest_rectangle();
    return 0;
}
