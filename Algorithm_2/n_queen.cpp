#include <iostream>
using namespace std;
#define MAX 15

int col[MAX];
int Target, total = 0;

/*
bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] == col[level] || abs(col[level] - col[i]) == abs(level - i)) {
		//대각선이거나 같은 라인
			return false; //3
		//col[i]가 의미하는 것이 x좌표, i가 의미하는것이 y좌표이므로  
		//차이가 일정하다면 대각선에 있다고 볼 수 있다.
		}
	}
	return true; //2
}*/

bool check(int level) {
	for (int i = 0; i < level; i++) {
		if (col[i] != col[level] && abs(col[level] - col[i]) != abs(level - i)) {
		//대각선이 아니고 같은 라인이 아니면 계속 탐색 
			continue;
		//col[i]가 의미하는 것이 x좌표, i가 의미하는것이 y좌표이므로  
		//차이가 일정하다면 대각선에 있다고 볼 수 있다.
		}
		else if(col[i] == col[level] || abs(col[level] - col[i]) == abs(level - i)){
			return false;
		}
	}
	return true; 
}


void nqueen(int x) {
	for (int j = 0; j < Target; j++){
		if (x == Target) {
			//total++;

			//중간 출력
			for(int i=0;i<Target;i++){
				cout<<col[i]+1<<" ";
			}cout<<endl;
			break;
		}
		
		else{
			col[x] = j;  //해당 위치에 퀸을 배치
			if (check(x)) {
				//유효하다면 다음행의 퀸 배치, 유효하지 않다면 다른 위치로 퀸 배치 변경
				nqueen(x + 1);	
			}
		}
	}
}

int main() {
	//cin >> N;
	Target=4;
	nqueen(0);
	//cout << total << endl;
}

