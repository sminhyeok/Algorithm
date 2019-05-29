/*
	B
	백준 17177 내접사각형
	2019.05.25 13:58 ~ 
	사각형의 네 꼭짓점이 원과 접할 때 원에 내접
	세 선분이 주어지고 그중 가장 긴 선분이 내접할 원의 지름
	나머지 한 선분의 길이
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
		i는 입력되지 않은 나머지 변
		i가 가질 수 있는 변은 3곳
		사각형 꼭짓점을나타내면
			AD 
			BC
		AB, AD, CD 나타낼 수 있음
		톨레미 정리 -> AB*CD + AD*BC = AC*BD
		->  (AB*CD)^2 + 2(AB*CD*AD*BC) + (AD*BC)^2 = (AC*BD)^2
		AC^2 = (BC^2-AB^2), BD^2 = (BC^2-CD^2)
	*/
	int AB, AD, CD;			// 밑변을 제외한 나머지 변
	int AC2, BD2, BC = a;		// 대각선과 밑변
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

