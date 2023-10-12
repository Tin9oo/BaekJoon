#include <iostream>
#include <vector>
#include <algorithm>

#define debug_pg false

using namespace std;

bool cmp(int i, int j) {
    return j < i;
}

void dfs(vector<int>& S, vector<int>& sv, int idx, int sum) {
    if(debug_pg) cout << "dfs()" << endl;

    if(idx==S.size()) {
        sv.push_back(sum);

        return;
    }

    dfs(S, sv, idx+1, sum + S[idx]);
    dfs(S, sv, idx+1, sum);
}

void solve(vector<int>& S, vector<int>& sv) {
    if(debug_pg) cout << "solve()" << endl;
    int check = 1;

    dfs(S, sv, 0, 0);

    // 부분 합 벡터에서 중복된 값을 제거하고 내림차순 정렬
    sort(sv.begin(), sv.end());
    sv.erase(unique(sv.begin(), sv.end()), sv.end());
    sort(sv.begin(), sv.end(), cmp);
    sv.pop_back(); // 아무것도 더하지 않아 합이 0인 경우 제외

    if(debug_pg) cout << "sort complete!!!" << endl;

    if(debug_pg) {
        for(int i = 0; i < sv.size(); ++i) {
            cout << sv[i] << " ";
        }
        cout << endl;
    }

    while(!sv.empty()) {
        if(sv.back()==check) {
            sv.pop_back();
            ++check;
        }
        else {
            cout << check << endl;
            return;
        }
    }
    cout << check << endl; // 부분 합 벡터 내에 수가 없으면 그 다음 수를 반환
}

int main() {
    int N;
    cin >> N;

    vector<int> S(N, 0);
    vector<int> sv;
    for(int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    solve(S, sv);

    return 0;
}