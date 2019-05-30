/*
	C
	���� 17178 �ټ��� 
	2019-05-25 15:30 ~ 16:53
	5�� �� N��, ù ��° �� �� �ջ���� �̵� ����
	�� ����� �ܼ�Ʈ�� ���� �Ǵ� ��� �������� �ٽ� ���
	�� ���� ��� �̵� -> �� ���� ���� ��� �̵�
	��� ������ �� �ٷθ� �� �� ����. ������ ���� ������� ����
	��� ���������� �ٽ� �ٷ� ���ư��� ����
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Person {
	char name;	// ���ĺ�
	int num;	// ����
};
bool comp(const Person &a, const Person &b) {
	if (a.name < b.name) return true;
	else if (a.name == b.name) return a.num < b.num;
	else return false;
	
}
vector<Person> LINE[100], SORTED; // �Էµ� ������� �� ����, ���ĵ� �� ����
stack<Person> WAIT;					// ��⿭

int N, cursor; // ���� ��, ���� ���� Ȯ���� ���� ����

void init();					// ������ �Է�
bool simulation();				// �ùķ��̼� ����
void Enter();					// ��⿭ WAIT���� ���� ������ �ο� ó��

int main() {
	init();
	if (simulation()) cout << "GOOD\n";
	else cout << "BAD\n";
}

void init() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			Person temp;
			char n;
			int num;
			cin >> n; temp.name = n;
			cin >> n >> num; temp.num = num;
			LINE[i].push_back(temp);	// �� �� ���� �Է¹ޱ�
			SORTED.push_back(temp);		// �켱���� ������ ��� �Է¹ޱ�
		}
	}
	sort(SORTED.begin(), SORTED.end(), comp);
}

bool simulation() {
	cursor = 0;
	// �� �ٿ� 5�� ó��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			char name1, name2;
			int num1, num2;

			name1 = SORTED.at(cursor).name;
			name2 = LINE[i].at(j).name;
			num1 = SORTED.at(cursor).num;
			num2 = LINE[i].at(j).num;

			// ������ �� �ִ� �ο��� �ƴϸ� ��⿭��
			if (name1 != name2 || num1 != num2) WAIT.push(LINE[i].at(j));
			else { 
				cursor++;
				Enter();
			}
		}
	}
	Enter();
	if (WAIT.size() == 0) return true;
	else return false;
}

void Enter() {
	if (cursor >= N*5) return;
	char name1 = SORTED.at(cursor).name;
	int num1 = SORTED.at(cursor).num;

	while (WAIT.size() != 0 && name1 == WAIT.top().name && num1 == WAIT.top().num) {
		WAIT.pop();

		cursor++;
		if (cursor < N * 5) {
			name1 = SORTED.at(cursor).name;
			num1 = SORTED.at(cursor).num;
		}
		else return;
	}
}