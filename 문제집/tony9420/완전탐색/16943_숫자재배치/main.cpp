#include <iostream>
#include <vector>

using namespace std;

int A, B;
int max_num = -1;

void dfs(string strA, string perm, vector<int> used, int level) {
    if(strA.length()==level) {
        if(perm[0]=='0') return; // 0으로 시작하는 부분 처리 중요.
        int num = stoi(perm);
        // cout << "num: " << num << endl;
        if(num < B && max_num < num) max_num = num; 
        return;
    }

    for(int i = 0; i < strA.size(); ++i) {
        if(!used[i]) {
            used[i]=1;
            dfs(strA, perm+strA[i], used, level+1);
            used[i]=0;
        }
    }
}

void solve() {
    string strA = to_string(A);
    // cout << strA << endl;

    dfs(strA, "", vector<int> (strA.length(), 0), 0);
    
}

int main() {
    cin >> A >> B;

    solve();

    cout << max_num << endl;

    return 0;
}