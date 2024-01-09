// N positive integers (10 ¡Â N < 100 000), 
// each of them less than or equal 10000
// S ¡Â 100 000 000
// goal : minimum length of subsequence, where sumbsum >= S


//BigO O(N) 
//data type: Integer (worst case: 10^4 * 10^5 = 10^9) 

// N positive integers (10 ¡Â N < 100 000), 
// each of them less than or equal 10000
// S ¡Â 100 000 000
// goal : minimum length of subsequence, where sumbsum >= S


//BigO O(N) 
//data type: Integer (worst case: 10^4 * 10^5 = 10^9) 

// N positive integers (10 ¡Â N < 100 000), 
// each of them less than or equal 10000
// S ¡Â 100 000 000
// goal : minimum length of subsequence, where sumbsum >= S


//BigO O(N) 
//data type: Integer (worst case: 10^4 * 10^5 = 10^9) 

// N positive integers (10 ¡Â N < 100 000), 
// each of them less than or equal 10000
// S ¡Â 100 000 000
// goal : minimum length of subsequence, where sumbsum >= S


//BigO O(N) 
//data type: Integer (worst case: 10^4 * 10^5 = 10^9) 

#include<iostream>
#include<algorithm>
using namespace std;

int n, s, ans;
int arr[100000];
int mini = 21e8;
int main() {


	freopen_s(new FILE*, "b.txt", "r", stdin);
	cin >> n >> s;
	ans = n + 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int subsum = 0;
	int flag = 0;

	for (int t = left; t < n; t++) {
		while (subsum < s && right < n) {
			subsum += arr[right];
			right++;
		}
		if (subsum >= s)
			ans = min(ans, right - left);
		subsum -= arr[left];
		left++;
	}

	if (ans == n + 1) ans = 0;
	cout << ans;

	return 0;
}