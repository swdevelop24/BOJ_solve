//3: test case
//8 : board size
//0 0 : current position 1
//7 0 : destination 1
//100: board size
//0 0: cur 2
//30 50: des 2
//10 : board size
//1 1 : cur 3
//1 1: des 3
//둘째 줄과 셋째 줄에는 
// 나이트가 현재 있는 칸, 
// 나이트가 이동하려고 하는 칸

//출력: 최소 몇 번만에 이동할 수 있는지 
// 5
//28
//0
#include<iostream>
#include<queue>
using namespace std;

int diry[8] = { -2,-1,1,2,2,1,-1,-2 };
int dirx[8] = { 1,2,2,1,-1,-2,-2,-1 };

int t;
int n;
int board[301][301] = { 0, };

struct Node {
	int yp;
	int xp;
};

void bfs(int sy, int sx, int dy, int dx) {
	queue<Node> q;
	int visited[301][301] = { 0 }; 
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if ((now.yp == dy) && (now.xp == dx)) {
			break;
		}
		for (int i = 0; i < 8; i++) {
			int ny = now.yp + diry[i];
			int nx = now.xp + dirx[i];

			if (ny < 0 || nx < 0 || nx >= n || ny >= n) continue;
			if (visited[ny][nx] == 0) {
				visited[ny][nx] = visited[now.yp][now.xp] + 1;
				q.push({ ny, nx });
			}
		}
	}
	cout << visited[dy][dx] - 1 << "\n";
}

 
int main() {

	//freopen_s(new FILE*, "a.txt", "r", stdin);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		int starty, startx, endy, endx;
		cin >> starty >> startx >> endy >> endx;
		bfs(starty, startx, endy, endx);
	}

	return 0;
}

