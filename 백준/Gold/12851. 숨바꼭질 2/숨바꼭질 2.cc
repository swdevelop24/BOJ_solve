#include<iostream>
#include<queue>
using namespace std;


int n, k; 
queue<int> q; 
 

int main() {

	cin >> n >> k; 

	int visited[100001] = { 0, };
	int cnt[100001] = { 0, }; 
	q.push(n); 
	visited[n] = 1; 
	cnt[n] = 1; 


	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == k) break; 
		int next[3] = { now - 1, now + 1, now * 2 }; 
		for (int i = 0; i < 3; i++) {
			if (next[i] >= 0 && next[i] <= 100000) {
				if (visited[next[i]] == 0) {
					visited[next[i]] = visited[now] + 1;
					cnt[next[i]] = cnt[now]; 
					q.push(next[i]);
				}
				//재방문 했다면 거리 누적해줌
				else if (visited[next[i]] == visited[now] + 1) {
					cnt[next[i]] += cnt[now];
				}
			}
			
		}

	}
		
	cout << visited[k] - 1 <<"\n";
	cout << cnt[k]; 


	return 0; 
}