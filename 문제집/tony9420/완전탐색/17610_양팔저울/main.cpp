#include <iostream>
#include <vector>

using namespace std;

/*
    [문제]
    ㅁ에 물의 무게 X가 할당된다.
    현재 보유한 추와 ㅁ의 조합으로 양팔저울이 평행해지지 않는 경우의 수를 구하라.

    [풀이]
    추 무게의 합인 S를 구하고 S까지 반복하는 루프를 만든다.
    used 벡터로 ㅁ과 같은 저울에 담길 추를 구분한다.
*/

bool flag = true;
int cnt = 0;

void dfs(int k, vector<int>& G, int X, vector<bool> used, int idx) {
    if(k == idx) {
        int left = X;
        int right = 0;
        for(int i = 0; i < k; ++i) {
            if(used[i]) left += G[i];
            else right += G[i];
        }
        if(left==right) flag = false;

        cout << left << "--" << right << endl;

        return;
    }

    used[idx]=true;
    dfs(k, G, X, used, idx + 1);

    used[idx]=false;
    dfs(k, G, X, used, idx + 1);
}

void solve(int k, vector<int>& G, int S) {
    vector<bool> used(k, false);

    for(int X = 1; X < S; ++X) {
        cout << "X: " << X << endl;
        
        dfs(k, G, X, used, 0);
        if(flag) ++cnt;
        
        cout << "====================" << endl;
    }
}


int main() {
    int k;
    cin >> k;

    vector<int> G(k, 0);
    int S = 0;
    for(int i = 0; i < k; ++i) {
        cin >> G[i];
        S += G[i];
    }

    solve(k, G, S);

    cout << cnt << endl;

    return 0;
}