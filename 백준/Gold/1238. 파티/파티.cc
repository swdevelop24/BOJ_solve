#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

struct Node {
	int n;
	int time; 
};

int n, m, x;
int ret[2][1001]; 
int ans; 

vector<vector<Node>> alist; 
vector<vector<Node>> backalist; 

int operator<(Node v, Node t) {
	return t.time < v.time; 
}

priority_queue<Node> pq; 

void dijkstra(vector<vector<Node>> &alist, int r) {

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (ret[r][now.n] > now.time) continue;

		for (Node next : alist[now.n]) {
			int total = next.time + now.time;
			if (ret[r][next.n] > total) {
				ret[r][next.n] = total;
				pq.push({ next.n, total });
			}
		}
	}
}

int main() {
	
	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> m >> x; 
	alist.resize(n+1);
	backalist.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int s, d, t; 
		cin >> s >> d >> t; 
		alist[s].push_back({ d,t }); 
		backalist[d].push_back({ s,t }); 
	}

	for (int i = 1; i <=n; i++) {
		ret[0][i] = 21e8; 
		ret[1][i] = 21e8;
	}
	ret[0][x] = 0;
	ret[1][x] = 0;

	pq.push({ x,0 });

	dijkstra(alist, 0);

	pq.push({ x,0 });
	
	dijkstra(backalist, 1);


	int ans = 0; 

	for (int i = 1; i <= n; i++) {
		if (ans < ret[0][i] + ret[1][i])
			ans = ret[0][i] + ret[1][i]; 
	}


	cout << ans; 

	return 0; 
}