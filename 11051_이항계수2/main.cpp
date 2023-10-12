#include <iostream>
#include <vector>

using namespace std;

/*
    [문제]
    이항계수 (N K) 를 10,007로 나눈 나머지를 구하시오.

    [풀이]
    1. 파스칼 삼각형으로 2차원 벡터에 저장한다. (DP)
    2. 10,007로 나눈다. (근데 뭔가 문제가 있었던거같다.)

*/

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> pt(N+1, vector<int>(K+1,1));

    for(int i = 2; i <= N; ++i) {
        for(int j = 1; j < min(i, K+1); ++j) { // i가 K보다 크면 인덱스 초과
            pt[i][j] = ((pt[i-1][j-1] % 10007) + (pt[i-1][j] % 10007)) % 10007; // 나누는 숫자 제대로 적을것.
        }
    }
    
    // for(int i = 0; i < pt.size(); ++i) {
    //     for(int j = 0; j < pt[0].size(); ++j) {
    //         cout << pt[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << pt[N][K] << endl;

    return 0;
}