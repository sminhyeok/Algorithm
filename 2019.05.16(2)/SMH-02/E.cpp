#pragma warning (disable:4996)
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main() {
	
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		q.push(i);
	while (q.size() != 1) {
		printf("%d ", q.front());
		q.pop();
		q.push(q.front());
		q.pop();
	}
	printf("%d\n" , q.front());
	
}