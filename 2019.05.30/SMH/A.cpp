/*
	A
	���� 17176 ��ȣ�ص���
	2019-05-25 11:26 ~ 12:47 (1�ð� 21��)
	
	Index�� �̿��� ���� ���ڰ� ���� �� Ƚ�� ���Դ��� ��
*/
#pragma warning (disable:4996)
#include <iostream>
#include <string>
using namespace std;
int original[53];	// ���� ���� ����
int sentence[53];	// ���� ���� ����
int N; // ��ȣ�� ����

void init();
int change(char n);
void solve();

int main() {
	init();
	solve();
}

// �Է°� ���ÿ� ��ȯ
void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 53; i++) {
		original[i] = 0;
		sentence[i] = 0;
	}

	int crypto; // ��ȣ
	cin >> N; // ���ڿ� ���� �Է�

	// ��ȣȭ�� ���� �Է¹���
	for (int i = 0; i < N; i++) {
		cin >> crypto;
		sentence[crypto]++;
	}
	cin.ignore();

	string origin;
	getline(cin, origin);

	// ������ ���ڷ� ��ȯ�Ͽ� �Է¹���
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

// �ص�
void solve() {
	for (int i = 0; i < 53; i++) {
		if (original[i] != sentence[i]) {
			cout << "n" << endl;
			return;
		}
	}
	cout << "y" << endl;
}