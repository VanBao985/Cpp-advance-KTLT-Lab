#include<bits/stdc++.h>

using namespace std;

double* maximum(double* a, int size){

    double *max;

    max = a;

    if (a==NULL) return NULL;
    for (int i = 0; i < size; i++)
    {
        if (a[i] > *max) max = &a[i];
    }
    return max;
}

int main(int argc, char const *argv[])
{
    
double arr[] = {1., 10., 2., -7., 25., 3.};
double* max = maximum(arr, 6);
printf("%.0f", *max);
    return 0;
}
