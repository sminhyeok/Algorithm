#include <iostream>
#include <string>
#define MAX 99999
using namespace std;
int DP[301][301];
int N, M;
string A, B;

void init() {
	cin >> N >> M >> A >> B;
	
	for (int i = 1; i <= N; i++) DP[0][i] = MAX;
	for (int i = 1; i <= M; i++) DP[i][0] = MAX;
	DP[0][0] = 0;
}

int min3(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	else if (b <= a && b <= c) return b;
	else return c;
}

int ANSWER() {
	for(int y = 1; y <= M; y++)
		for (int x = 1; x <= N; x++) {
			DP[y][x] = abs(A[x - 1] - B[y - 1]);
			DP[y][x] += min3(DP[y - 1][x - 1], DP[y][x - 1], DP[y - 1][x]);
		}
	return DP[M][N];
}

int main() {
	init();
	cout << ANSWER() << endl;
}