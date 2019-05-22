#include <stdio.h>
#define MAX 1000
int YoungSik(int n, int m, int l);

int main() {
	int N, M, L;
	//N : 자리 수, M : 게임을 끝내기 위해 공을 받는 횟수, L : 공을 넘기는 간격
	scanf("%d %d %d", &N, &M, &L);

	while (1) {
		if ((N >= 3 && N <= MAX) && //N은 3보다 크거나 같고, 1,000보다 작거나 같은 자연수
			(M > 0 && M <= MAX) &&	//M은 1,000보다 작거나 같은 자연수
			(L > 0 && L <= N - 1))	//L은 N-1보다 작거나 같은 자연수
		{
			printf("%d\n", YoungSik(N, M, L));	//함수에서 반환된 값을 출력
			break;//반복 종료
		}
		else //잘못된 값을 받았을 경우 다시 입력받는다.
			scanf("%d %d %d", &N, &M, &L);
	}
	return 0;
}

int YoungSik(int n, int m, int l) {
	int friends[MAX] = { 0 }; //friends[i]는 i번 자리에 사람이 공을받은 횟수
	int i = 0, count = 0; //count는 공을 던지는 총 횟수

	friends[i] =  1; //처음 i는 0이므로 0번째 자리에 사람이 공을받음

	while (1) {
		/*공을 받은 횟수가 짝수번이면 
		자기의 현재 위치에서 반시계 방향으로 
		L번째 있는 사람에게 공을 던진다.*/
		if (friends[i] % 2 != 0) {
			if (i + l > n - 1)
				i = (i + l) % n;
			else
				i = i + l;
		}
		/*공을 받은 횟수가 홀수번이면 
		자기의 현재 위치에서 시계 방향으로 
		L번째 있는 사람에게 공을 던진다.*/
		else {
			if (i - l < 0)
				i = (i - l) + n;
			else
				i = i - l;
		}
		
		friends[i] += 1; //공을 받았으므로 횟수 1 증가
		count++; //공을 던진 횟수 증가

		if (friends[i] == m) //공을 받은 사람의 공을 받은 횟수가 m일 경우
			break;//종료
	}

	return count;//공을 던진 총 횟수 반환
}