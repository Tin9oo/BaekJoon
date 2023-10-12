#include <iostream>
#include <vector>

using namespace std;

/*
    [문제]

    [풀이]
    시간 초과 발생 -> dp를 통해 시간 단축

    누적합으로 dp를 만들어 놓으면 계산 값에서 앞의 값을 빼서 범위의 값을 구할 수 있다.
    cum_area[i][j] = P[i][j] + cum_area[i-1][j] + cum_area[i][j-1] - cum_area[i-1][j-1]
    가장자리에서 인덱스 초과가 발생한다. 완충지대로 0인덱스 대역에서 0만 할당해놓으면 문제없이 동작할 것이다.
    sum = cum_area[x2][y2] - cum_area[x1-1][y2] - cum_area[x2][y1-1] + cum_area[x1-1][y1-1]
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> P(N+1, vector<int>(M+1, 0));
    vector<vector<int>> cum_area(N+1, vector<int>(M+1, 0));
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= M; ++j) {
            cin >> P[i][j];
            cum_area[i][j] = P[i][j] + cum_area[i-1][j] + cum_area[i][j-1] - cum_area[i-1][j-1];
        }
    }

    int K;
    cin >> K;

    int x1, y1, x2, y2;
    int sum;
    while(K--) {
        cin >> x1 >> y1 >> x2 >> y2;

        sum = cum_area[x2][y2] - cum_area[x1-1][y2] - cum_area[x2][y1-1] + cum_area[x1-1][y1-1];

        cout << sum << "\n"; // endl 바꾸니까 해결되네
    }
    
    return 0;
}