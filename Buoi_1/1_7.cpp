#include<bits/stdc++.h>

using namespace std;

int n, tmp;
int *arr;

void input(){
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void sort_array(){
    for (int i = 0; i < n;  i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[j]<arr[i])
            {
                int tmp = *(arr+i);
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}

void slt(){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    input();
    cout << "Enter the number of elements: The input array is:" << endl;
    slt();
    sort_array();
    cout << "The sorted array is:" << endl;
    slt();
    return 0;
}
