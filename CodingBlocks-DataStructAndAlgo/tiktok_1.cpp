#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main() {
    vector<string> words;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.__emplace_back(word);
    }
    // All words same length
    int wordLength = words[0].length();
    int numOfWords = n;
    string ans(wordLength, 'a');
    int k = 0, r = wordLength - 1;
    while(k <= r) {
        int minScore = INT_MAX;
        
        for(int j = 0; j < 26; j++) {
            int kthLetterScore = 0;
            char currChar = j + 'a';
            
            // Summing difference of currChar with every kth char of all n words.
            for(int i = 0; i < numOfWords; i++) {
                int score1 = abs(words[i][k] - currChar);
                int score2 = abs(words[i][r] - currChar);
                kthLetterScore += (score1 + score2);
            }

            // For the very first letter, nothing to compare to.
            if(j == 0) {
                ans[k] = currChar;
                ans[r] = currChar;
                minScore = kthLetterScore;
                continue;
            }
            // Check abs score
            if(kthLetterScore < minScore) {
                ans[k] = currChar;
                ans[r] = currChar;
                minScore = kthLetterScore;
            // If score equal, checking lexography
            } else if(kthLetterScore == minScore) {
                if(currChar < ans[k]) {
                    ans[k] = currChar;
                    ans[r] = currChar;
                }
            }
        }
        k++;
        r--;
    }

    cout << ans;
}