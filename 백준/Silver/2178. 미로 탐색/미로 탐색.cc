#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int yp;
	int xp; 
};

int n, m; 
char arr[101][101]; 
int map[101][101]; 
int cnt[101][101];  
int dir[4][2] = { -1,0,1,0,0,-1,0,1 };
 
queue<Node> q; 

int main() {
	
	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> n >> m; 
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			cin >> arr[y][x];
			map[y][x] = arr[y][x] -'0';
		}
	}
	int visited[101][101] = { 0, }; 
	q.push({ 0,0 }); 
	visited[0][0] = 1; 
	cnt[0][0] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		if (now.yp == n - 1 && now.xp == m - 1) break;
		

		for (int i = 0; i < 4; i++) {
			int ny = now.yp + dir[i][0];
			int nx = now.xp + dir[i][1];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue; 
			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx] == 1) continue; 
			visited[ny][nx] = 1; 
			q.push({ ny, nx }); 
			cnt[ny][nx] = cnt[now.yp][now.xp] +1; 
		}
		
	}
	
	cout << cnt[n-1][m-1];
	
	return 0; 
}