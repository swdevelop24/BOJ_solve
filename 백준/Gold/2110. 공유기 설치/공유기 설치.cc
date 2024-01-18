// stalls : (2<= n <=200,000)
// straight line: 1<= line(x) <= 1billion
// number of cows (2 <= c <=n)
// largest minimum distance? 

//1. sort
//2. given distance => possible not to be aggressive? 
//3. find the max of min dis through binary search  
//big O (nlogn(sort)+ nlogx) 

#include<iostream>
#include<algorithm>
using namespace std;

int n, c; 
int arr[200001];

int determine(int tar) {
	
	int last = arr[0]; 
	int cnt = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i] - last < tar) continue;
		last = arr[i]; 
		cnt++; 
	}
	return cnt >= c;

}

int bs(int s, int e) {

	int last = 0; 
	while (s <= e) {
		int mid = (s + e) / 2; 
		if (determine(mid)) {
			last = mid;
			s = mid + 1;
		}
		else
			e = mid - 1; 

	}
	return last; 
}

int main() {

	//freopen_s(new FILE*, "b.txt", "r", stdin);
	cin >> n >> c; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	sort(arr, arr + n); 
	int ret = bs(0, 1000000000); 

	cout << ret; 

	return 0;
}
