#include <iostream>
using namespace std;

class STICK {
private:
	int M, length, CUT[1001];	// 자르는 지점의 수, 막대의 길이,  자르는 지점
public:
	void INIT() {
		cin >> M >> length;
		for (int i = 0; i < M; i++)
			cin >> CUT[i];
		CUT[M] = length;	// 각 지점을 잘랐을 때 남는 길이를 알기위해 처음 길이도 추가
		for (int i = M; i > 0; i--)
			CUT[i] -= CUT[i - 1];	// 자른 길이 저장
	}

	bool CUTTING(int Q, int MIN) {	// 자를 횟수 Q, 최소 길이 가정
		int EA = 0, NUM = 0;		// 조각의 수, 자른 막대의 길이 저장 변수
		for (int i = 0; i <= M; i++) {
			NUM += CUT[i];			// MIN보다 큰 조각이 아니라면 합쳐서 비교
			if (NUM >= MIN) {
				EA++; NUM = 0;
			}
		}
		return EA >= Q + 1;			// 조각의 수는 자르는 횟수보다 1더 커야함
	}
	
	int ANSWER() {
		int Q, MID, LOW = 0, HIGH = length;
		cin >> Q;
		if (Q == 1 && M == 1) return CUT[0];	// 예외 처리

		while (HIGH - LOW > 1) {
			MID = (HIGH + LOW) / 2;
			if (CUTTING(Q, MID)) LOW = MID;	// 자를 수 있을때 더 큰 값 탐색
			else HIGH = MID;				// 자를 수 없을때 더 작은 최솟값 탐색
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