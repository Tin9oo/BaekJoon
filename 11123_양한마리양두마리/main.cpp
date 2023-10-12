#include <iostream>
#include <queue>

using namespace std;

/*
    [문제 설명]
    양이 존재하는 들판이 그리드로 생성
    # -> 양, . -> 들판, ##...# -> 양의 무리

    양 무리가 몇개인지 출력
    
    [알고리즘]
    bfs

    [풀이]
    1. 입력 받음
    2. 2중 루프로 모든 지점 탐색하며 solve()함수 실행
    2-1. solve() 함수는 매 지점에서 인접한 #이 있는지 확인하고 인접하면 재귀함수 돌려서 또 인접한거 찾음
    2-2. 이미 방문한 지점은 visited 벡터로 관리해서 무리가 중복되어 측정되지않게 한다.
    3. 무리의 개수 반환

*/

int tc;
int m, n;

vector<string> field;
vector<vector<bool>> visited;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int cnt = 0;

void input() {
    cin >> m >> n;
    field.resize(m);
    for(int i = 0; i < m; ++i) {
        cin >> field[i];
    }
}

void init() {
    visited.assign(m, vector<bool> (n, false));

    cnt = 0;
}

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});

    visited[a][b] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < dx.size(); ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                if(!visited[nx][ny] && field[nx][ny] == '#') {
                    // cout << "check pos: " << nx << ", " << ny << endl;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

}

void solve() {
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(!visited[i][j] && field[i][j] == '#') {
                // cout << "check pos: " << i << ", " << j << endl;
                bfs(i, j);
                ++cnt;
                // cout << "======================================" << endl;
            }
        }
    }
}

int main() {
    cin >> tc;
    for(int i = 0; i < tc; ++i) {
        input();
        init();
        solve();
        cout << cnt << endl;
    }

    return 0;
}