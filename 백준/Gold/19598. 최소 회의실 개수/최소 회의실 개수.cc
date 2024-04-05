#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	int st;
	int et; 
};

int operator<(Node t, Node v) {
	return t.et > v.et; 
}

int compare(Node t, Node v) {
	return t.st < v.st; 
}

priority_queue<Node> pq; 
Node meeting[100000]; 

int main() {

	ios_base::sync_with_stdio(NULL); 
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "a.txt", "r", stdin);

	int n; 
	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> meeting[i].st >> meeting[i].et; 
	}

	sort(&meeting[0], &meeting[n], compare); 

	int ret = 0; 

	for (int i = 0; i < n; i++) {
		cin >> meeting[i].st >> meeting[i].et;
	}

	for (int i = 0; i < n; i++) {
		while (!pq.empty() && pq.top().et <= meeting[i].st) {
			pq.pop(); 
		}
		pq.push(meeting[i]); 
		if (pq.size() > ret) {
			ret = pq.size(); 
		}
	}
	cout << ret; 
	return 0;
}