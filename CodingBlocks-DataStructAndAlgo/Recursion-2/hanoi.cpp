#include<iostream>
using namespace std;

void hanoi(int n, char source, char aux, char dest) {
    if(n == 0) {
        return;
    }
    hanoi(n - 1, source, dest, aux);
    cout << source << " " << dest << endl;
    hanoi(n - 1, aux, source, dest);
}

int main() {
    int n;
    cin >> n;
    hanoi(n, 'a', 'b', 'c');
}