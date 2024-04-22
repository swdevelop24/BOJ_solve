#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
	int num, price;
};

int n, m;
vector <int> ret;
vector<int> visited; 

bool operator<(Node v, Node t) {
	return t.price < v.price;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<Node>> alist(n + 1);

	ret.resize(n+1);
	visited.resize(n + 1); 
	for (int i = 1; i <= n; i++) {
		ret[i] = 21e8;
	}


	for (int i = 0; i < m; i++) {
		int from, to, p;
		cin >> from >> to >> p;
		alist[from].push_back({ to,p });
	}

	int sp, dp;
	cin >> sp >> dp;
	priority_queue<Node> q;

	q.push({ sp,0 });
	ret[sp] = 0;
	

	while (!q.empty()) {
		Node now = q.top();
		q.pop();


		if (!visited[now.num]) {
			visited[now.num] = 1; 
			if (ret[now.num] < now.price) continue;

			for (int i = 0; i < alist[now.num].size(); i++) {
				Node next = alist[now.num][i];
				int total = now.price + next.price;
				if (ret[next.num] < total) continue;
				ret[next.num] = total;
				q.push({ next.num, total });

			}
		}
		
	}

	cout << ret[dp];

	return 0;
}


