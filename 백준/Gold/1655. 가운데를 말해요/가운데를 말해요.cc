#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> big; 
priority_queue<int, vector<int>, less<int>> small; 

int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int num; 
		cin >> num; 
		//번갈아가면서 입력
		if (small.size() == big.size()) {
			small.push(num);
		}
		else
			big.push(num);

		
		if (!small.empty() && !big.empty()) {
			int s = small.top();
			int b = big.top();
			
			if (s > b) {
				small.pop();
				big.pop();
				small.push(b);
				big.push(s);
			}
		}

		cout << small.top() << "\n"; 
	}
	
	return 0; 
}