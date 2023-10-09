#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define debug_input false
#define debug_fn false
#define debug_map false
#define debug_log false

int test_case = 0;
int board_length;
pair<int, int> stt;
pair<int, int> dst;

vector<vector<int>> board;

vector<int> dx = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> dy = {1, -1, 1, -1, 2, 2, -2, -2};

int min_cnt = INT_MAX;

void get_input() {
    if(debug_fn) cout << "get_input()" << endl;

    int x, y;

    cin >> board_length;

    cin >> x >> y;
    stt = make_pair(x, y);
    cin >> x >> y;
    dst = make_pair(x, y);

    if(debug_input) {
        cout << endl << "Board length: " << board_length << endl;
        cout << "Start pos: " << stt.first << " " << stt.second << endl;
        cout << "Destination pos: " << dst.first << " " << dst.second << endl;
        cout << "==================================================" << endl;
    }
}

void init() {
    if(debug_fn) cout << "init()" << endl;

    board = vector<vector<int>> (board_length, vector<int>(board_length, INT_MAX));
    
    board[stt.first][stt.second] = 0;

    min_cnt = INT_MAX;
}

void BFS(int x, int y) {
    if(debug_fn) cout << "DFS(" << "x = " << x << ", y = " << y << ")" << endl;

    queue<pair<int, int>> q;
    q.push({x, y});

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        q.pop();        

        for(int i = 0; i < dx.size(); ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < board_length && ny < board_length) {
                if(board[x][y] + 1 < board[nx][ny]) {
                    board[nx][ny] = board[x][y] + 1;

                    q.push({nx, ny});

                    if(nx==dst.first && ny==dst.second) {
                        if(min_cnt > board[nx][ny]) {
                            min_cnt = board[nx][ny];
                            if(debug_log) cout << "New Minimum Count: " << min_cnt << endl;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    if(debug_fn) cout << "main()" << endl;

    cin >> test_case;

    for(int i = 0; i < test_case; ++i) {
        get_input();

        if(stt.first==dst.first && stt.second == dst.second) {
            cout << 0 << endl;
            continue;
        }

        init();
        BFS(stt.first, stt.second);

        cout << min_cnt << endl;
    }

    return 0;
}