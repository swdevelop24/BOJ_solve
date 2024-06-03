#include<iostream>
#include<algorithm>
using namespace std;

int n; 
int arr[2001]; 
int ans;
int good; 

int isValid(int idx) {
	int left = 0;
	int right = n - 1; 
	int tar = arr[idx]; 
	while (left < right) {
		if (left == idx) left++;
		else if (right == idx) right--; 
		else {
			if (arr[left] + arr[right] == tar) return 1;
			else if (arr[left] + arr[right] > tar) right--;
			else left++; 
		}
	}

	return 0; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		ans = isValid(i); 
		if (ans) good++; 
	}

	cout << good; 

	return 0;
}

