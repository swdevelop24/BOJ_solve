#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int n;
int arr[100001];
ll m;
int mindiff = 21e8;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int right = 0;
	int diff = 0;
	for (int left = 0; left < n; left++) {
		while (right < n && (abs(arr[right] - arr[left]) < m)) {
			right++;
		}
		if (right >= n) break; 
		if (abs(arr[right] - arr[left]) >= m) {
			mindiff = min(mindiff, abs(arr[right] - arr[left]));
		}
	}

	cout << mindiff;


	return 0;
}
