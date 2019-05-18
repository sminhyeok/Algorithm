#include <iostream>
using namespace std;
int BALL;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int CUP[4] = {0,1,2,3 };
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		int temp = CUP[b];
		CUP[b] = CUP[a];
		CUP[a] = temp;
	}
	for (int i = 1; i <= 3; i++)
		if (CUP[i] == 1) cout << i << endl;
}