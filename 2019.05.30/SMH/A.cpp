/*
	A
	백준 17176 암호해독기
	2019-05-25 11:26 ~ 12:47 (1시간 21분)
	
	Index를 이용해 같은 문자가 동일 한 횟수 나왔는지 비교
*/
#pragma warning (disable:4996)
#include <iostream>
#include <string>
using namespace std;
int original[53];	// 원문 글자 정보
int sentence[53];	// 복원 글자 정보
int N; // 암호문 길이

void init();
int change(char n);
void solve();

int main() {
	init();
	solve();
}

// 입력과 동시에 변환
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 53; i++) {
		original[i] = 0;
		sentence[i] = 0;
	}

	int crypto; // 암호
	cin >> N; // 문자열 길이 입력

	// 암호화된 문장 입력받음
	for (int i = 0; i < N; i++) {
		cin >> crypto;
		sentence[crypto]++;
	}
	cin.ignore();

	string origin;
	getline(cin, origin);

	// 원문을 숫자로 변환하여 입력받음
	for (int i = 0; i < N; i++) 
		original[change(origin[i])]++;
	
}

int change(char n) {
	// a ~ z : 97 ~ 122
	// A ~ Z : 65 ~ 90
	if (n == ' ') return 0;
	else if (n <= 90) return n - 64;	 // A~Z : 1~26
	else return n - 70; // a~z : 27~52
}

// 해독
void solve() {
	for (int i = 0; i < 53; i++) {
		if (original[i] != sentence[i]) {
			cout << "n" << endl;
			return;
		}
	}
	cout << "y" << endl;
}