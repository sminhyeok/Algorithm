#include <stdio.h>
#define MAX 1000

void card1(int n);

int main() {
	int num;

	scanf("%d", &num);

	while (1) {
		if (num >= 1 && num <= 1000) {
			card1(num);
			break;
		}
		else 
			scanf("%d", &num);
	}
	return 0;
}

void card1(int n) {
	int card[MAX], waste[MAX/2];
	int count = 0, k = 0, temp, i;

	for (int i = 0; i < n; i++) {
		card[i] = i + 1;
	}
	
	while (1) {
		if (count % 2 == 0) {
			waste[k] = card[0];
			k++;
			for (i = 0; i < n-1; i++) {
				card[i] = card[i + 1];
			}
			card[n-1] = 0;
			n--;
		}
		else {
			temp = card[0];
			for (i = 0; i < n - 1; i++) {
				card[i] = card[i + 1];
			}
			card[n-1] = temp;
		}

		if (card[1] == 0)
			break;

		count++;
	}

	for (i = 0; i < k; i++)
		printf("%d ", waste[i]);

	printf("%d\n", card[0]);
}

