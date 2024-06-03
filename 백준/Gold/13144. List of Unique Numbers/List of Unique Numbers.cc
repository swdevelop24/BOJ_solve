#include<iostream>
using namespace std;

int n;
int arr[100001]; 
int cnt; 
int dat[100001]; 
long long ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen_s(new FILE*, "a.txt", "r", stdin);

	cin >> n; 
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int right = -1;
	for (int left = 0; left < n; left++) {
		while ((dat[arr[right+1]] == 0) && right+1 <n) {
			dat[arr[right+1]]++;
			right++;
		}
		ans += right - left + 1; 
		dat[arr[left]]--; 

	}

	cout << ans; 
	return 0;
}
