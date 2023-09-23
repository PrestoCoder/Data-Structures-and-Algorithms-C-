#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Here, the maxLimit is the threshold beyond which no student can be allocated books.
// This ensures the max. limit given in the question.

// And using binary search we try to minimize this threshold.
bool allocateBooks(int* bookArr, int numBooks, int maxLimit, int numStudents) {
	int studentCount = 1;
	int currentBookCount = 0;
	int index = 0;
	while(index < numBooks && studentCount <= numStudents) {
		if(bookArr[index] + currentBookCount <= maxLimit) {
			currentBookCount += bookArr[index];
			index++;
		} else {
			currentBookCount = 0;
			studentCount += 1;
		}
	}
	if(studentCount > numStudents) {
		return false;
	} else {
		return true;
	}
}

int main() {
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) {

		int numBooks, numStudents;
		cin >> numBooks >> numStudents;

		int bookArr[numBooks];
		int min = 0;
		int max = 0;
		for(int i = 0; i < numBooks; i++) {
			cin >> bookArr[i];
			max += bookArr[i];
		}

		int start = 0, end = max, midLimit;
		int ans;
		while(start <= end) {
			midLimit = (start + end) / 2;
			bool canBooksBeAllocated = allocateBooks(bookArr, numBooks, midLimit, numStudents);
			// If books can be allocated, find an even lower max limit for books.
			if(canBooksBeAllocated) {
				ans = midLimit;
				end = midLimit - 1;
				continue;
			// If can't be allocated, thus, need to increase the min.
			} else {
				start = midLimit + 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}