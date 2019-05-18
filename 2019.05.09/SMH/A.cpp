#include <iostream>
using namespace std;

int main() {
	int A, B, C; // 트럭 한 대, 두 대, 세 대 주차했을때 요금
	int S[101] = { 0, }, F[101] = { 0, };	// 트럭 도착시간, 떠난 시간
	int COUNT = 0, MAX = 0, MIN = 101; // 트럭 주차 되어있는 수
	int SUM = 0;

	cin >> A >> B >> C;
	for (int i = 0; i < 3; i++) {
		int s, f;
		cin >> s >> f;
		if (s < MIN) MIN = s;
		if (f > MAX) MAX = f;
		S[s]++; F[f]++;
	}

	for (int t = MIN; t <= MAX; t++) {
		COUNT += S[t];
		COUNT -= F[t];
		
		if (COUNT == 1) SUM += COUNT * A;
		else if (COUNT == 2) SUM += COUNT * B;
		else if (COUNT == 3) SUM += COUNT * C;
	}
	cout << SUM << endl;
	
}
