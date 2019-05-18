#include <iostream>
using namespace std;

int main() {
	int IN, OUT;
	int PEOPLE = 0;
	int MAX = 0;

	for (int i = 0; i < 4; i++) {
		cin >> OUT >> IN;
		PEOPLE = PEOPLE - OUT + IN;
		if (MAX < PEOPLE) MAX = PEOPLE;
	}
	cout << MAX << endl;
}