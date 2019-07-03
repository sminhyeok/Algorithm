#include <iostream>
using namespace std;

int N, K, ANSWER;	// 행성의 수와 행성의 위치, 답
int MAP[10][10];
bool VISIT[10];

void init() {
	cin >> N >> K;
	ANSWER = 987654321;
	for (int i = 0; i < N; i++) VISIT[i] = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
	}
	VISIT[K] = true;
}

int min(int a, int b) { return a < b ? a : b; }
// 기존 x에서 y로 입력된 맵을 플로이드 워샬 알고리즘을 이용해 각 정점으로 향하는 최단거리를 구함
void FloydWarshall() {
	for(int k = 0; k < N; k++)
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				MAP[x][y] = min(MAP[x][y], MAP[x][k] + MAP[k][y]);
			}// x에서 y로 갈때 기존 값과, k경로를 거쳐서 이동하는 것중 짧은 거리를 구함
		}
}
// DFS를 이용해 모두 방문했을떄 최단거리를 구함 - 각 정점간 거리는 최단경로로 구성
void DFS(int T, int start, int dist) {
	if (T == N - 1) {
		if (ANSWER > dist) ANSWER = dist;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!VISIT[i]) {
			VISIT[i] = true;
			DFS(T + 1, i, dist + MAP[start][i]);
			VISIT[i] = false;
		}
	}
}

int main() {
	init();
	FloydWarshall();
	DFS(0, K, 0);
	cout << ANSWER << endl;
}