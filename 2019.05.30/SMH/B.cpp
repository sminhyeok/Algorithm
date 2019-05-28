/*
	B
	���� 17177 �����簢��
	2019.05.25 13:58 ~ 
	�簢���� �� �������� ���� ���� �� ���� ����
	�� ������ �־����� ���� ���� �� ������ ������ ���� ����
	������ �� ������ ����
*/
#include <iostream>
using namespace std;
bool IN(int a, int b, int c);
int answer;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (!IN(a, b, c)) cout << "-1" << endl;
	else cout << answer << endl;
}

bool IN(int a, int b, int c) {
	/* 
		i�� �Էµ��� ���� ������ ��
		i�� ���� �� �ִ� ���� 3��
		�簢�� ����������Ÿ����
			AD 
			BC
		AB, AD, CD ��Ÿ�� �� ����
		�緹�� ���� -> AB*CD + AD*BC = AC*BD
		->  (AB*CD)^2 + 2(AB*CD*AD*BC) + (AD*BC)^2 = (AC*BD)^2
		AC^2 = (BC^2-AB^2), BD^2 = (BC^2-CD^2)
	*/
	int AB, AD, CD;			// �غ��� ������ ������ ��
	int AC2, BD2, BC = a;		// �밢���� �غ�
	for (int i = a - 1; i > 0; i--) {
		for (int j = 0; j < 6; j++) {
			if (j <= 1) {
				AB = i;
				if (j %2 == 0) { AD = b; CD = c; }
				else  { AD = c; CD = b; }
			}
			else if (j <= 3) {
				AD = i;
				if (j % 2 == 0) { AB = b; CD = c; }
				else { AB = c; CD = b; }
			}
			else if( j<=5 ){
				CD = i;
				if (j % 2 == 0) { AD = b; AB = c; }
				else { AD = c; AB = b; }
			}
			 AC2 = BC * BC - AB * AB;
			 BD2 = BC * BC - CD * CD;
			int cross = AC2 * BD2;
			int beside = (AB*CD)*(AB*CD) + 2 * (AB*CD*AD*BC) + (AD*BC) * (AD*BC);

			if (cross == beside) { answer = i; return true; }
		}
		
	}
	return false;
}

