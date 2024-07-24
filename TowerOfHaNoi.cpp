#include <iostream>
using namespace std;

void move (int, char, char, char);
int i = 0;

int main(){
    int disk;
    cin >> disk;
    move(disk, 'A', 'C', 'B');
    cout << "Total number of moves: " << i;
    return 0;
}
void move (int n, char start, char finish, char spare)
{
    if (n == 1){
        cout << "Move disk from: " <<  start << " to: " << finish << endl;
        i++;
        return;
    }
    move (n-1, start, spare, finish);
    move (1, start, finish, spare);
    move (n-1, spare, finish, start);
}