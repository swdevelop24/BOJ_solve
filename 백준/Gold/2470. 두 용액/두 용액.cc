#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int arr[100005];

int main() {
	//freopen_s(new FILE*, "a.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);


	int left = 0;
	int right = n - 1;
	int minsum = 21e8;
	int ret1, ret2; 
	while (left < right) {
		if (abs(arr[left] + arr[right]) < minsum) {
			minsum = abs(arr[left] + arr[right]);
			ret1 = arr[left];
			ret2 = arr[right];
		}
		if (arr[left] + arr[right] > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	cout << ret1 << " " << ret2;


	return 0;
}