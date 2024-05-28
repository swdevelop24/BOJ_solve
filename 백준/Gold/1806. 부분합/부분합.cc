#include<iostream>
#include<cmath>
using namespace std;

int n;
int S;
int ret; 
int arr[100001]; 


int main() {
	
	cin >> n;
	cin >> S; 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; 
	}

	int right = 0;
	int sum = 0; 
	ret = n + 1; 
	for (int left = 1; left <= n; left++) {
		sum -= arr[left - 1]; 
		while (sum < S &&  right+1<=n) {
			right++;
			sum += arr[right]; 
		}
		if (sum >= S) {
			ret = min(ret, right-left+ 1); 
		}
	}

	if (ret == n + 1) {
		cout << 0;
	}
	else
		cout << ret;
	

	return 0; 
}