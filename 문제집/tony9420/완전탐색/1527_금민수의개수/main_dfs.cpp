#include <iostream>

using namespace std;

int A, B;
int cnt = 0;

void dfs(int num, int len) {
    // cout << "num: " << num << ", len: " << len << endl;
    if(len >= 10) return; // 오버플로우 방지, 이 라인 적기 싫으면 자료형 변경
    if(num > B) return;
    if(num >= A) ++cnt; // 최초에 작은 수도 생성 가능하게 예외 처리하는게 중요

    dfs(num*10 + 4, len+1);
    dfs(num*10 + 7, len+1);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> A >> B;

    dfs(0, 0);

    cout << cnt << endl;

    return 0;
}