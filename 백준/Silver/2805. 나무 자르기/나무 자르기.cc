//constraints:
//n = 1million (n: # of trees)
//m = 2billion (required wood amount) 
// tree hightest hight : 1 billion 
//worst case(when saw height is 1billion)
//  1million * 1billion = 10^6 * 10^9 = 10^15  
// =>  larger than 21e8 => long 

#include<iostream>
using namespace std;

int n;
int m; 
int arr[1000001]; 

int isPossible(int tar) {

	long long sum = 0; 
	for (int i = 0; i < n; i++) {
		if (arr[i] > tar) {
			sum += arr[i] - tar; 
		}
	}

	return sum >= m;

}

int bs(int s, int e) {
	int last = 0; 
	while (s <= e) {
		int mid = (s + e) / 2; 
		if (isPossible(mid)) {
			last = mid;
			s = mid + 1;
		}
		else
			e = mid - 1; 
	}
	return last;
}
int main() {

	cin >> n >> m; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int ret = bs(0, 2000000000); 
	cout << ret; 


	return 0; 
}