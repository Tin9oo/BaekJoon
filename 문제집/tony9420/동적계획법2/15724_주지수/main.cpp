#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    [문제]

    [풀이]
    시간 초과 발생 -> dp를 통해 시간 단축

    누적합으로 dp를 만들어 놓으면 계산 값에서 앞의 값을 빼서 범위의 값을 구할 수 있다.
    
*/

struct area_log
{
    int x1;
    int y1;
    int x2;
    int y2;

    int sum;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> P(N, vector<int>(M, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> P[i][j];
        }
    }

    int K;
    cin >> K;

    vector<int> area(4, 0);
    vector<area_log> al;

    for(int tc = 0; tc < K; ++tc) {
        for(int i = 0; i < 4; ++i) {
            cin >> area[i];
        }

        bool flag = false;
        for(int i = 0; i < al.size(); ++i) {
            if(al[i].x1==area[0] && al[i].y1==area[2] && al[i].x2==area[1] && al[i].y2==area[3]) {
                // cout << "Use DP" << endl;
                cout << al[i].sum << endl;
                flag=true;
                break;
            }
        }
        if(flag) continue;
        
        int sum = 0;
        for(int i = area[0]-1; i < area[2]; ++i) {
            for(int j = area[1]-1; j < area[3]; ++j) {
                sum += P[i][j];
            }
        }

        // if(al[i].x1==area[0] && al[i].y1==area[2] && al[i].x2==area[1] && al[i].y2==area[3]) {
        //     cout << al[i].sum << endl;
        //     flag=true;
        //     break;
        // }

        area_log tmp;
        tmp.x1=area[0];
        tmp.y1=area[2];
        tmp.x2=area[1];
        tmp.y2=area[3];
        tmp.sum=sum;
        al.push_back(tmp);

        // cout << "area log length: " << al.size() << endl;

        cout << sum << endl;
    }
    
    return 0;
}