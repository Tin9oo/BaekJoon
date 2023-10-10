#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> C;

int cnt = 0;

// void print_grid() {
//     for(int i = 0; i < C.size(); ++i) {
//         for(int j = 0; j < C[0].size(); ++j) {
//             cout << C[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

void flip(int a, int b) {
    for(int i = 0; i <= a; ++i) {
        for(int j = 0; j <= b; ++j) {
            C[i][j] = 1 - C[i][j];
        }
    }
    // print_grid();

    ++cnt;
}

void solve() {
    // 매 반복에서 최선의 선택이기 때문에 순차적으로 위로 올라가면 된다.
    // 내가 기존 구현한 방식: 지점에서 왼쪽으로 쭉, 위로 쭉 올려서 몰아가는 방식 -> 메모리 소모 큼
    for(int i = N - 1; i >= 0; --i) {
        for(int j = M - 1; j >= 0; --j) {
            if(C[i][j]) {
                flip(i, j);
            }
        }
    }
}

int main() {
    cin >> N >> M;

    C.resize(N, vector<int>(M));

    string row;
    for(int i = 0; i < N; ++i) {
        cin >> row;
        for(int j = 0; j < M; ++j) {
            C[i][j] = row[j]-'0';
        }
    }

    solve();

    cout << cnt << endl;

    return 0;
}