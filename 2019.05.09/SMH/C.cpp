#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int X, STICK = 64, ANSWER = 1;
	cin >> X;
	int temp = STICK;
	while (1) {
		if (temp > X) { 
			STICK /= 2; 
			if (temp - STICK >= X) temp -= STICK;
			else ANSWER++;
		}
		else if (temp == X) break;
	}
	cout << ANSWER << endl;
}

