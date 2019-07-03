#include <iostream>
using namespace std;

class STICK {
private:
	int M, length, CUT[1001];	// �ڸ��� ������ ��, ������ ����,  �ڸ��� ����
public:
	void INIT() {
		cin >> M >> length;
		for (int i = 0; i < M; i++)
			cin >> CUT[i];
		CUT[M] = length;	// �� ������ �߶��� �� ���� ���̸� �˱����� ó�� ���̵� �߰�
		for (int i = M; i > 0; i--)
			CUT[i] -= CUT[i - 1];	// �ڸ� ���� ����
	}

	bool CUTTING(int Q, int MIN) {	// �ڸ� Ƚ�� Q, �ּ� ���� ����
		int EA = 0, NUM = 0;		// ������ ��, �ڸ� ������ ���� ���� ����
		for (int i = 0; i <= M; i++) {
			NUM += CUT[i];			// MIN���� ū ������ �ƴ϶�� ���ļ� ��
			if (NUM >= MIN) {
				EA++; NUM = 0;
			}
		}
		return EA >= Q + 1;			// ������ ���� �ڸ��� Ƚ������ 1�� Ŀ����
	}
	
	int ANSWER() {
		int Q, MID, LOW = 0, HIGH = length;
		cin >> Q;
		if (Q == 1 && M == 1) return CUT[0];	// ���� ó��

		while (HIGH - LOW > 1) {
			MID = (HIGH + LOW) / 2;
			if (CUTTING(Q, MID)) LOW = MID;	// �ڸ� �� ������ �� ū �� Ž��
			else HIGH = MID;				// �ڸ� �� ������ �� ���� �ּڰ� Ž��
		}
		return LOW;
	}
};

int main() {
	int N;
	cin >> N;
	STICK s;
	s.INIT();
	while (N--) {
		cout << s.ANSWER() << endl;
	}
}