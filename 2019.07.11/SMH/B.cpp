#include <iostream>
#include <algorithm>
using namespace std;

struct EDGE { int X, Y, W; };

bool COMP(const EDGE &a, const EDGE &b) { return a.W > b.W; }// 가중치 기준 내림차순

EDGE E[99999];
int TREE[100001], N;	// 각 트리 노드의 부모를 나타냄, 트리의 개수, 정점 수
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
	if (COUNT[u] > COUNT[v]) swap(u, v);	// 항상 u가 더 작은 트리가 되게끔

	if (COUNT[u] == 1) { ANSWER += COUNT[v]  * w; COUNT[v]++; }	// 새로운 에지 하나만 트리에 삽입 될 때
	else { ANSWER += COUNT[v]  * COUNT[u] * w; COUNT[v] += COUNT[u];}	// 트리를 이룬 에지가 다른 트리에 삽입될 때
	TREE[u] = v;	// 트리 합치기(작은 트리가 큰 트리 아래로)
}

// 가중치로 내림차순된 에지들을 UNION 하면서 계산
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