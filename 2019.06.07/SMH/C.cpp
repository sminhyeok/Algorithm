#include <iostream>
using namespace std;

int N, K, ANSWER;	// �༺�� ���� �༺�� ��ġ, ��
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
// ���� x���� y�� �Էµ� ���� �÷��̵� ���� �˰����� �̿��� �� �������� ���ϴ� �ִܰŸ��� ����
void FloydWarshall() {
	for(int k = 0; k < N; k++)
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				MAP[x][y] = min(MAP[x][y], MAP[x][k] + MAP[k][y]);
			}// x���� y�� ���� ���� ����, k��θ� ���ļ� �̵��ϴ� ���� ª�� �Ÿ��� ����
		}
}
// DFS�� �̿��� ��� �湮������ �ִܰŸ��� ���� - �� ������ �Ÿ��� �ִܰ�η� ����
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