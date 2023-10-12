#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/*
    [문제]
    나무 팔고싶다.
    나무의 길이를 자연수로 같게 통일
    단 한번만 팔 수 있다.

    한번 자를 때 C원 소모
    나무 한 단위에 W원 이득
    K개 나무
    나무 한 단위 L

    현재 가지고있는 나무 길이는 주어짐
    
    벌 수 있는 가장 큰 돈을 구하라.

    [접근]
    길이를 1로 통일해야하나? 아니면 최소 길이로 통일시키면 되나?

    자르지 않는게 이득일수도 있다.

    [풀이]
    1. 
*/

void solve(vector<int> wl, int c, int w) {
    int cost = 0;
    int k = 0;
    long long max_gain = 0; // int로는 틀림, 최대 이득이 졸라 큰 값까지 가능
    long long gain = 0;
    int p;

    int max_unit = 0; // 현재 나무 중 최소가 아닌 가능한 최대 길이까지 단위로 설정가능해야한다.
    for(int i = 0; i < wl.size(); ++i) {
        max_unit = max(max_unit, wl[i]);
    }

    for(int unit = 1; unit <= max_unit; ++unit) {
        gain = 0;

        for(int i = 0; i < wl.size(); ++i) {
            if(wl[i] >= unit) {
                p = wl[i]/unit;
                
                if(wl[i]%unit==0) {
                    cost=(p-1) * c;
                }
                else {
                    cost=p * c;
                }
                
                if(p * unit * w - cost > 0) {
                    gain += (wl[i]/unit) * unit * w - cost;
                }
            }
        }

        max_gain = max(max_gain, gain);

        // cout << "Unit: " << unit << endl;
        // cout << "Wood count: " << k << endl;
        // cout << "cut count: " << cut_cnt << endl;
        // cout << "Current gain: " << gain << endl;
        // cout << "================================" << endl;
    }

    cout << max_gain << endl;
}

int main() {
    int N, C, W;

    cin >> N >> C >> W;

    vector<int> wood_len(N, 0);

    for(int i = 0; i < N; ++i) {
        cin >> wood_len[i];
    }

    sort(wood_len.begin(), wood_len.end());

    solve(wood_len, C, W);

    return 0;
}