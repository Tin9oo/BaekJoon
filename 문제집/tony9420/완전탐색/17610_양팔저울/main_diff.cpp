#include <iostream>
#include <vector>

using namespace std;

/*
    [문제]
    ㅁ에 물의 무게 X가 할당된다.
    현재 보유한 추와 ㅁ의 조합으로 양팔저울이 평행해지지 않는 경우의 수를 구하라.

    [풀이]
    추 무게의 합인 S를 구하고 S까지 반복하는 루프를 만든다.
    used 벡터로 ㅁ과 같은 저울에 담길 추를 구분한다.
*/

int k;
vector<int> G;
int S = 0;

vector<vector<bool>> visited;

int cnt = 0;

void dfs(int idx, int cur_w) {
    if(idx > k) return;
    visited[idx][cur_w] = true;
    
    dfs(idx + 1, cur_w + G[idx]);
    dfs(idx + 1, abs(cur_w - G[idx]));
    dfs(idx + 1, cur_w);
}

int main() {
    cin >> k;

    G.resize(k, 0);
    for(int i = 0; i < k; ++i) {
        cin >> G[i];
        S += G[i];
    }
    visited.resize(k+1, vector<bool>(S+1, false));

    dfs(0, 0);

    for(int s = 1; s <= S; ++s) {
        if(!visited[k][s]) ++cnt;
    }

    cout << cnt << endl;

    return 0;
}