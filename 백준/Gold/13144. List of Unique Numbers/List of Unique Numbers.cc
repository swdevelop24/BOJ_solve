#include<iostream>
using namespace std;

int n;
int arr[100001];
int dat[100001];
long long cnt;

int main() {
	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int right = 0;
	for (int left = 0; left < n; left++) {
		while (right < n && dat[arr[right]] < 1) {
			dat[arr[right]]++;
			right++;
		}
		cnt += right - left;
		dat[arr[left]]--;
	}

	cout << cnt;
	return 0;
}
