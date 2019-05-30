/*
	C
	백준 17178 줄서기 
	2019-05-25 15:30 ~ 16:53
	5명 씩 N줄, 첫 번째 줄 맨 앞사람만 이동 가능
	이 사람은 콘서트장 입장 또는 대기 공간에서 다시 대기
	한 줄의 사람 이동 -> 그 다음 줄의 사람 이동
	대기 공간은 한 줄로만 설 수 있음. 마지막 들어온 사람부터 나감
	대기 공간에서는 다시 줄로 돌아가지 못함
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct Person {
	char name;	// 알파벳
	int num;	// 숫자
};
bool comp(const Person &a, const Person &b) {
	if (a.name < b.name) return true;
	else if (a.name == b.name) return a.num < b.num;
	else return false;
	
}
vector<Person> LINE[100], SORTED; // 입력된 사람들의 줄 정보, 정렬된 줄 정보
stack<Person> WAIT;					// 대기열

int N, cursor; // 줄의 수, 입장 순서 확인을 위한 변수

void init();					// 데이터 입력
bool simulation();				// 시뮬레이션 진행
void Enter();					// 대기열 WAIT에서 입장 가능한 인원 처리

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
			LINE[i].push_back(temp);	// 줄 별 정보 입력받기
			SORTED.push_back(temp);		// 우선순위 정렬은 모두 입력받기
		}
	}
	sort(SORTED.begin(), SORTED.end(), comp);
}

bool simulation() {
	cursor = 0;
	// 한 줄에 5명씩 처리
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			char name1, name2;
			int num1, num2;

			name1 = SORTED.at(cursor).name;
			name2 = LINE[i].at(j).name;
			num1 = SORTED.at(cursor).num;
			num2 = LINE[i].at(j).num;

			// 입장할 수 있는 인원이 아니면 대기열로
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