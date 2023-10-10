#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> C;

int cnt = 0;

void print_grid() {
    for(int i = 0; i < C.size(); ++i) {
        for(int j = 0; j < C[0].size(); ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

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
    int j;
    for(int i = C.size()-1; i >= 0; --i) {
        j = i;
        if(C[i][j]) flip(i, j);
        for(j = i -1; j >= 0; --j) {
            if(C[i][j]) {
                flip(i, j);
            }
            if(C[j][i]) {
                flip(j, i);
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