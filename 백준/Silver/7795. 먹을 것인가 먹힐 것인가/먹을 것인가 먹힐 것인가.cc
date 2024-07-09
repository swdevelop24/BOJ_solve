#include<iostream>
#include<algorithm>
using namespace std;

int t;
int n, m;
int arr[42000];
int brr[42000];

int bs(int left, int right, int tar) {
	int ret = -1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (brr[mid] < tar) {
			ret = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ret+1;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen_s(new FILE*, "a.txt", "r", stdin); 
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		for (int x = 0; x < n; x++) {
			cin >> arr[x];
		}

		for (int y = 0; y < m; y++) {
			cin >> brr[y];
		}

	    sort(arr, arr + n);
		sort(brr, brr + m);

		int ans = 0;
		for (int s = 0; s < n; s++) {
	
			ans += bs(0, m-1, arr[s]);
		}

		cout << ans  << " ";
	}

	return 0;
}