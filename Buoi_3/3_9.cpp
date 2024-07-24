#include<iostream>

using namespace std;

bool work[1000];
int cnt[1000]; // count number of work day consecutive
int k1, k2, n;

void printSolve(){
    for(int i =1; i<=n; i++){
        cout << (work[i] ? "1" : "0");
    }
    cout << endl;
}
void TRY(int k);

void setWork(int k){
    work[k] = true;
    cnt[k] = cnt[k-1] + 1;
}
void setLeave(int k){
    work[k] = false;
    cnt[k]=0;
}
void TRY(int k){
    if (k>n) {
        if ((cnt[k-1] >= k1 && cnt[k-1] <= k2) || cnt[k-1] ==0){    
            printSolve();
        }
        return;
    }
    // check yesterday: work or leave?
    if (!(work[k-1])) {
        // if yesterday: leave, today: work
        setWork(k);
    }
    else{
        if (cnt[k-1] < k1)  setWork(k);
        if (cnt[k-1] >= k2)  setLeave(k); 
        if (cnt[k-1] >= k1 && cnt[k-1] < k2){
            setLeave(k);
            TRY(k+1);
            setWork(k);
            TRY(k+1);
            return;
        }
    }
    TRY(k+1);
}

int main(int argc, char const *argv[])
{
    cin >> n >> k1 >> k2;
    setLeave(1);
    TRY(2);
    setWork(1);
    TRY(2);
    return 0;
}