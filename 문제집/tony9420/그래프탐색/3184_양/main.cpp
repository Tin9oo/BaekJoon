#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define debug_input false
#define debug_prog false
#define debug_rst false

int R, C;
std::vector<std::string> field;
std::vector<std::vector<bool>> visit;

std::vector<int> dx = {0, 1, 0, -1};
std::vector<int> dy = {1, 0, -1, 0};

int TO = 0;
int TV = 0;

void get_input() {
    if(debug_prog) std::cout<< "get_input()" << std::endl;
    std::cin >> R >> C;
    field.resize(R);
    visit.assign(R, std::vector<bool>(C, false));
    for(int i = 0; i < R; ++i) {
        std::cin >> field[i];
    }

    if(debug_input) {
        std::cout << R << " " << C << std::endl;
        for(int i = 0; i < R; ++i) {
            std::cout << field[i] << std::endl;
        }
    }
}

void BFS(int x, int y) {
    if(debug_prog) std::cout<< "BFS()" << std::endl;

    int O, V;
    O = 0;
    V = 0;

    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(x, y));

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(field[x][y] == 'o') ++O;
        if(field[x][y] == 'v') ++V;

        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < R && ny < C) {
                if(field[nx][ny] != '#' && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    q.push(std::make_pair(nx, ny));
                }
            }
        }
    }

    if (O > V) TO += O;
    else TV += V;
}

void travel() {
    if(debug_prog) std::cout<< "travel()" << std::endl;

    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            if(visit[i][j] == false) {
                BFS(i, j);
            }
        }
    }

    std::cout << TO << " " << TV << std::endl;
}

void run() {
    if(debug_prog) std::cout<< "run()" << std::endl;
    get_input();
    travel();
}

int main() {
    std::ios:: sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    run();
    
    return 0;
}