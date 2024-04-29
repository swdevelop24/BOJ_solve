#include<iostream>
#include<queue>
using namespace std;


int n, k; 
queue<int> q; 
 

int main() {

	cin >> n >> k; 

	int visited[100001] = { 0, }; 
	q.push(n); 
	visited[n] = 1; 


	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == k) break; 
		int next[3] = { now - 1, now + 1, now * 2 }; 
		for (int i = 0; i < 3; i++) {
			if (next[i] >= 0 && next[i] <= 100000) {
				if (visited[next[i]] == 0) {
					visited[next[i]] = visited[now] + 1;
					q.push(next[i]);
				}		
			}
		}

	}
		
	cout << visited[k] - 1; 


	return 0; 
}