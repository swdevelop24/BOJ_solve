#include<iostream>
typedef long long ll;
using namespace std;

int n;
ll m;

int arr[1000001];

int isPossible(int target) {

	ll sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > target) {
			sum += arr[i] - target;
		}
	}

	return (sum >= m);
	
}
int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll start = 0;
	ll end = 2e9;
	ll ret = 0;
	while (start <= end) {
		ll mid = (start + end) / 2;
		if (isPossible(mid)) {
			ret = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << ret;
	return 0;
}