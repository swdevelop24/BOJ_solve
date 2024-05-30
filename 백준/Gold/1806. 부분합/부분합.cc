#include<iostream>
using namespace std;

int main() {
	//freopen_s(new FILE*, "a.txt", "r", stdin);

	int n, s; 
	cin >> n >> s;

	int arr[100001] = { 0 }; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int sum = arr[0];
	int cnt = 0; 
	int mincnt = n + 1; 

	int left = 0;
	int right = 0; 

	for (left = 0; left < n; left++) {
		while (right < n && sum < s) {
			right++;
			sum += arr[right]; 
		}
		if (sum >= s) {
			mincnt = min(mincnt, right - left +1); 
		}
		sum -= arr[left]; 
	}

	if (mincnt == n + 1) cout << 0;
	else cout << mincnt;

	return 0;
}