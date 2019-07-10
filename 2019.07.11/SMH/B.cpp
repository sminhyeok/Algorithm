#include <iostream>
#include <algorithm>
using namespace std;

struct EDGE { int X, Y, W; };

bool COMP(const EDGE &a, const EDGE &b) { return a.W > b.W; }// ����ġ ���� ��������

EDGE E[99999];
int TREE[100001], N;	// �� Ʈ�� ����� �θ� ��Ÿ��, Ʈ���� ����, ���� ��
long long ANSWER, COUNT[100001];

void INIT() {
	ANSWER = 0;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> E[i].X >> E[i].Y >> E[i].W;
		TREE[i + 1] = i + 1;
		COUNT[i+1] = 1;
	}
	TREE[N - 1] = N - 1; COUNT[N - 1] = 1;
	TREE[N] = N; COUNT[N] = 1;
	sort(E, E + N, COMP);
}

int find(int u) {
	if (u == TREE[u]) return u;
	return TREE[u] = find(TREE[u]);
}

void UNION(int u, int v, long long w) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (COUNT[u] > COUNT[v]) swap(u, v);	// �׻� u�� �� ���� Ʈ���� �ǰԲ�

	if (COUNT[u] == 1) { ANSWER += COUNT[v]  * w; COUNT[v]++; }	// ���ο� ���� �ϳ��� Ʈ���� ���� �� ��
	else { ANSWER += COUNT[v]  * COUNT[u] * w; COUNT[v] += COUNT[u];}	// Ʈ���� �̷� ������ �ٸ� Ʈ���� ���Ե� ��
	TREE[u] = v;	// Ʈ�� ��ġ��(���� Ʈ���� ū Ʈ�� �Ʒ���)
}

// ����ġ�� ���������� �������� UNION �ϸ鼭 ���
void CALC() {
	for (int i = 0; i < N-1; i++) {
		int u, v, w;
		u = E[i].X;	v = E[i].Y; w = E[i].W;
		UNION(u, v, w);
	}
	cout << ANSWER << endl;
}

int main() {
	INIT();
	CALC();
}