#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> packets(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> packets[i];
    }
    int max_frame;
    cin >> max_frame;

    int min_distortion = INT_MAX;
    for(int i = 0; i <= max_frame; i++) {
        
        int distortion = 0;
        int max_distortion = INT_MIN;
        for(int j = 0; j < n; j++) {
            if(j == 0) {
                distortion += abs(packets[0] == 0 ? i : packets[0] - packets[1] == 0 ? i : packets[1]);
                continue;
            }
            if(j == n - 1) {
                distortion += abs(packets[n - 2] == 0 ? i : packets[n - 2] - packets[n - 1] == 0 ? i : packets[n - 1]);
            }

            int d1 = abs(packets[j] == 0 ? i : packets[j] - packets[j - 1] == 0 ? i : packets[j - 1]);
            int d2 = abs(packets[j] == 0 ? i : packets[j] - packets[j + 1] == 0 ? i : packets[j + 1]);
            if(distortion > max_distortion) {
                max_distortion = distortion;
            }
        }
        if(max_distortion < min_distortion) {
            min_distortion = max_distortion;
        }
        
    }

    cout << min_distortion;
}