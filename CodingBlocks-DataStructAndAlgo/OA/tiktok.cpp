#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> priorities;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        priorities.push_back(x);
    }

    int x, y;
    cin >> y >> x;

    sort(priorities.begin(), priorities.end());

    queue<int> q1;
    for(int i = 0; i < x; i++) {
        int size = priorities.size();
        if(size > 0) {
            q1.push(priorities[size - 1]);
            priorities.pop_back();
        } else {
            q1.push(-1);
        }
    }

    int sum = 0;
    for(int i = 0; i < y; i++) {
        int a = q1.front();
        cout << a << " ";
        if(a != -1) {
            sum += a;
        }
        q1.pop();
        q1.push(a);
    }

    cout << sum;

    return 0;
}
