
#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen_s(new FILE*, "a.txt", "r", stdin); 

	int n; 
	cin >> n; 

	for (int i = 0; i < n; i++) {
		int num; 
		cin >> num; 
		pq.push(num); 
	}

	for (int i = 1; i < n; i++) {
		for (int x = 0; x < n; x++) {
			int num; 
			cin >> num; 
			pq.push(num); 
			pq.pop(); 
		}
	}

	cout << pq.top(); 
	return 0; 
}