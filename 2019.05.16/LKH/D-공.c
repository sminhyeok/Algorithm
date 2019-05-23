#include <stdio.h>
void ball(int c);

int main() {
	int count;

	scanf("%d", &count);//컵의 위치를 바꾼 횟수를 입력받는다.

	while (1) {
		if (count <= 50 && count > 0) {//count를 50보다 작거나 같은 자연수로 받았을 때
			ball(count);//ball에 count를 넣어주고
			break;//반복문을 종료한다.
		}
		else//count를 그 외의 숫자로 받았을 경우
			scanf("%d", &count);//다시 입력받는다.
	}
	return 0;
}

void ball(int c)
{
	int ball = 1;
	int cup1, cup2, temp, i;
	int cup[3] = { 0 };

	cup[0] = ball;//첫번째 컵에 공을 넣어둔다.

	while(c > 0) {//c가 0보다 클동안 반복한다.
		scanf("%d %d", &cup1, &cup2);
		if ((cup1 <= 3 && cup1 > 0) && (cup2 <= 3 && cup2 > 0)) 
		{	//컵 교환
			temp = cup[cup1-1];
			cup[cup1-1] = cup[cup2-1];
			cup[cup2-1] = temp;
			c--;//제대로 입력받았을 경우에 c의 값을 감소시킨다.
		}
	}

	for (i = 0; i < 3; i++) {
		if (cup[i] == 1)//컵에 공이 들어있을 경우
			printf("%d\n", i+1);//몇번 컵인지 출력한다.
		if(i == 3 && cup[i] != 1)//모든 컵에 공이 없을 경우
			printf("%d\n", -1);//-1을 출력한다.
	}
}

