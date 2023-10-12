#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> grid;
int h, w;

void dfs(int x, int y) {
    // 범위를 벗어나면 종료
    if (x < 0 || x >= h || y < 0 || y >= w)
        return;
    
    // 현재 위치가 양인 경우, 방문 표시하고 주변을 탐색
    if (grid[x][y] == '#') {
        grid[x][y] = '.';
        dfs(x - 1, y);
        dfs(x + 1, y);
        dfs(x, y - 1);
        dfs(x, y + 1);
    }
}

int countSheepGroups() {
    int count = 0;
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                // 양 무리를 찾으면 카운트 증가하고 탐색 시작
                ++count;
                dfs(i, j);
            }
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> h >> w;
        grid.assign(h, vector<char>(w));
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
            }
        }
        
        int result = countSheepGroups();
        cout << result << endl;
    }
    
    return 0;
}