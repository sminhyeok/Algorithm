#include <stdio.h>
int main()
{
	int i, a = 0, x, y, max = 0;
	for (i = 0; i<4; i++) {
		scanf("%d %d", &x, &y);
		a -= x;
		a += y;
		if (max<a) max = a;
	}
	printf("%d", max);
	return 0;
}