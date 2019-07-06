#include <iostream>
#include <vector>
#include <algorithm>
#define Y first
#define X second
using namespace std;

const long long MOD = 1e9 + 7;
const int MAX = 200001;
const int FULL = 400001;

pair<int, int> STAR[MAX];
long long TREE[FULL + 1];
int N;

bool COMP(const pair<int, int> &a, const pair<int, int> & b) {
	if (a.Y < b.Y) return true;
	else if (a.Y == b.Y) return a.X < b.X;
	else return false;
}

void UPDATE(int i, int num) {
	while (i <= FULL) {
		TREE[i] += num;
		i += (i & -i);
	}
}

int SUM(int i) {
	long long result = 0;
	while (i > 0) {
		result += TREE[i];
		i -= (i & -i);
	}
	return result;
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> STAR[i].X >> STAR[i].Y;
		UPDATE(STAR[i].X + MAX, 1);
	}
	sort(STAR, STAR + N, COMP);
}

long long COUNT() {
	long long ANSWER = 0;
	int y = -MAX;

	for (int i = 0; i < N; i++) {
		if (y != STAR[i].Y) {
			y = STAR[i].Y;
			for (int j = i; STAR[j].Y == y; j++)
				UPDATE(STAR[j].X + MAX, -1);
		}

		int x = STAR[i].X + MAX;
		long long left = SUM(x - 1) % MOD;
		long long right = (SUM(FULL) - SUM(x)) % MOD;
		ANSWER += (left * right) % MOD;
		ANSWER %= MOD;
	}
	return ANSWER;
}

int main() {
	init();
	cout << COUNT() << endl;
}